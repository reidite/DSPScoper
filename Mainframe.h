#define MAINFRAME_NAME "Digital Filter"
#define MAINFRAME_HEIGHT 340
#define MAINFRAME_WIDTH 720

#define AMPL 2.0
#define FREQ 220.0
#define PSI 0.1
#define NUMBER_OF_PTS 100

#define DEFAULT_SAMPLEFREQ 220
#define DEFAULT_PASSFREQ 50
#define DEFAULT_STOPFREQ 50

#include <thread>
#include "wx/aboutdlg.h"

#include "./ui/MainFrameUI.h"
#include "./calc/filter.h"
#include "./calc/signal.h"

namespace DigitalFilter {
    class MainFrame : public MainFrameUI {
    private:
        std::atomic_bool isDrawingFiltedResult = false;
        Calc::Filter* filter;

        wxDECLARE_EVENT_TABLE();
        wxDECLARE_NO_COPY_CLASS(MainFrame);

    protected:
        int _sampleFreq = DEFAULT_SAMPLEFREQ;
        int _passFreq = DEFAULT_PASSFREQ;
        int _stopFreq = DEFAULT_STOPFREQ;
        unsigned int designMethod = 0;
        unsigned int filterOrder = 0;
        unsigned int filterType = 0;

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
        void m_radioBtn_IIROnRadioButton(wxCommandEvent& event);
        void m_radioBtn_FIROnRadioButton(wxCommandEvent& event);
        void m_radioBtn_FirstorderOnRadioButton(wxCommandEvent& event);
        void m_radioBtn_SecondorderOnRadioButton(wxCommandEvent& event);
        void m_radioBtn_LowpassOnRadioButton(wxCommandEvent& event);
        void m_radioBtn_HighpassOnRadioButton(wxCommandEvent& event);
        void m_radioBtn_BandpassOnRadioButton(wxCommandEvent& event);
        void m_radioBtn_BandstopOnRadioButton(wxCommandEvent& event);
        void m_textCtrl_SamplefreqOnKeyUp(wxKeyEvent& event);
        void m_textCtrl_PassfreqOnKeyUp(wxKeyEvent& event);
        void m_textCtrl_StopfreqOnKeyUp(wxKeyEvent& event);
        void m_toggle_StartOnToggleButton(wxCommandEvent& event);

        // Plotings
        void Quit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void SettingThePlots();
        void SettingSignalProperties();

        void LoadingFilter();
        void LoadingSignal();
        void LoadingFilteredSignal();
    };
}