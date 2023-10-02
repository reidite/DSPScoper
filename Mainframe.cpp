#include "Mainframe.h"

DigitalFilter::MainFrame::MainFrame()
	: MainFrameUI(nullptr, wxID_ANY, MAINFRAME_NAME, wxDefaultPosition, wxSize(MAINFRAME_WIDTH, MAINFRAME_HEIGHT)) {
	SettingThePlots();
	SettingSignalProperties();

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
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_radioBtn_FIROnRadioButton(wxCommandEvent& event) {
	designMethod = 1;
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_radioBtn_FirstorderOnRadioButton(wxCommandEvent& event) {
	filterOrder = 0;
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_radioBtn_SecondorderOnRadioButton(wxCommandEvent& event) {
	filterOrder = 1;
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_radioBtn_LowpassOnRadioButton(wxCommandEvent& event) {
	filterType = 0;
	LoadingFilter();
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_radioBtn_HighpassOnRadioButton(wxCommandEvent& event) {
	filterType = 1;
	LoadingFilter();
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_radioBtn_BandpassOnRadioButton(wxCommandEvent& event) {
	filterType = 2;
	LoadingFilter();
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_radioBtn_BandstopOnRadioButton(wxCommandEvent& event) {
	filterType = 3;
	LoadingFilter();
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_textCtrl_SamplefreqOnKeyUp(wxKeyEvent& event) {
	int keyCode = event.GetKeyCode();
	if (wxIsdigit(keyCode) || (keyCode >= WXK_NUMPAD0 && keyCode <= WXK_NUMPAD9) ||
		keyCode == WXK_BACK || keyCode == WXK_DELETE) {
		if (m_textCtrl_Samplefreq->GetValue().size() == 0) {
			_sampleFreq = 0;
			m_textCtrl_Samplefreq->SetValue(std::to_string(_sampleFreq));
		}
		_sampleFreq = wxAtoi(m_textCtrl_Samplefreq->GetValue());
		originalATSignalData->SetFreq(_sampleFreq);
		LoadingFilter();
	}
	else {
		m_textCtrl_Samplefreq->SetValue(std::to_string(_sampleFreq));
	}
}

void DigitalFilter::MainFrame::m_textCtrl_PassfreqOnKeyUp(wxKeyEvent& event) {
	int keyCode = event.GetKeyCode();
	if (wxIsdigit(keyCode) || (keyCode >= WXK_NUMPAD0 && keyCode <= WXK_NUMPAD9) ||
		keyCode == WXK_BACK || keyCode == WXK_DELETE) {
		if (m_textCtrl_Passfreq->GetValue().size() == 0) {
			_passFreq = 0;
			m_textCtrl_Passfreq->SetValue(std::to_string(_passFreq));
		}
		_passFreq = wxAtoi(m_textCtrl_Passfreq->GetValue());
		LoadingFilter();
	}
	else {
		m_textCtrl_Passfreq->SetValue(std::to_string(_passFreq));
	}
}

void DigitalFilter::MainFrame::m_textCtrl_StopfreqOnKeyUp(wxKeyEvent& event) {
	int keyCode = event.GetKeyCode();
	if (wxIsdigit(keyCode) || (keyCode >= WXK_NUMPAD0 && keyCode <= WXK_NUMPAD9) ||
		keyCode == WXK_BACK || keyCode == WXK_DELETE) {
		if (m_textCtrl_Stopfreq->GetValue().size() == 0) {
			_stopFreq = 0;
			m_textCtrl_Stopfreq->SetValue(std::to_string(_stopFreq));
		}
		_stopFreq = wxAtoi(m_textCtrl_Stopfreq->GetValue());
		LoadingFilter();
	}
	else {
		m_textCtrl_Stopfreq->SetValue(std::to_string(_stopFreq));
	}
}

void DigitalFilter::MainFrame::m_toggle_StartOnToggleButton(wxCommandEvent& event) {
	LoadingFilter();
	if (!isDrawingFiltedResult) {
		isDrawingFiltedResult = true;
		m_toggle_Start->SetLabel("Stop");
	}
	else {
		isDrawingFiltedResult = false;
		m_toggle_Start->SetLabel("Start");
	}
	isUpdatingSignal = true;
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

void DigitalFilter::MainFrame::SettingSignalProperties() {
	wxPen drawingBluePen(*wxBLUE, 2, wxPENSTYLE_SOLID);
	wxPen drawingRedPen(*wxRED, 2, wxPENSTYLE_SOLID);

	originalATSignalData = new Calc::Signal(FREQ, AMPL, PSI, NUMBER_OF_PTS);
	originalMFSignalData = new DigitalFilter::Calc::Signal(originalATSignalData);
	filteredATSignalData = new DigitalFilter::Calc::Signal(originalATSignalData);
	filteredMFSignalData = new DigitalFilter::Calc::Signal(filteredATSignalData);

	originalATSignalData->SetContinuity(true);
	originalMFSignalData->SetContinuity(true);
	filteredATSignalData->SetContinuity(true);
	filteredMFSignalData->SetContinuity(true);

	originalATSignalData->SetPen(drawingBluePen);
	originalMFSignalData->SetPen(drawingBluePen);
	filteredATSignalData->SetPen(drawingRedPen);
	filteredMFSignalData->SetPen(drawingRedPen);

	m_Fig1->AddLayer(originalATSignalData);
	m_Fig2->AddLayer(originalMFSignalData);
	m_Fig1->AddLayer(filteredATSignalData);
	m_Fig2->AddLayer(filteredMFSignalData);
}

void DigitalFilter::MainFrame::LoadingFilter() {
	if (filterType != filter->getFilterID()) {
		filter->setFilterID(filterType);
		if (filterType != 3)
			filter->SetAB(_sampleFreq, _passFreq);
		else filter->SetAB(_sampleFreq, _stopFreq);
	}
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::LoadingSignal() {
	while (isLoadingSignal) {
		while (!isUpdatingSignal) {};
		
		originalATSignalData->Clear();
		originalMFSignalData->Clear();
		filteredATSignalData->Clear();
		filteredMFSignalData->Clear();

		originalATSignalData->SetATSignalData();
		originalMFSignalData->SetFreq(_sampleFreq);
		originalMFSignalData->SetMFSignalData(originalATSignalData);
		if (isDrawingFiltedResult)
			LoadingFilteredSignal();
		m_Fig1->Fit(0, 1, -AMPL * (1 + PSI), AMPL * (1 + PSI));
		m_Fig2->Fit(0, _sampleFreq, 0, 1);
		isUpdatingSignal = false;
	}
}

void DigitalFilter::MainFrame::LoadingFilteredSignal() {
	filteredATSignalData->SetX(originalATSignalData->GetX());
	filteredATSignalData->SetY(filter->filting(originalATSignalData->GetY()));
	filteredATSignalData->SetFreq(_sampleFreq);
	filteredATSignalData->SetFiltedData();
	filteredMFSignalData->SetFreq(_sampleFreq);
	filteredMFSignalData->SetMFSignalData(filteredATSignalData);
}

void DigitalFilter::MainFrame::TerminatePlotThread() {
	isLoadingSignal = false;
}

void DigitalFilter::MainFrame::UpdatingFreq() {
	isLoadingSignal = false;
}

//m_toggle_Start->SetFont(wxFont(14, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD, false, wxT("Calibri")));