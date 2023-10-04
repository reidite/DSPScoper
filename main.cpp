#include "wx/wxprec.h"
#include "wx/log.h"
#include "wx/app.h"
#include "wx/scrolwin.h"
#include "wx/fontpicker.h"
#include "wx/settings.h"

#include "./Mainframe.h"

class App : public wxApp {
private:
    DigitalFilter::MainFrame* frame;
public:
	App() { }

    bool OnInit() wxOVERRIDE;
	wxDECLARE_NO_COPY_CLASS(App);
};


bool App::OnInit() {
    if (!wxApp::OnInit())
        return false;
    frame = new DigitalFilter::MainFrame();
    wxIcon icon("IDI_ICON", 32, 32);
    frame->SetIcon(icon);
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(App);
