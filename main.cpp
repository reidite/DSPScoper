/////////////////////////////////////////////////////////////////////////////
// Name:            main.cpp
// Purpose:         Initialize the entry point of the program
// Author:          Vincent Nguyen
// Maintainer:      Vincent Nguyen
// Contributors:    N/A
// Created:         25/09/2023
// Last edit:       06/10/2023
// Copyright:       Anyone
// Licence:         GPL-3.0 license
/////////////////////////////////////////////////////////////////////////////
#include "./Mainframe.h"

//---------------------------------------------------------------------------
// DSPInspector
//---------------------------------------------------------------------------

class DSPScoper : public wxApp {
private:
    DigitalFilter::MainFrame* frame;
public:
    DSPScoper() { }

    bool OnInit() wxOVERRIDE;

	wxDECLARE_NO_COPY_CLASS(DSPScoper);
};


bool DSPScoper::OnInit() {
    if (!wxApp::OnInit())
        return false;
    frame = new DigitalFilter::MainFrame();
    wxIcon icon("IDI_ICON", 32, 32);
    frame->SetIcon(icon);
    frame->Show(true);
    return true;
}


wxIMPLEMENT_APP(DSPScoper);
