#include "Mainframe.h"

DigitalFilter::MainFrame::MainFrame()
	: MainFrameUI(nullptr, wxID_ANY, MAINFRAME_NAME, wxDefaultPosition, wxSize(MAINFRAME_WIDTH, MAINFRAME_HEIGHT)) {
	SettingThePlots();
	SettingSignalProperties();

	signal = new DigitalFilter::Calc::Signal();
	filter = new DigitalFilter::Calc::Filter(filterType);

	signal->GenerateSignalData(_numberOfSample);
	filter->SetAB(_numberOfSample, _appliedFreq);
	
	UpdatingSignalInfo();
	m_textCtrl_SampleSize->SetValue(std::to_string(_numberOfSample));
	m_textCtrl_AppliedFreq->SetValue(std::to_string(_appliedFreq));
}

DigitalFilter::MainFrame::~MainFrame() {
}


void DigitalFilter::MainFrame::m_choice_DesignMethodOnChoice(wxCommandEvent& event) {
	designMethod = m_choice_DesignMethod->GetSelection();
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_choice_FilterOrderOnChoice(wxCommandEvent& event) {
	filterOrder = m_choice_FilterOrder->GetSelection();
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_choice_ResponeTypeOnChoice(wxCommandEvent& event) {
	filterType = m_choice_ResponeType->GetSelection();
	LoadingFilter();
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::m_textCtrl_SampleSizeOnKeyUp(wxKeyEvent& event) {
	int keyCode = event.GetKeyCode();
	if (wxIsdigit(keyCode) || (keyCode >= WXK_NUMPAD0 && keyCode <= WXK_NUMPAD9) ||
		keyCode == WXK_BACK || keyCode == WXK_DELETE) {
		if (m_textCtrl_SampleSize->GetValue().size() == 0) {
			_numberOfSample = 0;
			m_textCtrl_SampleSize->SetValue(std::to_string(_numberOfSample));
		}
		_numberOfSample = wxAtoi(m_textCtrl_SampleSize->GetValue());
		signal->GenerateSignalData(_numberOfSample);
		LoadingFilter();
	}
	else {
		m_textCtrl_SampleSize->SetValue(std::to_string(_numberOfSample));
	}
}

void DigitalFilter::MainFrame::m_textCtrl_AppliedFreqOnKeyUp(wxKeyEvent& event) {
	int keyCode = event.GetKeyCode();
	if (wxIsdigit(keyCode) || (keyCode >= WXK_NUMPAD0 && keyCode <= WXK_NUMPAD9) ||
		keyCode == WXK_BACK || keyCode == WXK_DELETE) {
		if (m_textCtrl_AppliedFreq->GetValue().size() == 0) {
			_appliedFreq = 0;
			m_textCtrl_AppliedFreq->SetValue(std::to_string(_appliedFreq));
		}
		_appliedFreq = wxAtoi(m_textCtrl_AppliedFreq->GetValue());
		LoadingFilter();
	}
	else {
		m_textCtrl_AppliedFreq->SetValue(std::to_string(_appliedFreq));
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

	originalATPlot = new DigitalFilter::SignalPlot();
	filteredATPlot = new DigitalFilter::SignalPlot();
	originalMFPlot = new DigitalFilter::SignalPlot();
	filteredMFPlot = new DigitalFilter::SignalPlot();

	originalATPlot->SetContinuity(true);
	filteredATPlot->SetContinuity(true);
	originalMFPlot->SetContinuity(true);
	filteredMFPlot->SetContinuity(true);

	originalATPlot->SetPen(drawingBluePen);
	originalMFPlot->SetPen(drawingBluePen);
	filteredATPlot->SetPen(drawingRedPen);
	filteredMFPlot->SetPen(drawingRedPen);

	m_Fig1->AddLayer(originalATPlot);
	m_Fig2->AddLayer(originalMFPlot);
	m_Fig1->AddLayer(filteredATPlot);
	m_Fig2->AddLayer(filteredMFPlot);
}

void DigitalFilter::MainFrame::LoadingFilter() {
	if (filterType != filter->getFilterID()) {
		filter->setFilterID(filterType);
		if (filterType != 3)
			filter->SetAB(_numberOfSample, _appliedFreq);
		else filter->SetAB(_numberOfSample, _appliedFreq);
	}
	isUpdatingSignal = true;
}

void DigitalFilter::MainFrame::LoadingSignal() {
	while (isLoadingSignal) {
		while (!isUpdatingSignal) {};
		
		originalATPlot->Clear();
		originalMFPlot->Clear();
		filteredATPlot->Clear();
		filteredMFPlot->Clear();

		originalATPlot->DrawingSignalData(signal->x, signal->y);
		originalMFPlot->DrawingDFTData(signal->x, signal->y);
		if (isDrawingFiltedResult)
			LoadingFilteredSignal();
		m_Fig1->Fit(0, 1, -2, 2);
		m_Fig2->Fit(0, 100, 0, 1);
		isUpdatingSignal = false;
	}
}

void DigitalFilter::MainFrame::LoadingFilteredSignal() {
	std::vector<double> filted_y = filter->filting(signal->y);
	filteredATPlot->DrawingSignalData(signal->x, filted_y);
	filteredMFPlot->DrawingDFTData(signal->x, filted_y);
}

void DigitalFilter::MainFrame::TerminatePlotThread() {
	isLoadingSignal = false;
}

void DigitalFilter::MainFrame::UpdatingFreq() {
	isLoadingSignal = false;
}

void DigitalFilter::MainFrame::UpdatingSignalInfo() {
	m_listCtrl_SignalInfo->InsertColumn(0, _("No"), wxLIST_FORMAT_LEFT, 30);
	m_listCtrl_SignalInfo->InsertColumn(1, _("Ampl"), wxLIST_FORMAT_LEFT, 60);
	m_listCtrl_SignalInfo->InsertColumn(2, _("Freq"), wxLIST_FORMAT_LEFT, 60);
	//m_listCtrl_SignalInfo->InsertColumn(3, _("Psi"), wxLIST_FORMAT_LEFT, 60);
	//m_listCtrl_SignalInfo->IsExposed();

	m_item_signal = new wxListItem();
	long index = m_listCtrl_SignalInfo->InsertItem(0, _("0"));
	m_listCtrl_SignalInfo->SetItem(index, 1, _(std::to_string((double)INIT_AMPL)));
	m_listCtrl_SignalInfo->SetItem(index, 2, _(std::to_string((double)INIT_FREQ)));

	index = m_listCtrl_SignalInfo->InsertItem(0, _("1"));
	m_listCtrl_SignalInfo->SetItem(index, 1, _(std::to_string((double)0.6)));
	m_listCtrl_SignalInfo->SetItem(index, 2, _(std::to_string((double)50)));

	index = m_listCtrl_SignalInfo->InsertItem(0, _("2"));
	m_listCtrl_SignalInfo->SetItem(index, 1, _(std::to_string((double)0.8)));
	m_listCtrl_SignalInfo->SetItem(index, 2, _(std::to_string((double)80)));
	/*std::string tmp = std::to_string(INIT_PSI);
	m_listCtrl_SignalInfo->SetItem(index, 3, _(tmp.substr(0, tmp.find("." + 3))));*/
}

//m_toggle_Start->SetFont(wxFont(14, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD, false, wxT("Calibri")));