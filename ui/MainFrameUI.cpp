///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrameUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrameUI::MainFrameUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 720,520 ), wxDefaultSize );
	
	wxGridBagSizer* gSizer_OuterLayout;
	gSizer_OuterLayout = new wxGridBagSizer( 0, 0 );
	gSizer_OuterLayout->SetFlexibleDirection( wxBOTH );
	gSizer_OuterLayout->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );
	
	wxGridBagSizer* gbSizer_LeftController ;
	gbSizer_LeftController  = new wxGridBagSizer( 0, 0 );
	gbSizer_LeftController ->SetFlexibleDirection( wxBOTH );
	gbSizer_LeftController ->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	gbSizer_LeftController ->SetMinSize( wxSize( 210,-1 ) ); 
	m_scrolledWindow = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL );
	m_scrolledWindow->SetScrollRate( 5, 5 );
	m_scrolledWindow->SetMinSize( wxSize( 240,100 ) );
	
	wxGridBagSizer* gbSizer_AdjusterLayout;
	gbSizer_AdjusterLayout = new wxGridBagSizer( 0, 0 );
	gbSizer_AdjusterLayout->SetFlexibleDirection( wxVERTICAL );
	gbSizer_AdjusterLayout->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer_FilterControlPanel;
	sbSizer_FilterControlPanel = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow, wxID_ANY, wxT("Filter Control") ), wxVERTICAL );
	
	wxGridSizer* gSizer_FilterControl;
	gSizer_FilterControl = new wxGridSizer( 4, 2, 0, 0 );
	
	m_staticText_FilterOrder = new wxStaticText( sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxT("Filter Order"), wxPoint( 0,0 ), wxDefaultSize, 0 );
	m_staticText_FilterOrder->Wrap( -1 );
	gSizer_FilterControl->Add( m_staticText_FilterOrder, 0, wxALL, 5 );
	
	wxString m_choice_FilterOrderChoices[] = { wxT("First Order"), wxT("Second Order") };
	int m_choice_FilterOrderNChoices = sizeof( m_choice_FilterOrderChoices ) / sizeof( wxString );
	m_choice_FilterOrder = new wxChoice( sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxPoint( 0,1 ), wxDefaultSize, m_choice_FilterOrderNChoices, m_choice_FilterOrderChoices, wxCB_SORT );
	m_choice_FilterOrder->SetSelection( 0 );
	m_choice_FilterOrder->SetMinSize( wxSize( 100,-1 ) );
	
	gSizer_FilterControl->Add( m_choice_FilterOrder, 0, 0, 5 );
	
	m_staticText_DesignMethod = new wxStaticText( sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxT("Design Method"), wxPoint( 1,0 ), wxDefaultSize, 0 );
	m_staticText_DesignMethod->Wrap( -1 );
	gSizer_FilterControl->Add( m_staticText_DesignMethod, 0, wxALL, 5 );
	
	wxString m_choice_DesignMethodChoices[] = { wxT("IIR"), wxT("FIR") };
	int m_choice_DesignMethodNChoices = sizeof( m_choice_DesignMethodChoices ) / sizeof( wxString );
	m_choice_DesignMethod = new wxChoice( sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxPoint( 1,1 ), wxDefaultSize, m_choice_DesignMethodNChoices, m_choice_DesignMethodChoices, 0 );
	m_choice_DesignMethod->SetSelection( 0 );
	m_choice_DesignMethod->SetMinSize( wxSize( 100,-1 ) );
	
	gSizer_FilterControl->Add( m_choice_DesignMethod, 0, 0, 5 );
	
	m_staticText_ResponseType = new wxStaticText( sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxT("Design Method"), wxPoint( 2,0 ), wxDefaultSize, 0 );
	m_staticText_ResponseType->Wrap( -1 );
	gSizer_FilterControl->Add( m_staticText_ResponseType, 0, wxALL, 5 );
	
	wxString m_choice_ResponeTypeChoices[] = { wxT("Low Pass"), wxT("High Pass"), wxT("Band Pass"), wxT("Band Stop") };
	int m_choice_ResponeTypeNChoices = sizeof( m_choice_ResponeTypeChoices ) / sizeof( wxString );
	m_choice_ResponeType = new wxChoice( sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxPoint( 2,1 ), wxDefaultSize, m_choice_ResponeTypeNChoices, m_choice_ResponeTypeChoices, 0 );
	m_choice_ResponeType->SetSelection( 0 );
	m_choice_ResponeType->SetMinSize( wxSize( 100,-1 ) );
	
	gSizer_FilterControl->Add( m_choice_ResponeType, 0, 0, 5 );
	
	m_staticText_AppliedFreq = new wxStaticText( sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxT("Applied Frequency"), wxPoint( 3,0 ), wxDefaultSize, 0 );
	m_staticText_AppliedFreq->Wrap( -1 );
	gSizer_FilterControl->Add( m_staticText_AppliedFreq, 0, wxALL, 5 );
	
	m_textCtrl_AppliedFreq = new wxTextCtrl( sbSizer_FilterControlPanel->GetStaticBox(), wxID_ANY, wxEmptyString, wxPoint( 3,1 ), wxDefaultSize, wxTE_CENTRE );
	m_textCtrl_AppliedFreq->SetMaxLength( 6 ); 
	m_textCtrl_AppliedFreq->SetMinSize( wxSize( 100,-1 ) );
	
	gSizer_FilterControl->Add( m_textCtrl_AppliedFreq, 0, 0, 5 );
	
	
	sbSizer_FilterControlPanel->Add( gSizer_FilterControl, 1, wxEXPAND, 5 );
	
	
	gbSizer_AdjusterLayout->Add( sbSizer_FilterControlPanel, wxGBPosition( 0, 0 ), wxGBSpan( 5, 2 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer_SignalControlPanel;
	sbSizer_SignalControlPanel = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow, wxID_ANY, wxT("Signal Control") ), wxVERTICAL );
	
	wxGridBagSizer* gbSizer_SignalControl;
	gbSizer_SignalControl = new wxGridBagSizer( 0, 0 );
	gbSizer_SignalControl->SetFlexibleDirection( wxBOTH );
	gbSizer_SignalControl->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_dataViewListCtrl_SignalInfo = new wxDataViewListCtrl( sbSizer_SignalControlPanel->GetStaticBox(), wxID_ANY, wxPoint( 0,0 ), wxDefaultSize, wxDV_ROW_LINES|wxDV_VERT_RULES );
	m_dataViewListCtrl_SignalInfo->SetMinSize( wxSize( -1,250 ) );
	
	gbSizer_SignalControl->Add( m_dataViewListCtrl_SignalInfo, wxGBPosition( 0, 0 ), wxGBSpan( 10, 2 ), wxALL|wxEXPAND, 5 );
	
	wxGridSizer* gSizer111;
	gSizer111 = new wxGridSizer( 3, 2, 0, 0 );
	
	m_staticText_SampleSize = new wxStaticText( sbSizer_SignalControlPanel->GetStaticBox(), wxID_ANY, wxT("Sample Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_SampleSize->Wrap( -1 );
	gSizer111->Add( m_staticText_SampleSize, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	m_textCtrl_SampleSize = new wxTextCtrl( sbSizer_SignalControlPanel->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_textCtrl_SampleSize->SetMaxLength( 6 ); 
	m_textCtrl_SampleSize->SetMinSize( wxSize( 100,-1 ) );
	
	gSizer111->Add( m_textCtrl_SampleSize, 3, wxALL, 5 );
	
	
	gbSizer_SignalControl->Add( gSizer111, wxGBPosition( 10, 0 ), wxGBSpan( 1, 2 ), 0, 5 );
	
	
	sbSizer_SignalControlPanel->Add( gbSizer_SignalControl, 1, wxEXPAND, 5 );
	
	
	gbSizer_AdjusterLayout->Add( sbSizer_SignalControlPanel, wxGBPosition( 5, 0 ), wxGBSpan( 11, 2 ), wxEXPAND, 5 );
	
	
	m_scrolledWindow->SetSizer( gbSizer_AdjusterLayout );
	m_scrolledWindow->Layout();
	gbSizer_AdjusterLayout->Fit( m_scrolledWindow );
	gbSizer_LeftController ->Add( m_scrolledWindow, wxGBPosition( 0, 0 ), wxGBSpan( 15, 2 ), wxEXPAND | wxALL, 5 );
	
	m_toggle_Start = new wxToggleButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_toggle_Start->SetValue( true ); 
	gbSizer_LeftController ->Add( m_toggle_Start, wxGBPosition( 15, 0 ), wxGBSpan( 1, 2 ), wxALIGN_CENTER, 5 );
	
	
	gbSizer_LeftController ->AddGrowableCol( 0 );
	gbSizer_LeftController ->AddGrowableCol( 1 );
	gbSizer_LeftController ->AddGrowableRow( 0 );
	gbSizer_LeftController ->AddGrowableRow( 1 );
	gbSizer_LeftController ->AddGrowableRow( 2 );
	gbSizer_LeftController ->AddGrowableRow( 3 );
	gbSizer_LeftController ->AddGrowableRow( 4 );
	
	gSizer_OuterLayout->Add( gbSizer_LeftController , wxGBPosition( 0, 0 ), wxGBSpan( 6, 2 ), wxEXPAND, 5 );
	
	gSizer_Outputs = new wxGridSizer( 2, 1, 0, 0 );
	
	
	gSizer_OuterLayout->Add( gSizer_Outputs, wxGBPosition( 0, 2 ), wxGBSpan( 6, 5 ), wxEXPAND, 5 );
	
	
	gSizer_OuterLayout->AddGrowableCol( 2 );
	gSizer_OuterLayout->AddGrowableCol( 3 );
	gSizer_OuterLayout->AddGrowableCol( 4 );
	gSizer_OuterLayout->AddGrowableCol( 5 );
	gSizer_OuterLayout->AddGrowableCol( 6 );
	gSizer_OuterLayout->AddGrowableRow( 0 );
	gSizer_OuterLayout->AddGrowableRow( 1 );
	gSizer_OuterLayout->AddGrowableRow( 2 );
	
	this->SetSizer( gSizer_OuterLayout );
	this->Layout();
	gSizer_OuterLayout->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_choice_FilterOrder->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameUI::m_choice_FilterOrderOnChoice ), NULL, this );
	m_choice_DesignMethod->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameUI::m_choice_DesignMethodOnChoice ), NULL, this );
	m_choice_ResponeType->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameUI::m_choice_ResponeTypeOnChoice ), NULL, this );
	m_textCtrl_AppliedFreq->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameUI::m_textCtrl_AppliedFreqOnKeyUp ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler( MainFrameUI::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemActivated ) );
	this->Connect( wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU, wxDataViewEventHandler( MainFrameUI::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemContextMenu ) );
	m_textCtrl_SampleSize->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameUI::m_textCtrl_SampleSizeOnKeyUp ), NULL, this );
	m_toggle_Start->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MainFrameUI::m_toggle_StartOnToggleButton ), NULL, this );
}

MainFrameUI::~MainFrameUI()
{
	// Disconnect Events
	m_choice_FilterOrder->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameUI::m_choice_FilterOrderOnChoice ), NULL, this );
	m_choice_DesignMethod->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameUI::m_choice_DesignMethodOnChoice ), NULL, this );
	m_choice_ResponeType->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameUI::m_choice_ResponeTypeOnChoice ), NULL, this );
	m_textCtrl_AppliedFreq->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameUI::m_textCtrl_AppliedFreqOnKeyUp ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler( MainFrameUI::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemActivated ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU, wxDataViewEventHandler( MainFrameUI::m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemContextMenu ) );
	m_textCtrl_SampleSize->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameUI::m_textCtrl_SampleSizeOnKeyUp ), NULL, this );
	m_toggle_Start->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MainFrameUI::m_toggle_StartOnToggleButton ), NULL, this );
	
}
