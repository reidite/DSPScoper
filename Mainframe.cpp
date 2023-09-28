#include "Mainframe.h"

DigitalFilter::MainFrame::MainFrame()
	: MainFrameUI(nullptr, wxID_ANY, MAINFRAME_NAME, wxDefaultPosition, wxSize(MAINFRAME_WIDTH, MAINFRAME_HEIGHT)) {
	SettingThePlots();
	filter = new DigitalFilter::Calc::Filter(filterType);
	filter->SetAB(_sampleFreq, _passFreq);

	m_textCtrl_Samplefreq->SetValue(std::to_string(_sampleFreq));
	m_textCtrl_Passfreq->SetValue(std::to_string(_passFreq));
	m_textCtrl_Stopfreq->SetValue(std::to_string(_stopFreq));
}

DigitalFilter::MainFrame::~MainFrame() {
}


void DigitalFilter::MainFrame::m_radioBtn_IIROnRadioButton(wxCommandEvent& event) {
	designMethod = 0;
}

void DigitalFilter::MainFrame::m_radioBtn_FIROnRadioButton(wxCommandEvent& event) {
	designMethod = 1;
}

void DigitalFilter::MainFrame::m_radioBtn_FirstorderOnRadioButton(wxCommandEvent& event) {
	filterOrder = 0;
}

void DigitalFilter::MainFrame::m_radioBtn_SecondorderOnRadioButton(wxCommandEvent& event) {
	filterOrder = 1;
}

void DigitalFilter::MainFrame::m_radioBtn_LowpassOnRadioButton(wxCommandEvent& event) {
	filterType = 0;
}

void DigitalFilter::MainFrame::m_radioBtn_HighpassOnRadioButton(wxCommandEvent& event) {
	filterType = 1;
}

void DigitalFilter::MainFrame::m_radioBtn_BandpassOnRadioButton(wxCommandEvent& event) {
	filterType = 2;
}

void DigitalFilter::MainFrame::m_radioBtn_BandstopOnRadioButton(wxCommandEvent& event) {
	filterType = 3;
}

void DigitalFilter::MainFrame::m_textCtrl_SamplefreqOnKeyUp(wxKeyEvent& event) {
	int keyCode = event.GetKeyCode();
	if (wxIsdigit(keyCode) || (keyCode >= WXK_NUMPAD0 && keyCode <= WXK_NUMPAD9) ||
		keyCode == WXK_BACK || keyCode == WXK_DELETE) {
		_sampleFreq = wxAtoi(m_textCtrl_Samplefreq->GetValue());
	}
	else {
		m_textCtrl_Samplefreq->SetValue(std::to_string(_sampleFreq));
	}
}

void DigitalFilter::MainFrame::m_textCtrl_PassfreqOnKeyUp(wxKeyEvent& event) {
	int keyCode = event.GetKeyCode();
	if (wxIsdigit(keyCode) || (keyCode >= WXK_NUMPAD0 && keyCode <= WXK_NUMPAD9) ||
		keyCode == WXK_BACK || keyCode == WXK_DELETE) {
		_passFreq = wxAtoi(m_textCtrl_Passfreq->GetValue());
	}
	else {
		m_textCtrl_Passfreq->SetValue(std::to_string(_passFreq));
	}
}

void DigitalFilter::MainFrame::m_textCtrl_StopfreqOnKeyUp(wxKeyEvent& event) {
	int keyCode = event.GetKeyCode();
	if (wxIsdigit(keyCode) || (keyCode >= WXK_NUMPAD0 && keyCode <= WXK_NUMPAD9) ||
		keyCode == WXK_BACK || keyCode == WXK_DELETE) {
		_stopFreq = wxAtoi(m_textCtrl_Stopfreq->GetValue());
	}
	else {
		m_textCtrl_Stopfreq->SetValue(std::to_string(_stopFreq));
	}
}

void DigitalFilter::MainFrame::m_button_StartOnButtonClick(wxCommandEvent& event) {
	if (filterType != filter->getFilterID()) {
		filter->setFilterID(filterType);
		if (filterType != 3)
			filter->SetAB(_sampleFreq, _passFreq);
		else filter->SetAB(_sampleFreq, _stopFreq);
	}
	LoadingFilteredSignal();
}

void DigitalFilter::MainFrame::Quit(wxCommandEvent& WXUNUSED(event)) {
	stopFigureDrawing = true;
	Close(true);
}

void DigitalFilter::MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
	wxAboutDialogInfo info;
	info.SetName(_(MAINFRAME_NAME));
	info.SetDescription(_("This is a program visualize the result of some digital filters"));
	info.SetCopyright("(C) 2022 Vicent Nguyen <nglequocviet@gmail.com>");

	wxAboutBox(info, this);
}

void DigitalFilter::MainFrame::SettingThePlots() {
	mpScaleX* timeAxis = new mpScaleX(wxT("Time"), mpALIGN_BORDER_BOTTOM, true, mpX_NORMAL);
	mpScaleY* amplitudeAxis = new mpScaleY(wxT("Amplitude"), mpALIGN_BORDER_LEFT, true);
	mpScaleX* freqAxis = new mpScaleX(wxT("Frequency"), mpALIGN_BORDER_BOTTOM, true, mpX_NORMAL);
	mpScaleY* modulusAxis = new mpScaleY(wxT("Modulus"), mpALIGN_BORDER_LEFT, true);
	timeAxis->SetContinuity(true);
	freqAxis->SetContinuity(true);
	amplitudeAxis->SetContinuity(true);

	timeAxis->SetDrawOutsideMargins(true);
	freqAxis->SetDrawOutsideMargins(true);
	amplitudeAxis->SetDrawOutsideMargins(true);

	m_Fig1 = new mpWindow(this, -1, wxPoint(0, 0), wxSize(100, 100), wxSUNKEN_BORDER);
	m_Fig1->EnableMousePanZoom(false);
	m_Fig1->AddLayer(timeAxis);
	m_Fig1->AddLayer(amplitudeAxis);

	m_Fig2 = new mpWindow(this, -1, wxPoint(0, 0), wxSize(100, 100), wxSUNKEN_BORDER);
	m_Fig2->EnableMousePanZoom(false);
	m_Fig2->AddLayer(freqAxis);
	m_Fig2->AddLayer(modulusAxis);

	gSizer_Outputs->Add(m_Fig1, 0, wxEXPAND, 5);
	gSizer_Outputs->Add(m_Fig2, 1, wxEXPAND, 5);
}

void DigitalFilter::MainFrame::LoadingOriginalSignal() {
	wxPen drawingBluePen(*wxBLUE, 2, wxPENSTYLE_SOLID);

	originalATSignalData = new Calc::Signal(AMPL, FREQ, PSI);
	originalATSignalData->SetContinuity(true);
	originalATSignalData->SetPen(drawingBluePen);
	originalATSignalData->SetATSignalData(100);
	m_Fig1->AddLayer(originalATSignalData);
	m_Fig1->Fit(0.0, 1.0, -AMPL, AMPL);


	originalMFSignalData = new DigitalFilter::Calc::Signal(originalATSignalData);
	originalMFSignalData->SetContinuity(true);
	originalMFSignalData->SetPen(drawingBluePen);
	originalMFSignalData->SetMFSignalData(originalATSignalData);
	m_Fig2->AddLayer(originalMFSignalData);
	m_Fig2->Fit();
}

void DigitalFilter::MainFrame::LoadingFilteredSignal() {
	wxPen drawingRedPen(*wxRED, 2, wxPENSTYLE_SOLID);

	filteredATSignalData = new Calc::Signal(AMPL, FREQ, PSI);
	filteredATSignalData->SetContinuity(true);
	filteredATSignalData->SetPen(drawingRedPen);
	filteredATSignalData->SetX(originalATSignalData->GetX());
	filteredATSignalData->SetY(filter->filting(originalATSignalData->GetY()));
	filteredATSignalData->SetFiltedData();
	m_Fig1->AddLayer(filteredATSignalData);
	m_Fig1->Fit(0.0, 1.0, -AMPL, AMPL);

	filteredMFSignalData = new DigitalFilter::Calc::Signal(filteredATSignalData);
	filteredMFSignalData->SetContinuity(true);
	filteredMFSignalData->SetPen(drawingRedPen);
	filteredMFSignalData->SetMFSignalData(filteredATSignalData);
	m_Fig2->AddLayer(filteredMFSignalData);
	m_Fig2->Fit();
}