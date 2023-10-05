#define MAINFRAME_NAME "Digital Filter"
#define MAINFRAME_WIDTH 720
#define MAINFRAME_HEIGHT 620

#define PLOT_MARGIN 5

#define DEFAULT_NUMBER_OF_SAMPLE 1000
#define DEFAULT_APPLIED_FREQ 50

#define DEFAULT_SAMPLEFREQ 12
#define DEFAULT_PASSFREQ 5
#define DEFAULT_STOPFREQ 5


#include <thread>
#include <iomanip>
#include <mutex>
#include <condition_variable>
#include "wx/aboutdlg.h"

#include "./plot/mathplot.h"
#include "./ui/MainFrameUI.h"
#include "./calc/filter.h"
#include "./calc/signal.h"

enum INFOCMD {
    mpINFO_NEW,
    mpINFO_REMOVE
};

namespace DigitalFilter {
    class SignalPlot : public mpFXYVector {
    public:
        SignalPlot() : mpFXYVector(wxT("f(x) = A*sin(2*PI*Freq*x)"), mpALIGN_LEFT) {

        }
        void DrawingSignalData(std::vector<double> x, std::vector<double> y) {
            this->Clear();
            this->SetData(x, y);
        }

        void DrawingDFTData(std::vector<double> x, std::vector<double> y, int maxFreq);
    };

    class MainFrame : public MainFrameUI {
    private:
        std::thread* PlotUpdater;
        std::atomic_bool isLoadingSignal = true;
        std::atomic_bool isUpdatingSignal = true;
        std::atomic_bool isDrawingFiltedResult = false;

        Calc::Signal* signal;
        Calc::Filter* filter;

        unsigned int itemID = 0;
        
        wxDECLARE_NO_COPY_CLASS(MainFrame);

    protected:
        int _numberOfSample = DEFAULT_NUMBER_OF_SAMPLE;
        int _appliedFreq = DEFAULT_APPLIED_FREQ;

        unsigned int designMethod = 0;
        unsigned int filterOrder = 0;
        unsigned int filterType = 0;

        wxMenu* m_infoPopMenu;

        mpWindow* m_Fig1;
        mpWindow* m_Fig2;

        SignalPlot* originalATPlot;
        SignalPlot* filteredATPlot;
        SignalPlot* originalMFPlot;
        SignalPlot* filteredMFPlot;

        std::vector<wxDataViewColumn*> cols = std::vector<wxDataViewColumn*>(4, nullptr);

    public:
        MainFrame();
        virtual ~MainFrame();

        // Commands
        void m_choice_DesignMethodOnChoice(wxCommandEvent& event);
        void m_choice_FilterOrderOnChoice(wxCommandEvent& event);
        void m_choice_ResponeTypeOnChoice(wxCommandEvent& event);
        void m_textCtrl_SampleSizeOnKeyUp(wxKeyEvent& event);
        void m_textCtrl_AppliedFreqOnKeyUp(wxKeyEvent& event);

        void m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemActivated(wxDataViewEvent& event);
        void m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemContextMenu(wxDataViewEvent& event);
        void m_toggle_StartOnToggleButton(wxCommandEvent& event);
        void MainFrameUIOnClose(wxCloseEvent& event);
        void OnAbout(wxCommandEvent& event);

        // Plotings
        void SettingThePlots();
        void SettingSignalProperties();
        void LoadingFilter();
        void LoadingSignalUpdater();

        // InfoDataViewing
        void UpdatingSignalInfo();
        void OnMenuSelect(wxCommandEvent& WXUNUSED(event));
    };
}