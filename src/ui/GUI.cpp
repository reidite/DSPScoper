///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrameUI::MainFrameUI(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(-1, -1), wxDefaultSize);
	this->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	wxGridBagSizer* gSizer_OuterLayout;
	gSizer_OuterLayout = new wxGridBagSizer(0, 0);
	gSizer_OuterLayout->SetFlexibleDirection(wxBOTH);
	gSizer_OuterLayout->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_ALL);

	wxGridBagSizer* gbSizer_LeftController;
	gbSizer_LeftController = new wxGridBagSizer(0, 0);
	gbSizer_LeftController->SetFlexibleDirection(wxBOTH);
	gbSizer_LeftController->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	gbSizer_LeftController->SetMinSize(wxSize(240, -1));
	m_scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(240, 500), wxVSCROLL);
	m_scrolledWindow->SetScrollRate(0, 5);
	m_scrolledWindow->SetMinSize(wxSize(240, 300));

	wxGridBagSizer* gbSizer_AdjusterLayout;
	gbSizer_AdjusterLayout = new wxGridBagSizer(0, 0);
	gbSizer_AdjusterLayout->SetFlexibleDirection(wxVERTICAL);
	gbSizer_AdjusterLayout->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	wxStaticBoxSizer* sbSizer_FilterControlPanel;
	sbSizer_FilterControlPanel = new wxStaticBoxSizer(new wxStaticBox(m_scrolledWindow, wxID_ANY, wxT("Filter Control")), wxVERTICAL);

	wxGridSizer* gSizer_FilterControl;
	gSizer_FilterControl = new wxGridSizer(5, 2, 0, 0);

	m_staticText_FilterOrder = new wxStaticText(sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxT("Filter Order"), wxPoint(0, 0), wxDefaultSize, 0);
	m_staticText_FilterOrder->Wrap(-1);
	gSizer_FilterControl->Add(m_staticText_FilterOrder, 0, wxALL, 5);

	wxString m_choice_FilterOrderChoices[] = { wxT("First Order"), wxT("Second Order") };
	int m_choice_FilterOrderNChoices = sizeof(m_choice_FilterOrderChoices) / sizeof(wxString);
	m_choice_FilterOrder = new wxChoice(sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxPoint(0, 1), wxDefaultSize, m_choice_FilterOrderNChoices, m_choice_FilterOrderChoices, wxCB_SORT);
	m_choice_FilterOrder->SetSelection(0);
	m_choice_FilterOrder->SetMinSize(wxSize(100, -1));

	gSizer_FilterControl->Add(m_choice_FilterOrder, 0, 0, 5);

	m_staticText_FilterType = new wxStaticText(sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxT("Filter Type"), wxPoint(1, 0), wxDefaultSize, 0);
	m_staticText_FilterType->Wrap(-1);
	gSizer_FilterControl->Add(m_staticText_FilterType, 0, wxALL, 5);

	wxString m_choice_FilterTypeChoices[] = { wxT("IIR"), wxT("FIR") };
	int m_choice_FilterTypeNChoices = sizeof(m_choice_FilterTypeChoices) / sizeof(wxString);
	m_choice_FilterType = new wxChoice(sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxPoint(1, 1), wxDefaultSize, m_choice_FilterTypeNChoices, m_choice_FilterTypeChoices, 0);
	m_choice_FilterType->SetSelection(0);
	m_choice_FilterType->SetMinSize(wxSize(100, -1));

	gSizer_FilterControl->Add(m_choice_FilterType, 0, 0, 5);

	m_staticText_FilterClass = new wxStaticText(sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxT("Filter Class"), wxPoint(1, 0), wxDefaultSize, 0);
	m_staticText_FilterClass->Wrap(-1);
	gSizer_FilterControl->Add(m_staticText_FilterClass, 0, wxALL, 5);

	wxString m_choice_FilterClassChoices[] = { wxT("Butterworth"), wxT("Chebyshev"), wxT("Elliptic"), wxT("Bessel"), wxT("Gaussian"), wxT("Legendre"), wxT("Linkwitz-Riley") };
	int m_choice_FilterClassNChoices = sizeof(m_choice_FilterClassChoices) / sizeof(wxString);
	m_choice_FilterClass = new wxChoice(sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxPoint(1, 1), wxDefaultSize, m_choice_FilterClassNChoices, m_choice_FilterClassChoices, 0);
	m_choice_FilterClass->SetSelection(0);
	m_choice_FilterClass->SetMinSize(wxSize(100, -1));

	gSizer_FilterControl->Add(m_choice_FilterClass, 0, 0, 5);

	m_staticText_FilterResponse = new wxStaticText(sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxT("Filter Response"), wxPoint(2, 0), wxDefaultSize, 0);
	m_staticText_FilterResponse->Wrap(-1);
	gSizer_FilterControl->Add(m_staticText_FilterResponse, 0, wxALL, 5);

	wxString m_choice_FilterResponseChoices[] = { wxT("Low-pass"), wxT("High-pass"), wxT("Band-pass"), wxT("Band-stop") };
	int m_choice_FilterResponseNChoices = sizeof(m_choice_FilterResponseChoices) / sizeof(wxString);
	m_choice_FilterResponse = new wxChoice(sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxPoint(2, 1), wxDefaultSize, m_choice_FilterResponseNChoices, m_choice_FilterResponseChoices, 0);
	m_choice_FilterResponse->SetSelection(0);
	m_choice_FilterResponse->SetMinSize(wxSize(100, -1));

	gSizer_FilterControl->Add(m_choice_FilterResponse, 0, 0, 5);

	m_staticText_AppliedFreq = new wxStaticText(sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxT("Applied Frequency"), wxPoint(3, 0), wxDefaultSize, 0);
	m_staticText_AppliedFreq->Wrap(-1);
	gSizer_FilterControl->Add(m_staticText_AppliedFreq, 0, wxALL, 5);

	m_textCtrl_AppliedFreq = new wxTextCtrl(sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxEmptyString, wxPoint(3, 1), wxDefaultSize, wxTE_CENTRE);
	m_textCtrl_AppliedFreq->SetMaxLength(6);
	m_textCtrl_AppliedFreq->SetMinSize(wxSize(100, -1));

	gSizer_FilterControl->Add(m_textCtrl_AppliedFreq, 0, 0, 5);


	sbSizer_FilterControlPanel->Add(gSizer_FilterControl, 1, wxEXPAND, 5);


	gbSizer_AdjusterLayout->Add(sbSizer_FilterControlPanel, wxGBPosition(0, 0), wxGBSpan(6, 2), wxALIGN_CENTER | wxALL, 5);

	wxStaticBoxSizer* sbSizer_SignalControlPanel;
	sbSizer_SignalControlPanel = new wxStaticBoxSizer(new wxStaticBox(m_scrolledWindow, wxID_ANY, wxT("Signal Control")), wxVERTICAL);

	wxGridBagSizer* gbSizer_SignalControl;
	gbSizer_SignalControl = new wxGridBagSizer(0, 0);
	gbSizer_SignalControl->SetFlexibleDirection(wxBOTH);
	gbSizer_SignalControl->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	m_dataViewListCtrl_SignalInfo = new wxDataViewListCtrl(sbSizer_SignalControlPanel->GetStaticBox(), wxID_ANY, wxPoint(0, 0), wxDefaultSize, wxDV_ROW_LINES | wxDV_VERT_RULES);
	m_dataViewListCtrl_SignalInfo->SetMinSize(wxSize(-1, 240));

	gbSizer_SignalControl->Add(m_dataViewListCtrl_SignalInfo, wxGBPosition(0, 0), wxGBSpan(5, 2), wxALL | wxEXPAND, 5);

	wxGridSizer* gSizer111;
	gSizer111 = new wxGridSizer(1, 2, 0, 0);

	m_staticText_SamplingRate = new wxStaticText(sbSizer_SignalControlPanel->GetStaticBox(), wxID_ANY, wxT("Sampling Rate"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_SamplingRate->Wrap(-1);
	gSizer111->Add(m_staticText_SamplingRate, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT | wxALL, 5);

	m_textCtrl_SamplingRate = new wxTextCtrl(sbSizer_SignalControlPanel->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE);
	m_textCtrl_SamplingRate->SetMaxLength(6);
	m_textCtrl_SamplingRate->SetMinSize(wxSize(100, -1));

	gSizer111->Add(m_textCtrl_SamplingRate, 3, wxALL | wxEXPAND, 5);


	gbSizer_SignalControl->Add(gSizer111, wxGBPosition(5, 0), wxGBSpan(1, 2), 0, 5);


	sbSizer_SignalControlPanel->Add(gbSizer_SignalControl, 1, 0, 5);


	gbSizer_AdjusterLayout->Add(sbSizer_SignalControlPanel, wxGBPosition(6, 0), wxGBSpan(6, 2), wxALIGN_CENTER | wxALL, 5);


	m_scrolledWindow->SetSizer(gbSizer_AdjusterLayout);
	m_scrolledWindow->Layout();
	gbSizer_LeftController->Add(m_scrolledWindow, wxGBPosition(0, 0), wxGBSpan(10, 2), wxALL | wxEXPAND, 5);

	wxGridSizer* gSizer_Start;
	gSizer_Start = new wxGridSizer(1, 1, 0, 0);

	gSizer_Start->SetMinSize(wxSize(100, 30));
	m_toggle_Start = new wxToggleButton(this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0);
	m_toggle_Start->SetValue(true);
	gSizer_Start->Add(m_toggle_Start, 0, wxALIGN_CENTER | wxALL, 5);


	gbSizer_LeftController->Add(gSizer_Start, wxGBPosition(10, 0), wxGBSpan(1, 2), wxALIGN_CENTER, 5);


	gbSizer_LeftController->AddGrowableRow(0);
	gbSizer_LeftController->AddGrowableRow(1);
	gbSizer_LeftController->AddGrowableRow(2);
	gbSizer_LeftController->AddGrowableRow(3);
	gbSizer_LeftController->AddGrowableRow(4);
	gbSizer_LeftController->AddGrowableRow(5);
	gbSizer_LeftController->AddGrowableRow(6);
	gbSizer_LeftController->AddGrowableRow(7);
	gbSizer_LeftController->AddGrowableRow(8);
	gbSizer_LeftController->AddGrowableRow(9);

	gSizer_OuterLayout->Add(gbSizer_LeftController, wxGBPosition(0, 0), wxGBSpan(4, 2), wxALL | wxEXPAND, 5);

	gSizer_Outputs = new wxGridSizer(2, 1, 0, 0);


	gSizer_OuterLayout->Add(gSizer_Outputs, wxGBPosition(0, 2), wxGBSpan(4, 6), wxEXPAND, 5);


	gSizer_OuterLayout->AddGrowableCol(2);
	gSizer_OuterLayout->AddGrowableCol(3);
	gSizer_OuterLayout->AddGrowableCol(4);
	gSizer_OuterLayout->AddGrowableCol(5);
	gSizer_OuterLayout->AddGrowableCol(6);
	gSizer_OuterLayout->AddGrowableCol(7);
	gSizer_OuterLayout->AddGrowableRow(0);
	gSizer_OuterLayout->AddGrowableRow(1);
	gSizer_OuterLayout->AddGrowableRow(2);
	gSizer_OuterLayout->AddGrowableRow(3);

	this->SetSizer(gSizer_OuterLayout);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(MainFrameUI::MainFrameUIOnClose));
	m_choice_FilterOrder->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrameUI::m_choice_FilterOrderOnChoice), NULL, this);
	m_choice_FilterType->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrameUI::m_choice_FilterTypeOnChoice), NULL, this);
	m_choice_FilterClass->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrameUI::m_choice_FilterClassOnChoice), NULL, this);
	m_choice_FilterResponse->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrameUI::m_choice_FilterResponseOnChoice), NULL, this);
	m_textCtrl_AppliedFreq->Connect(wxEVT_KEY_UP, wxKeyEventHandler(MainFrameUI::m_textCtrl_AppliedFreqOnKeyUp), NULL, this);
	this->Connect(wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(MainFrameUI::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemActivated));
	this->Connect(wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU, wxDataViewEventHandler(MainFrameUI::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemContextMenu));
	m_textCtrl_SamplingRate->Connect(wxEVT_KEY_UP, wxKeyEventHandler(MainFrameUI::m_textCtrl_SamplingRateOnKeyUp), NULL, this);
	m_toggle_Start->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameUI::m_toggle_StartOnToggleButton), NULL, this);
}

MainFrameUI::~MainFrameUI()
{
	// Disconnect Events
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(MainFrameUI::MainFrameUIOnClose));
	m_choice_FilterOrder->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrameUI::m_choice_FilterOrderOnChoice), NULL, this);
	m_choice_FilterType->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrameUI::m_choice_FilterTypeOnChoice), NULL, this);
	m_choice_FilterClass->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrameUI::m_choice_FilterClassOnChoice), NULL, this);
	m_choice_FilterResponse->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrameUI::m_choice_FilterResponseOnChoice), NULL, this);
	m_textCtrl_AppliedFreq->Disconnect(wxEVT_KEY_UP, wxKeyEventHandler(MainFrameUI::m_textCtrl_AppliedFreqOnKeyUp), NULL, this);
	this->Disconnect(wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(MainFrameUI::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemActivated));
	this->Disconnect(wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU, wxDataViewEventHandler(MainFrameUI::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemContextMenu));
	m_textCtrl_SamplingRate->Disconnect(wxEVT_KEY_UP, wxKeyEventHandler(MainFrameUI::m_textCtrl_SamplingRateOnKeyUp), NULL, this);
	m_toggle_Start->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrameUI::m_toggle_StartOnToggleButton), NULL, this);

}
