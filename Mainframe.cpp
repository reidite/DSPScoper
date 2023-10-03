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

void DigitalFilter::SignalPlot::DrawingDFTData(std::vector<double> x, std::vector<double> y) {
	int N = y.size();
	int K = x.size();

	std::complex<double> intSum;

	std::vector<std::complex<double>> output;
	output.reserve(K);

	for (int k = 0; k < K; k++) {
		intSum = std::complex<double>(0.0, 0.0);
		for (int n = 0; n < N; n++) {
			double realPart = cos((2 * M_PI / N) * k * n);
			double imagPart = sin((2 * M_PI / N) * k * n);

			std::complex<double> w(realPart, -imagPart);

			intSum += y[n] * w;
		}

		output.push_back(intSum);
	}

	std::vector<double> freqs;
	std::vector<double> modus;

	for (int n = 0; n < K; n++)
	{
		freqs.push_back(n);
	}

	for (auto& ii : output)
	{
		ii = ii / static_cast<double>(N);
		modus.push_back(std::abs(ii));
	}

	this->SetData(freqs, modus);
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
	if (filterType != m_choice_ResponeType->GetSelection()) {
		filterType = m_choice_ResponeType->GetSelection();
		LoadingFilter();
		isUpdatingSignal = true;
	}
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

void DigitalFilter::MainFrame::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemActivated(wxDataViewEvent& event) {
	wxDataViewItem item = m_dataViewListCtrl_SignalInfo->GetSelection();
	wxDataViewColumn* col = m_dataViewListCtrl_SignalInfo->GetColumn(event.GetColumn());
	if (item.IsOk() && event.GetColumn() != 0) {
		wxString prevValue = (m_dataViewListCtrl_SignalInfo->GetTextValue(m_dataViewListCtrl_SignalInfo->ItemToRow(item), event.GetColumn()));

		wxDataViewRenderer* renderer = col->GetRenderer();
		wxRect itemRect = m_dataViewListCtrl_SignalInfo->GetItemRect(item);
		renderer->StartEditing(item, itemRect);
		m_dataViewListCtrl_SignalInfo->EditItem(item, col);
		m_dataViewListCtrl_SignalInfo->Bind(wxEVT_DATAVIEW_ITEM_VALUE_CHANGED, [=](wxDataViewEvent& event) {
			double newValue;
			if (m_dataViewListCtrl_SignalInfo->GetTextValue(m_dataViewListCtrl_SignalInfo->ItemToRow(item), event.GetColumn()).ToDouble(&newValue)) {
				switch (event.GetColumn()) {
				case 1:
					signal->infos[m_dataViewListCtrl_SignalInfo->ItemToRow(item)].m_amp = newValue;
					break;
				case 2:
					signal->infos[m_dataViewListCtrl_SignalInfo->ItemToRow(item)].m_freq = newValue;
					break;
				case 3:
					signal->infos[m_dataViewListCtrl_SignalInfo->ItemToRow(item)].m_stddev = newValue;
					break;
				default:
					break;
				}
				signal->GenerateSignalData(_numberOfSample);
				isUpdatingSignal = true;
			}
			else {
				m_dataViewListCtrl_SignalInfo->SetTextValue(prevValue, m_dataViewListCtrl_SignalInfo->ItemToRow(item), event.GetColumn());
			}
		});
	}
}

void DigitalFilter::MainFrame::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemContextMenu(wxDataViewEvent& event) {
	PopupMenu(m_infoPopMenu);
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
	filter->setFilterID(filterType);
	filter->SetAB(_numberOfSample, _appliedFreq);
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
	cols[0] = new wxDataViewColumn("No", new wxDataViewTextRenderer(), 0, 30);
	cols[1] = new wxDataViewColumn("Amp", new wxDataViewTextRenderer(), 1, 52);
	cols[2] = new wxDataViewColumn("Freq", new wxDataViewTextRenderer(), 2, 52);
	cols[3] = new wxDataViewColumn("Stddev", new wxDataViewTextRenderer(), 3, 52);

	for(wxDataViewColumn* col:cols)
		m_dataViewListCtrl_SignalInfo->AppendColumn(col);

	for (Calc::SignalInfo info : signal->infos) {
		wxVector<wxVariant> rowData;
		rowData.push_back(wxString::Format("%d", itemID++));
		rowData.push_back(wxString::Format("%0.2lf", info.m_amp));
		rowData.push_back(wxString::Format("%0.2lf", info.m_freq));
		rowData.push_back(wxString::Format("%0.2lf", info.m_stddev));
		m_dataViewListCtrl_SignalInfo->AppendItem(rowData);
	}

	m_infoPopMenu = new wxMenu();
	m_infoPopMenu->Append(INFOCMD::mpINFO_NEW, _("New"), _("Create a new signal"));
	m_infoPopMenu->Append(INFOCMD::mpINFO_REMOVE, _("Remove"), _("Remove the selected signal"));
}

void DigitalFilter::MainFrame::AddingInfo(wxCommandEvent& event) {
	wxVector<wxVariant> rowData;
	rowData.push_back(wxString::Format("%d", itemID++));
	rowData.push_back(wxString::Format("%0.2lf", 0.0));
	rowData.push_back(wxString::Format("%0.2lf", 0.0));
	rowData.push_back(wxString::Format("%0.2lf", 0.0));
	m_dataViewListCtrl_SignalInfo->AppendItem(rowData);
	signal->infos.push_back({ 0.0, 0.0, 0.0 });
}

void DigitalFilter::MainFrame::RemovingInfo(wxCommandEvent& event) {
	unsigned int n_row = m_dataViewListCtrl_SignalInfo->ItemToRow(m_dataViewListCtrl_SignalInfo->GetSelection());
	m_dataViewListCtrl_SignalInfo->DeleteItem(n_row);
	signal->infos.erase(signal->infos.begin() + n_row);
	itemID--;
	signal->GenerateSignalData(_numberOfSample);
	isUpdatingSignal = true;
}