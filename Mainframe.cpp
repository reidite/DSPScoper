#include "Mainframe.h"

DigitalFilter::MainFrame::MainFrame()
					: wxFrame(NULL, wxID_ANY, MAINFRAME_NAME, wxDefaultPosition, wxSize(MAINFRAME_WIDTH, MAINFRAME_HEIGHT)) {
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxGridSizer* gSizer_OuterLayout;
	gSizer_OuterLayout = new wxGridSizer(0, 2, 0, 0);

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


	gSizer_AdjusterLayout->Add(sbSizer_DesignMethod, 1, wxEXPAND, 5);

	wxStaticBoxSizer* sbSizer_FilterOrder;
	sbSizer_FilterOrder = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Filter Order")), wxVERTICAL);

	wxGridSizer* gSizer01;
	gSizer01 = new wxGridSizer(2, 1, 0, 0);

	m_radioBtn_Firstorder = new wxRadioButton(sbSizer_FilterOrder->GetStaticBox(), wxID_ANY, wxT("First order"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer01->Add(m_radioBtn_Firstorder, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxALL, 5);

	m_radioBtn_Secondorder = new wxRadioButton(sbSizer_FilterOrder->GetStaticBox(), wxID_ANY, wxT("Second order"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer01->Add(m_radioBtn_Secondorder, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxALL, 5);


	sbSizer_FilterOrder->Add(gSizer01, 1, wxEXPAND, 5);


	gSizer_AdjusterLayout->Add(sbSizer_FilterOrder, 1, wxEXPAND, 5);

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


	gSizer_AdjusterLayout->Add(sbSizer_ResponseType, 1, wxEXPAND, 5);

	wxStaticBoxSizer* sbSizer_SpecifyFrequency;
	sbSizer_SpecifyFrequency = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Specify Frequency")), wxVERTICAL);

	wxGridSizer* gSizer11;
	gSizer11 = new wxGridSizer(3, 1, 0, 0);

	wxGridSizer* gSizer0;
	gSizer0 = new wxGridSizer(1, 2, 0, 0);

	m_staticText_Samplefreq = new wxStaticText(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxT("Sample freq"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_Samplefreq->Wrap(-1);
	gSizer0->Add(m_staticText_Samplefreq, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_textCtrl_Samplefreq = new wxTextCtrl(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE);
	m_textCtrl_Samplefreq->SetMaxLength(6);
	gSizer0->Add(m_textCtrl_Samplefreq, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	gSizer11->Add(gSizer0, 1, wxEXPAND, 5);

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer(1, 2, 0, 0);

	m_staticText_Passfreq = new wxStaticText(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxT("Pass freq"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_Passfreq->Wrap(-1);
	gSizer1->Add(m_staticText_Passfreq, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_textCtrl_Passfreq = new wxTextCtrl(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE);
	m_textCtrl_Passfreq->SetMaxLength(6);
	gSizer1->Add(m_textCtrl_Passfreq, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	gSizer11->Add(gSizer1, 1, wxEXPAND, 5);

	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer(1, 2, 0, 0);

	m_staticText_Stopfreq = new wxStaticText(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxT("Stop freq"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_Stopfreq->Wrap(-1);
	gSizer2->Add(m_staticText_Stopfreq, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_textCtrl_Stopfreq = new wxTextCtrl(sbSizer_SpecifyFrequency->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	m_textCtrl_Stopfreq->SetMaxLength(6);
	gSizer2->Add(m_textCtrl_Stopfreq, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	gSizer11->Add(gSizer2, 1, wxEXPAND, 5);


	sbSizer_SpecifyFrequency->Add(gSizer11, 1, wxEXPAND, 5);


	gSizer_AdjusterLayout->Add(sbSizer_SpecifyFrequency, 1, wxEXPAND, 5);


	bSizer_LeftLayout->Add(gSizer_AdjusterLayout, 1, wxALIGN_TOP, 5);

	m_button_Start = new wxButton(this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	bSizer_LeftLayout->Add(m_button_Start, 0, wxALIGN_CENTER | wxALIGN_CENTER_VERTICAL, 5);


	gSizer_OuterLayout->Add(bSizer_LeftLayout, 1, wxEXPAND, 5);

	wxGridSizer* gSizer_Outputs;
	gSizer_Outputs = new wxGridSizer(2, 1, 0, 0);

	m_bitmap_Fig1 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
	gSizer_Outputs->Add(m_bitmap_Fig1, 0, wxALL, 5);

	m_bitmap_Fig2 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
	gSizer_Outputs->Add(m_bitmap_Fig2, 0, wxALL, 5);


	gSizer_OuterLayout->Add(gSizer_Outputs, 1, wxEXPAND, 5);


	this->SetSizer(gSizer_OuterLayout);
	this->Layout();

	this->Centre(wxBOTH);
}

DigitalFilter::MainFrame::~MainFrame() {
}


void DigitalFilter::MainFrame::Quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void DigitalFilter::MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxAboutDialogInfo info;
    info.SetName(_(MAINFRAME_NAME));
    info.SetDescription(_("This is a program visualize the result of some digital filters"));
    info.SetCopyright("(C) 2022 Vicent Nguyen <nglequocviet@gmail.com>");

    wxAboutBox(info, this);
}
