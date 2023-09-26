/////////////////////////////////////////////////////////////////////////////
// Name:        collpane.cpp
// Purpose:     wxCollapsiblePane sample
// Author:      Francesco Montorsi
// Modified by:
// Created:     14/10/06
// Copyright:   (c) Francesco Montorsi
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"
#include "wx/log.h"
#include "wx/app.h"
#include "wx/scrolwin.h"




#include "wx/fontpicker.h"

#include "Mainframe.h"

enum
{
    PANE_COLLAPSE = 100,
    PANE_EXPAND,
    PANE_SETLABEL,
    PANE_SHOWDLG,
    PANE_ABOUT = wxID_ABOUT,
    PANE_QUIT = wxID_EXIT,

    PANE_BUTTON,
    PANE_TEXTCTRL
};


// ----------------------------------------------------------------------------
// our classes
// ----------------------------------------------------------------------------
namespace DigitalFilter {
	class App : public wxApp {
	public:
		App() { }

		virtual bool OnInit() wxOVERRIDE {
			if (!wxApp::OnInit())
				return false;

			// create and show the main frame
			MainFrame* frame = new MainFrame;

			frame->Show(true);

			return true;
		};

		wxDECLARE_NO_COPY_CLASS(App);
	};
}
wxIMPLEMENT_APP(DigitalFilter::App);
wxBEGIN_EVENT_TABLE(DigitalFilter::MainFrame, wxFrame)
wxEND_EVENT_TABLE()