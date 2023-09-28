#include "Mainframe.h"

DigitalFilter::MainFrame::MainFrame()
					: MainFrameUI(nullptr, wxID_ANY, MAINFRAME_NAME, wxDefaultPosition, wxSize(MAINFRAME_WIDTH, MAINFRAME_HEIGHT)) {
	mpScaleX* timeAxis = new mpScaleX(wxT("Time"), mpALIGN_BORDER_BOTTOM, true, mpX_NORMAL);
	mpScaleY* amplitudeAxis = new mpScaleY(wxT("Amplitude"), mpALIGN_BORDER_LEFT, true);
	mpScaleX* freqAxis = new mpScaleX(wxT("Frequency"), mpALIGN_BORDER_BOTTOM, true, mpX_NORMAL);
	mpScaleY* modulusAxis = new mpScaleY(wxT("Modulus"), mpALIGN_BORDER_LEFT, true);
	timeAxis->SetContinuity(true);
	freqAxis->SetContinuity(true);
	amplitudeAxis->SetContinuity(true);


	wxPen drawingBluePen(*wxBLUE, 4, wxPENSTYLE_SOLID);
	wxPen drawingRedPen(*wxRED, 4, wxPENSTYLE_SOLID);

	timeAxis->SetDrawOutsideMargins(true);
	freqAxis->SetDrawOutsideMargins(true);
	amplitudeAxis->SetDrawOutsideMargins(true);

	m_Fig1 = new mpWindow(this, 0, wxPoint(0, 0), wxSize(300, 100), wxSUNKEN_BORDER);
	m_Fig1->AddLayer(timeAxis);
	m_Fig1->AddLayer(amplitudeAxis);

	originalATSignalData = new Calc::Signal(AMPL, FREQ, PSI);
	originalATSignalData->SetContinuity(true);
	originalATSignalData->SetPen(drawingBluePen);
	originalATSignalData->SetATSignalData(100);
	m_Fig1->AddLayer(originalATSignalData);

	gSizer_Outputs->Add(m_Fig1, 0, wxEXPAND, 5);
	m_Fig1->Fit();

	m_Fig2 = new mpWindow(this, -1, wxPoint(0, 0), wxSize(100, 100), wxSUNKEN_BORDER);
	m_Fig2->AddLayer(freqAxis);
	m_Fig2->AddLayer(modulusAxis);

	originalMFSignalData = new DigitalFilter::Calc::Signal(originalATSignalData);
	originalMFSignalData->SetContinuity(true);
	originalMFSignalData->SetPen(drawingBluePen);
	originalMFSignalData->SetMFSignalData(originalATSignalData);
	m_Fig2->AddLayer(originalATSignalData);
	gSizer_Outputs->Add(m_Fig2, 1, wxEXPAND, 5);
	m_Fig2->Fit();

}

DigitalFilter::MainFrame::~MainFrame() {
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

void DigitalFilter::MainFrame::LoadingOriginalSignal() {
	while (!stopFigureDrawing) {
		//m_Fig1->Refresh();
		//originalSignal = new Signal(AMPL, FREQ, PSI);
	}
}