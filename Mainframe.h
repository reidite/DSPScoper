#define MAINFRAME_NAME "Digital Filter"
#define MAINFRAME_HEIGHT 420
#define MAINFRAME_WIDTH 840
#define AMPL 2.0
#define FREQ 220.0
#define PSI 0.25


#include "wx/aboutdlg.h"


#include "MainFrameUI.h"
#include "signal.h"
#include <thread>

namespace DigitalFilter {
    class MainFrame : public MainFrameUI {
    private:
        std::atomic_bool stopFigureDrawing = false;
        Calc::Signal* originalATSignalData;
        Calc::Signal* filteredATSignalData;
        Calc::Signal* originalMFSignalData;
        Calc::Signal* filteredMFSignalData;


        int axesPos[2];
        bool ticks;
        wxDECLARE_EVENT_TABLE();
        wxDECLARE_NO_COPY_CLASS(MainFrame);

    protected:
        mpWindow* m_Fig1;
        mpWindow* m_Fig2;

    public:
        MainFrame();
        virtual ~MainFrame();

        // Commands
        void Quit(wxCommandEvent& event);
        void Start(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void LoadingOriginalSignal();
    };
}