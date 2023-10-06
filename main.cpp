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
// DSPScoper
//---------------------------------------------------------------------------

class DSPScoper : public wxApp {
/** Main class of the application, initializing the program, 
*   setting up any necessary resources.
*/
private:
    //!< Container of the main frame instance
    DSP::MainFrame* mp_frame;
public:
    DSPScoper() { }

    //!< Called before OnRun() to do initialization
    bool OnInit() wxOVERRIDE;

	wxDECLARE_NO_COPY_CLASS(DSPScoper);
};


bool DSPScoper::OnInit() {
    /**
    * Setting up resources on initializing time of the application.
    *
    */
    if (!wxApp::OnInit())
        return false;
    mp_frame = new DSP::MainFrame();
    wxIcon icon("IDI_ICON", 32, 32);
    mp_frame->SetIcon(icon);
    mp_frame->Show(true);
    return true;
}


wxIMPLEMENT_APP(DSPScoper);
