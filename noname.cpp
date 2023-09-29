///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

MainFrameUI::MainFrameUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 720,240 ), wxDefaultSize );
	
	wxGridSizer* gSizer_OuterLayout;
	gSizer_OuterLayout = new wxGridSizer( 1, 2, 0, 0 );
	
	wxBoxSizer* bSizer_LeftLayout;
	bSizer_LeftLayout = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer_AdjusterLayout;
	gSizer_AdjusterLayout = new wxGridSizer( 2, 2, 0, 0 );
	
	wxStaticBoxSizer* sbSizer_DesignMethod;
	sbSizer_DesignMethod = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Design Method") ), wxVERTICAL );
	
	wxGridSizer* gSizer00;
	gSizer00 = new wxGridSizer( 2, 1, 0, 0 );
	
	m_radioBtn_IIR = new wxRadioButton( sbSizer_DesignMethod->GetStaticBox(), wxID_ANY, wxT("IIR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtn_IIR->SetValue( true ); 
	gSizer00->Add( m_radioBtn_IIR, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	m_radioBtn_FIR = new wxRadioButton( sbSizer_DesignMethod->GetStaticBox(), wxID_ANY, wxT("FIR"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer00->Add( m_radioBtn_FIR, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	
	sbSizer_DesignMethod->Add( gSizer00, 1, wxEXPAND, 5 );
	
	
	gSizer_AdjusterLayout->Add( sbSizer_DesignMethod, 1, wxEXPAND|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer_FilterOrder;
	sbSizer_FilterOrder = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Filter Order") ), wxVERTICAL );
	
	wxGridSizer* gSizer01;
	gSizer01 = new wxGridSizer( 2, 1, 0, 0 );
	
	m_radioBtn_Firstorder = new wxRadioButton( sbSizer_FilterOrder->GetStaticBox(), wxID_ANY, wxT("First order"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtn_Firstorder->SetValue( true ); 
	gSizer01->Add( m_radioBtn_Firstorder, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	m_radioBtn_Secondorder = new wxRadioButton( sbSizer_FilterOrder->GetStaticBox(), wxID_ANY, wxT("Second order"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer01->Add( m_radioBtn_Secondorder, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	
	sbSizer_FilterOrder->Add( gSizer01, 1, wxEXPAND, 5 );
	
	
	gSizer_AdjusterLayout->Add( sbSizer_FilterOrder, 1, wxEXPAND|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer_ResponseType;
	sbSizer_ResponseType = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Response Type") ), wxVERTICAL );
	
	wxGridSizer* gSizer10;
	gSizer10 = new wxGridSizer( 4, 1, 0, 0 );
	
	m_radioBtn_Lowpass = new wxRadioButton( sbSizer_ResponseType->GetStaticBox(), wxID_ANY, wxT("Low-pass"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtn_Lowpass->SetValue( true ); 
	gSizer10->Add( m_radioBtn_Lowpass, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	m_radioBtn_Highpass = new wxRadioButton( sbSizer_ResponseType->GetStaticBox(), wxID_ANY, wxT("High-pass"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer10->Add( m_radioBtn_Highpass, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	m_radioBtn_Bandpass = new wxRadioButton( sbSizer_ResponseType->GetStaticBox(), wxID_ANY, wxT("Band-pass"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer10->Add( m_radioBtn_Bandpass, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	m_radioBtn_Bandstop = new wxRadioButton( sbSizer_ResponseType->GetStaticBox(), wxID_ANY, wxT("Band-stop"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer10->Add( m_radioBtn_Bandstop, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	
	sbSizer_ResponseType->Add( gSizer10, 1, wxEXPAND, 5 );
	
	
	gSizer_AdjusterLayout->Add( sbSizer_ResponseType, 1, wxEXPAND|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer_SpecifyFrequency;
	sbSizer_SpecifyFrequency = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Specify Frequency") ), wxVERTICAL );
	
	wxGridSizer* gSizer11;
	gSizer11 = new wxGridSizer( 3, 2, 0, 0 );
	
	m_staticText_Samplefreq = new wxStaticText( sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxT("Sample freq"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Samplefreq->Wrap( -1 );
	gSizer11->Add( m_staticText_Samplefreq, 0, wxLEFT, 5 );
	
	m_textCtrl_Samplefreq = new wxTextCtrl( sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_textCtrl_Samplefreq->SetMaxLength( 6 ); 
	gSizer11->Add( m_textCtrl_Samplefreq, 3, wxSHAPED, 5 );
	
	m_staticText_Passfreq = new wxStaticText( sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxT("Pass freq"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Passfreq->Wrap( -1 );
	gSizer11->Add( m_staticText_Passfreq, 0, wxLEFT, 5 );
	
	m_textCtrl_Passfreq = new wxTextCtrl( sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_textCtrl_Passfreq->SetMaxLength( 6 ); 
	gSizer11->Add( m_textCtrl_Passfreq, 0, wxSHAPED, 5 );
	
	m_staticText_Stopfreq = new wxStaticText( sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxT("Stop freq"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Stopfreq->Wrap( -1 );
	gSizer11->Add( m_staticText_Stopfreq, 0, wxLEFT, 5 );
	
	m_textCtrl_Stopfreq = new wxTextCtrl( sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_textCtrl_Stopfreq->SetMaxLength( 6 ); 
	gSizer11->Add( m_textCtrl_Stopfreq, 0, wxSHAPED, 5 );
	
	
	sbSizer_SpecifyFrequency->Add( gSizer11, 1, wxEXPAND, 5 );
	
	
	gSizer_AdjusterLayout->Add( sbSizer_SpecifyFrequency, 1, wxEXPAND|wxLEFT, 5 );
	
	
	bSizer_LeftLayout->Add( gSizer_AdjusterLayout, 1, wxALIGN_CENTER|wxSHAPED, 5 );
	
	m_toggle_Start = new wxToggleButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxSize( 100,50 ), 0 );
	m_toggle_Start->SetValue( true ); 
	m_toggle_Start->SetFont( wxFont( 14, 74, 90, 90, false, wxT("Calibri") ) );
	m_toggle_Start->SetMinSize( wxSize( 100,50 ) );
	
	bSizer_LeftLayout->Add( m_toggle_Start, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	gSizer_OuterLayout->Add( bSizer_LeftLayout, 1, wxALIGN_LEFT|wxEXPAND|wxSHAPED, 5 );
	
	gSizer_Outputs = new wxGridSizer( 2, 1, 0, 0 );
	
	gSizer_Outputs->SetMinSize( wxSize( 360,320 ) ); 
	
	gSizer_OuterLayout->Add( gSizer_Outputs, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( gSizer_OuterLayout );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_radioBtn_IIR->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_IIROnRadioButton ), NULL, this );
	m_radioBtn_FIR->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_FIROnRadioButton ), NULL, this );
	m_radioBtn_Firstorder->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_FirstorderOnRadioButton ), NULL, this );
	m_radioBtn_Secondorder->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_SecondorderOnRadioButton ), NULL, this );
	m_radioBtn_Lowpass->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_LowpassOnRadioButton ), NULL, this );
	m_radioBtn_Highpass->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_HighpassOnRadioButton ), NULL, this );
	m_radioBtn_Bandpass->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_BandpassOnRadioButton ), NULL, this );
	m_radioBtn_Bandstop->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_BandstopOnRadioButton ), NULL, this );
	m_textCtrl_Samplefreq->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameUI::m_textCtrl_SamplefreqOnKeyUp ), NULL, this );
	m_textCtrl_Passfreq->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameUI::m_textCtrl_PassfreqOnKeyUp ), NULL, this );
	m_textCtrl_Stopfreq->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameUI::m_textCtrl_StopfreqOnKeyUp ), NULL, this );
	m_toggle_Start->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MainFrameUI::m_toggle_StartOnToggleButton ), NULL, this );
}

MainFrameUI::~MainFrameUI()
{
	// Disconnect Events
	m_radioBtn_IIR->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_IIROnRadioButton ), NULL, this );
	m_radioBtn_FIR->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_FIROnRadioButton ), NULL, this );
	m_radioBtn_Firstorder->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_FirstorderOnRadioButton ), NULL, this );
	m_radioBtn_Secondorder->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_SecondorderOnRadioButton ), NULL, this );
	m_radioBtn_Lowpass->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_LowpassOnRadioButton ), NULL, this );
	m_radioBtn_Highpass->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_HighpassOnRadioButton ), NULL, this );
	m_radioBtn_Bandpass->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_BandpassOnRadioButton ), NULL, this );
	m_radioBtn_Bandstop->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MainFrameUI::m_radioBtn_BandstopOnRadioButton ), NULL, this );
	m_textCtrl_Samplefreq->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameUI::m_textCtrl_SamplefreqOnKeyUp ), NULL, this );
	m_textCtrl_Passfreq->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameUI::m_textCtrl_PassfreqOnKeyUp ), NULL, this );
	m_textCtrl_Stopfreq->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameUI::m_textCtrl_StopfreqOnKeyUp ), NULL, this );
	m_toggle_Start->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MainFrameUI::m_toggle_StartOnToggleButton ), NULL, this );
	
}
