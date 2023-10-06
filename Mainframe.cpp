#include "Mainframe.h"

DigitalFilter::MainFrame::MainFrame()
	: MainFrameUI(nullptr, wxID_ANY, MAINFRAME_NAME, wxDefaultPosition, wxSize(MAINFRAME_WIDTH, MAINFRAME_HEIGHT)) {
	/**
	* Constructs a new wxMainFrame object with the specified parameters.
	*/

	p_signal = new DigitalFilter::Calc::Signal();
	p_filter = new DigitalFilter::Calc::Filter(un_filterRespone);
	
	p_signal->GenerateSignalData(n_numSampling);
	p_filter->SetAB(n_numSampling, n_appliedFreq);

	LoadingSignalInfos();

	SettingPlotsUI();
	LoadingPlotsUpdater();
}

DigitalFilter::MainFrame::~MainFrame() {
	/**
	* Destroys the wxMainFrame object and frees any allocated resources.
	*/
}

void DigitalFilter::MainFrame::LoadingFilter() {
	/**
	* Modifies the digital signal filter being loaded into the program.
	*/
	p_filter->setResponeID(un_filterRespone);
	p_filter->SetAB(n_numSampling, n_appliedFreq);
	atomic_b_updatingPlotsRaised = true;
}

void DigitalFilter::MainFrame::LoadingSignalInfos() {
	/**
	* Loading and retrieving information about the available signal.
	*/
	m_textCtrl_SamplingRate->SetValue(std::to_string(n_numSampling));
	m_textCtrl_AppliedFreq->SetValue(std::to_string(n_appliedFreq));

	m_colInfos[0] = new wxDataViewColumn("No", new wxDataViewTextRenderer(), 0, 30);
	m_colInfos[1] = new wxDataViewColumn("Amp", new wxDataViewTextRenderer(), 1, 52);
	m_colInfos[2] = new wxDataViewColumn("Freq", new wxDataViewTextRenderer(), 2, 52);
	m_colInfos[3] = new wxDataViewColumn("Stddev", new wxDataViewTextRenderer(), 3, 52);

	for (wxDataViewColumn* col : m_colInfos)
		m_dataViewListCtrl_SignalInfo->AppendColumn(col);

	for (Calc::SignalInfo info : p_signal->infos) {
		wxVector<wxVariant> rowData;
		rowData.push_back(wxString::Format("%d", un_numRowInfos++));
		rowData.push_back(wxString::Format("%0.2lf", info.m_amp));
		rowData.push_back(wxString::Format("%0.2lf", info.m_freq));
		rowData.push_back(wxString::Format("%0.2lf", info.m_stddev));
		m_dataViewListCtrl_SignalInfo->AppendItem(rowData);

		lf_sumAmpSignal += info.m_amp;
		lf_maxAmpSignal = std::max(lf_maxAmpSignal, info.m_amp);
		lf_maxFreqSignal = std::max(lf_maxFreqSignal, info.m_freq);
	}

	mp_infoPopMenu = new wxMenu();
	mp_infoPopMenu->Append(wxID_ADD, _("New"), _("Create a new signal"));
	mp_infoPopMenu->Append(wxID_DELETE, _("Remove"), _("Remove the selected signal"));
	Bind(wxEVT_MENU, &MainFrame::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlOnMenuSelect, this);
}

void DigitalFilter::MainFrame::SettingPlotsUI() {
	/**
	* Configuring and setting up the user interface for displaying signal plots.
	*/
	mp_FigAT = new Plot::ATPlotWindow(this);
	mp_FigMF = new Plot::MFPlotWindow(this);

	mp_FigAT->UpdatingBoundingBox(lf_sumAmpSignal);
	mp_FigMF->UpdatingBoundingBox(lf_maxAmpSignal, lf_maxFreqSignal);

	gSizer_Outputs->Add(mp_FigAT, 0, wxEXPAND, 5);
	gSizer_Outputs->Add(mp_FigMF, 1, wxEXPAND, 5);

	mp_originalATPlot = new DigitalFilter::Plot::SignalPlot(*wxBLUE);
	mp_filteredATPlot = new DigitalFilter::Plot::SignalPlot(*wxRED);
	mp_originalMFPlot = new DigitalFilter::Plot::SignalPlot(*wxBLUE);
	mp_filteredMFPlot = new DigitalFilter::Plot::SignalPlot(*wxRED);

	mp_FigAT->AddLayer(mp_originalATPlot);
	mp_FigMF->AddLayer(mp_originalMFPlot);
	mp_FigAT->AddLayer(mp_filteredATPlot);
	mp_FigMF->AddLayer(mp_filteredMFPlot);
}

void DigitalFilter::MainFrame::LoadingPlotsUpdater() {
	/**
	* Loading a thread to update or refresh the signal plots in response to changes
	* in the processed signal data.
	*/
	pthrd_PlotUpdater = new std::thread([&]() {
		while (atomic_b_drawingPlotsInProgress) {
			mp_originalATPlot->Clear();
			mp_originalMFPlot->Clear();
			mp_filteredATPlot->Clear();
			mp_filteredMFPlot->Clear();

			mp_originalATPlot->DrawingSignalData(p_signal->x, p_signal->y);
			mp_originalMFPlot->DrawingDFTData(p_signal->x, p_signal->y, lf_maxFreqSignal);

			if (atomic_b_drawingFiltedResultRaised) {
				std::vector<double> filted_y;
				if (un_filterOrder == 0 || un_filterRespone > 1) {
					filted_y = p_filter->filting(p_signal->y, un_filterType);
				}
				else {
					filted_y = p_filter->filting(p_filter->filting(p_signal->y, un_filterType), un_filterType);
				}
				mp_filteredATPlot->DrawingSignalData(p_signal->x, filted_y);
				mp_filteredMFPlot->DrawingDFTData(p_signal->x, filted_y, lf_maxFreqSignal);
			}

			mp_FigAT->UpdatingBoundingBox(lf_sumAmpSignal);
			mp_FigMF->UpdatingBoundingBox(lf_maxAmpSignal, lf_maxFreqSignal);
			atomic_b_updatingPlotsRaised = false;
			while (!atomic_b_updatingPlotsRaised);
		}
		});
}

void DigitalFilter::MainFrame::MainFrameUIOnClose(wxCloseEvent& event) {
	atomic_b_drawingPlotsInProgress = false;
	atomic_b_updatingPlotsRaised = true;
	pthrd_PlotUpdater->join();
	exit(0);
}

void DigitalFilter::MainFrame::MainFrameUIOnAbout(wxCommandEvent& WXUNUSED(event)) {
	wxAboutDialogInfo info;
	info.SetName(_(MAINFRAME_NAME));
	info.SetDescription(_("This is a program visualize the result of some digital filters"));
	info.SetCopyright("(C) 2022 Vicent Nguyen <nglequocviet@gmail.com>");

	wxAboutBox(info, this);
}

void DigitalFilter::MainFrame::m_choice_FilterOrderOnChoice(wxCommandEvent& event) {
	un_filterOrder = m_choice_FilterOrder->GetSelection();
	atomic_b_updatingPlotsRaised = true;
}

void DigitalFilter::MainFrame::m_choice_FilterTypeOnChoice(wxCommandEvent& event) {
	un_filterType = m_choice_FilterType->GetSelection();
	atomic_b_updatingPlotsRaised = true;
}

void DigitalFilter::MainFrame::m_choice_FilterClassOnChoice(wxCommandEvent& event) {
	un_filterClass = m_choice_FilterClass->GetSelection();
	atomic_b_updatingPlotsRaised = true;
}

void DigitalFilter::MainFrame::m_choice_FilterResponseOnChoice(wxCommandEvent& event) {
	if (un_filterRespone != m_choice_FilterResponse->GetSelection()) {
		un_filterRespone = m_choice_FilterResponse->GetSelection();
		LoadingFilter();
		atomic_b_updatingPlotsRaised = true;
	}
}

void DigitalFilter::MainFrame::m_textCtrl_AppliedFreqOnKeyUp(wxKeyEvent& event) {
	int keyCode = event.GetKeyCode();
	if (wxIsdigit(keyCode) || (keyCode >= WXK_NUMPAD0 && keyCode <= WXK_NUMPAD9) ||
		keyCode == WXK_BACK || keyCode == WXK_DELETE) {
		if (m_textCtrl_AppliedFreq->GetValue().size() == 0) {
			n_appliedFreq = 0;
			m_textCtrl_AppliedFreq->SetValue(std::to_string(n_appliedFreq));
		}
		n_appliedFreq = wxAtoi(m_textCtrl_AppliedFreq->GetValue());
		LoadingFilter();
	}
	else {
		m_textCtrl_AppliedFreq->SetValue(std::to_string(n_appliedFreq));
	}
}

void DigitalFilter::MainFrame::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemActivated(wxDataViewEvent& event) {
	if(event.GetColumn() < 0) return;
	wxDataViewItem item = m_dataViewListCtrl_SignalInfo->GetSelection();
	wxDataViewColumn* col = m_dataViewListCtrl_SignalInfo->GetColumn(event.GetColumn());
	if (item.IsOk() && event.GetColumn() != 0) {
		wxString prev = (m_dataViewListCtrl_SignalInfo->GetTextValue(m_dataViewListCtrl_SignalInfo->ItemToRow(item), event.GetColumn()));

		wxDataViewRenderer* renderer = col->GetRenderer();
		wxRect itemRect = m_dataViewListCtrl_SignalInfo->GetItemRect(item);
		renderer->StartEditing(item, itemRect);
		m_dataViewListCtrl_SignalInfo->EditItem(item, col);
		
		m_dataViewListCtrl_SignalInfo->Bind(wxEVT_DATAVIEW_ITEM_VALUE_CHANGED, [=](wxDataViewEvent& event) {
			double newValue;
			if (m_dataViewListCtrl_SignalInfo->GetTextValue(m_dataViewListCtrl_SignalInfo->ItemToRow(item), event.GetColumn()).ToDouble(&newValue)) {
				switch (event.GetColumn()) {
				case 1:
					double prevValue;
					prev.ToDouble(&prevValue);
					lf_sumAmpSignal += (newValue - prevValue);
					lf_maxAmpSignal = INT_MIN;
					for (int i = 0; i < p_signal->infos.size(); i++)
						lf_maxAmpSignal = std::max(lf_maxAmpSignal, p_signal->infos[i].m_amp);
					p_signal->infos[m_dataViewListCtrl_SignalInfo->ItemToRow(item)].m_amp = newValue;
					break;
				case 2:
					p_signal->infos[m_dataViewListCtrl_SignalInfo->ItemToRow(item)].m_freq = newValue;
					lf_maxFreqSignal = INT_MIN;
					for (int i = 0; i < p_signal->infos.size(); i++)
						lf_maxFreqSignal = std::max(lf_maxFreqSignal, p_signal->infos[i].m_freq);
					break;
				case 3:
					p_signal->infos[m_dataViewListCtrl_SignalInfo->ItemToRow(item)].m_stddev = newValue;
					break;
				default:
					break;
				}
				p_signal->GenerateSignalData(n_numSampling);
				atomic_b_updatingPlotsRaised = true;
			}
			else {
				m_dataViewListCtrl_SignalInfo->SetTextValue(prev, m_dataViewListCtrl_SignalInfo->ItemToRow(item), event.GetColumn());
			}
		});
	}
}

void DigitalFilter::MainFrame::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemContextMenu(wxDataViewEvent& event) {
	if (m_dataViewListCtrl_SignalInfo->GetSelection()) {
		mp_infoPopMenu->FindItemByPosition(1)->Enable(true);
		PopupMenu(mp_infoPopMenu);
	}
	else {
		mp_infoPopMenu->FindItemByPosition(1)->Enable(false);
		PopupMenu(mp_infoPopMenu);
	}
}

void DigitalFilter::MainFrame::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlOnMenuSelect(wxCommandEvent& event) {
	if (event.GetId() == wxID_ADD) {
		wxVector<wxVariant> rowData;
		rowData.push_back(wxString::Format("%d", un_numRowInfos++));
		rowData.push_back(wxString::Format("%0.2lf", 0.0));
		rowData.push_back(wxString::Format("%0.2lf", 0.0));
		rowData.push_back(wxString::Format("%0.2lf", 0.0));
		m_dataViewListCtrl_SignalInfo->AppendItem(rowData);
		p_signal->infos.push_back({ 0.0, 0.0, 0.0 });
	}
	else if (event.GetId() == wxID_DELETE) {
		unsigned int n_row = m_dataViewListCtrl_SignalInfo->ItemToRow(m_dataViewListCtrl_SignalInfo->GetSelection());

		lf_sumAmpSignal -= p_signal->infos[n_row].m_amp;
		m_dataViewListCtrl_SignalInfo->DeleteItem(n_row);


		lf_maxAmpSignal = INT_MIN;
		for (int i = 0; i < p_signal->infos.size(); i++)
			lf_maxAmpSignal = std::max(lf_maxAmpSignal, p_signal->infos[i].m_amp);

		p_signal->infos.erase(p_signal->infos.begin() + n_row);
		un_numRowInfos--;

		lf_maxFreqSignal = INT_MIN;
		for (int i = 0; i < p_signal->infos.size(); i++)
			lf_maxFreqSignal = std::max(lf_maxFreqSignal, p_signal->infos[i].m_freq);

		p_signal->GenerateSignalData(n_numSampling);
		atomic_b_updatingPlotsRaised = true;
	}
}

void DigitalFilter::MainFrame::m_textCtrl_SamplingRateOnKeyUp(wxKeyEvent& event) {
	int keyCode = event.GetKeyCode();
	if (wxIsdigit(keyCode) || (keyCode >= WXK_NUMPAD0 && keyCode <= WXK_NUMPAD9) ||
		keyCode == WXK_BACK || keyCode == WXK_DELETE) {
		if (m_textCtrl_SamplingRate->GetValue().size() == 0) {
			n_numSampling = 0;
			m_textCtrl_SamplingRate->SetValue(std::to_string(n_numSampling));
		}
		n_numSampling = wxAtoi(m_textCtrl_SamplingRate->GetValue());
		p_signal->GenerateSignalData(n_numSampling);
		LoadingFilter();
	}
	else {
		m_textCtrl_SamplingRate->SetValue(std::to_string(n_numSampling));
	}
}

void DigitalFilter::MainFrame::m_toggle_StartOnToggleButton(wxCommandEvent& event) {
	LoadingFilter();
	if (!atomic_b_drawingFiltedResultRaised) {
		atomic_b_drawingFiltedResultRaised = true;
		m_toggle_Start->SetLabel("Stop");
	}
	else {
		atomic_b_drawingFiltedResultRaised = false;
		m_toggle_Start->SetLabel("Start");
	}
	atomic_b_updatingPlotsRaised = true;
}
