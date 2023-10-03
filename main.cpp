#include "wx/wxprec.h"
#include "wx/log.h"
#include "wx/app.h"
#include "wx/scrolwin.h"
#include "wx/fontpicker.h"

#include "./Mainframe.h"

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
wxIMPLEMENT_APP(App);
