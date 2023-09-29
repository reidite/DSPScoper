/////////////////////////////////////////////////////////////////////////////
// Name:        collpane.cpp
// Purpose:     wxCollapsiblePane sample
// Author:      Francesco Montorsi
// Modified by:
// Created:     14/10/06
// Copyright:   (c) Francesco Montorsi
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////
#define WXSUPPRESS_SIZER_FLAGS_CHECK = 1

#include "wx/wxprec.h"
#include "wx/log.h"
#include "wx/app.h"
#include "wx/scrolwin.h"
#include "wx/fontpicker.h"

#include "./Mainframe.h"

enum {
    PANE_COLLAPSE = 100,
    PANE_EXPAND,
    PANE_SETLABEL,
    PANE_SHOWDLG,
    PANE_ABOUT = wxID_ABOUT,
    PANE_QUIT = wxID_EXIT,

    PANE_BUTTON,
    PANE_TEXTCTRL
};


class App : public wxApp {
private:
    DigitalFilter::MainFrame* frame;
    std::thread* OriginalSignalUpdater;
public:
	App() { }

    bool OnInit() wxOVERRIDE;

    void CleanUp() wxOVERRIDE;
	wxDECLARE_NO_COPY_CLASS(App);
};


wxIMPLEMENT_APP(App);

bool App::OnInit() {
    if (!wxApp::OnInit())
        return false;

    // create and show the main frame
    frame = new DigitalFilter::MainFrame();
    frame->Show(true);
    OriginalSignalUpdater = new std::thread(&DigitalFilter::MainFrame::LoadingSignal, &(*frame));
    OriginalSignalUpdater->detach();
    return true;
}

void App::CleanUp() {
    frame->TerminatePlotThread();
    OriginalSignalUpdater->join();
}

wxBEGIN_EVENT_TABLE(DigitalFilter::MainFrame, wxFrame)
wxEND_EVENT_TABLE()
