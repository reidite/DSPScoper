///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrameUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrameUI::MainFrameUI(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxGridSizer* gSizer_OuterLayout;
	gSizer_OuterLayout = new wxGridSizer(1, 2, 0, 0);

	wxBoxSizer* bSizer_LeftLayout;
	bSizer_LeftLayout = new wxBoxSizer(wxVERTICAL);

	wxGridSizer* gSizer_AdjusterLayout;
	gSizer_AdjusterLayout = new wxGridSizer(2, 2, 0, 0);

	wxStaticBoxSizer* sbSizer_DesignMethod;
	sbSizer_DesignMethod = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Design Method")), wxVERTICAL);

	wxGridSizer* gSizer00;
	gSizer00 = new wxGridSizer(2, 1, 0, 0);

	m_radioBtn_IIR = new wxRadioButton(sbSizer_DesignMethod->GetStaticBox(), wxID_ANY, wxT("IIR"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer00->Add(m_radioBtn_IIR, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxALL, 5);

	m_radioBtn_FIR = new wxRadioButton(sbSizer_DesignMethod->GetStaticBox(), wxID_ANY, wxT("FIR"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer00->Add(m_radioBtn_FIR, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxALL, 5);


	sbSizer_DesignMethod->Add(gSizer00, 1, wxEXPAND, 5);


	gSizer_AdjusterLayout->Add(sbSizer_DesignMethod, 1, wxEXPAND | wxLEFT, 5);

	wxStaticBoxSizer* sbSizer_FilterOrder;
	sbSizer_FilterOrder = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Filter Order")), wxVERTICAL);

	wxGridSizer* gSizer01;
	gSizer01 = new wxGridSizer(2, 1, 0, 0);

	m_radioBtn_Firstorder = new wxRadioButton(sbSizer_FilterOrder->GetStaticBox(), wxID_ANY, wxT("First order"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer01->Add(m_radioBtn_Firstorder, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxALL, 5);

	m_radioBtn_Secondorder = new wxRadioButton(sbSizer_FilterOrder->GetStaticBox(), wxID_ANY, wxT("Second order"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer01->Add(m_radioBtn_Secondorder, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxALL, 5);


	sbSizer_FilterOrder->Add(gSizer01, 1, wxEXPAND, 5);


	gSizer_AdjusterLayout->Add(sbSizer_FilterOrder, 1, wxEXPAND | wxLEFT, 5);

	wxStaticBoxSizer* sbSizer_ResponseType;
	sbSizer_ResponseType = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Response Type")), wxVERTICAL);

	wxGridSizer* gSizer10;
	gSizer10 = new wxGridSizer(4, 1, 0, 0);

	m_radioBtn_Lowpass = new wxRadioButton(sbSizer_ResponseType->GetStaticBox(), wxID_ANY, wxT("Low-pass"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer10->Add(m_radioBtn_Lowpass, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxALL, 5);

	m_radioBtn_Highpass = new wxRadioButton(sbSizer_ResponseType->GetStaticBox(), wxID_ANY, wxT("High-pass"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer10->Add(m_radioBtn_Highpass, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxALL, 5);

	m_radioBtn_Bandpass = new wxRadioButton(sbSizer_ResponseType->GetStaticBox(), wxID_ANY, wxT("Band-pass"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer10->Add(m_radioBtn_Bandpass, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxALL, 5);

	m_radioBtn_Bandstop = new wxRadioButton(sbSizer_ResponseType->GetStaticBox(), wxID_ANY, wxT("Band-stop"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer10->Add(m_radioBtn_Bandstop, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxALL, 5);


	sbSizer_ResponseType->Add(gSizer10, 1, wxEXPAND, 5);


	gSizer_AdjusterLayout->Add(sbSizer_ResponseType, 1, wxEXPAND | wxLEFT, 5);

	wxStaticBoxSizer* sbSizer_SpecifyFrequency;
	sbSizer_SpecifyFrequency = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Specify Frequency")), wxVERTICAL);

	wxGridSizer* gSizer11;
	gSizer11 = new wxGridSizer(3, 2, 0, 0);

	m_staticText_Samplefreq = new wxStaticText(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxT("Sample freq"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_Samplefreq->Wrap(-1);
	gSizer11->Add(m_staticText_Samplefreq, 0, wxLEFT, 5);

	m_textCtrl_Samplefreq = new wxTextCtrl(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE);
	m_textCtrl_Samplefreq->SetMaxLength(6);
	gSizer11->Add(m_textCtrl_Samplefreq, 3, wxSHAPED, 5);

	m_staticText_Passfreq = new wxStaticText(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxT("Pass freq"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_Passfreq->Wrap(-1);
	gSizer11->Add(m_staticText_Passfreq, 0, wxLEFT, 5);

	m_textCtrl_Passfreq = new wxTextCtrl(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE);
	m_textCtrl_Passfreq->SetMaxLength(6);
	gSizer11->Add(m_textCtrl_Passfreq, 0, wxSHAPED, 5);

	m_staticText_Stopfreq = new wxStaticText(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxT("Stop freq"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_Stopfreq->Wrap(-1);
	gSizer11->Add(m_staticText_Stopfreq, 0, wxLEFT, 5);

	m_textCtrl_Stopfreq = new wxTextCtrl(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE);
	m_textCtrl_Stopfreq->SetMaxLength(6);
	gSizer11->Add(m_textCtrl_Stopfreq, 0, wxSHAPED, 5);


	sbSizer_SpecifyFrequency->Add(gSizer11, 1, wxEXPAND, 5);


	gSizer_AdjusterLayout->Add(sbSizer_SpecifyFrequency, 1, wxEXPAND | wxLEFT, 5);


	bSizer_LeftLayout->Add(gSizer_AdjusterLayout, 1, wxALIGN_TOP, 5);

	m_button_Start = new wxButton(this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	bSizer_LeftLayout->Add(m_button_Start, 0, wxALIGN_CENTER | wxALIGN_CENTER_VERTICAL, 5);


	gSizer_OuterLayout->Add(bSizer_LeftLayout, 1, wxEXPAND, 5);

	gSizer_Outputs = new wxGridSizer(2, 1, 0, 0);


	gSizer_OuterLayout->Add(gSizer_Outputs, 1, wxEXPAND, 5);


	this->SetSizer(gSizer_OuterLayout);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	m_button_Start->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameUI::m_button_StartOnButtonClick), NULL, this);
}

MainFrameUI::~MainFrameUI()
{
	// Disconnect Events
	m_button_Start->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameUI::m_button_StartOnButtonClick), NULL, this);

}
