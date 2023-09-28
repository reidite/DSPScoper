#define MAINFRAME_NAME "Digital Filter"
#define MAINFRAME_HEIGHT 420
#define MAINFRAME_WIDTH 840
#define AMPL 2.0
#define FREQ 220.0
#define PSI 0.25
#define DEFAULT_SAMPLEFREQ 220
#define DEFAULT_PASSFREQ 50
#define DEFAULT_STOPFREQ 50

#include "wx/aboutdlg.h"
#include "MainFrameUI.h"
#include "coefstrategy.h"
#include "signal.h"
#include <thread>

enum RESPOND_TYPE {
    LOWBASS,
    HIGHBASS,
    BANDBASS,
    BANDSTOP
};

namespace DigitalFilter {
    class MainFrame : public MainFrameUI {
    private:
        std::atomic_bool stopFigureDrawing = false;
        int _sampleFreq = DEFAULT_SAMPLEFREQ;
        int _passFreq = DEFAULT_PASSFREQ;
        int _stopFreq = DEFAULT_STOPFREQ;
        RESPOND_TYPE filterType;

        
        wxDECLARE_EVENT_TABLE();
        wxDECLARE_NO_COPY_CLASS(MainFrame);

    protected:
        mpWindow* m_Fig1;
        mpWindow* m_Fig2;

        Calc::Signal* originalATSignalData;
        Calc::Signal* filteredATSignalData;
        Calc::Signal* originalMFSignalData;
        Calc::Signal* filteredMFSignalData;

    public:
        MainFrame();
        virtual ~MainFrame();

        // Commands
        void m_textCtrl_SamplefreqOnKeyUp(wxKeyEvent& event);
        void m_textCtrl_PassfreqOnKeyUp(wxKeyEvent& event);
        void m_textCtrl_StopfreqOnKeyUp(wxKeyEvent& event);
        void m_button_StartOnButtonClick(wxCommandEvent& event);

        //int sampleFreq
        void Quit(wxCommandEvent& event);
        void Start(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void LoadingOriginalSignal();
        void LoadingFilteredSignal();
    };
}