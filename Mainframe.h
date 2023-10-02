#define MAINFRAME_NAME "Digital Filter"
#define MAINFRAME_HEIGHT 520
#define MAINFRAME_WIDTH 720

#define INIT_AMPL 1.0
#define INIT_FREQ 5.0
#define INIT_PSI 0.1

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

namespace DigitalFilter {
    class SignalPlot : public mpFXYVector {
    public:
        SignalPlot() : mpFXYVector(wxT("f(x) = A*sin(2*PI*Freq*x)"), mpALIGN_LEFT) {

        }
        void DrawingSignalData(std::vector<double> x, std::vector<double> y) {
            this->Clear();
            this->SetData(x, y);
        }

        void DrawingDFTData(std::vector<double> x, std::vector<double> y) {
            int N = y.size();
            int K = x.size();

            std::complex<double> intSum;

            std::vector<std::complex<double>> output;
            output.reserve(K);

            for (int k = 0; k < K; k++) {
                intSum = std::complex<double>(0.0, 0.0);
                for (int n = 0; n < N; n++) {
                    double realPart = cos((2 * M_PI / N) * k * n);
                    double imagPart = sin((2 * M_PI / N) * k * n);

                    std::complex<double> w(realPart, -imagPart);

                    intSum += y[n] * w;
                }

                output.push_back(intSum);
            }

            std::vector<double> freqs;
            std::vector<double> modus;

            for (int n = 0; n < K; n++)
            {
                freqs.push_back(n);
            }

            for (auto& ii : output)
            {
                ii = ii / static_cast<double>(N);
                modus.push_back(std::abs(ii));
            }

            this->SetData(freqs, modus);
        }
    };

    class MainFrame : public MainFrameUI {
    private:
        std::atomic_bool isLoadingSignal = true;
        std::atomic_bool isUpdatingSignal = true;
        std::atomic_bool isDrawingFiltedResult = false;

        std::condition_variable isLoadingPlotInited;
        std::mutex lockLoadingSignal;
        std::unique_lock<std::mutex> loadingSignalLocker{ lockLoadingSignal };
        
        Calc::Signal* signal;
        Calc::Filter* filter;

        unsigned int itemID = 0;

        wxDECLARE_EVENT_TABLE();
        wxDECLARE_NO_COPY_CLASS(MainFrame);

    protected:
        int _numberOfSample = DEFAULT_NUMBER_OF_SAMPLE;
        int _appliedFreq = DEFAULT_APPLIED_FREQ;

        unsigned int designMethod = 0;
        unsigned int filterOrder = 0;
        unsigned int filterType = 0;

        mpWindow* m_Fig1;
        mpWindow* m_Fig2;

        SignalPlot* originalATPlot;
        SignalPlot* filteredATPlot;
        SignalPlot* originalMFPlot;
        SignalPlot* filteredMFPlot;

        std::vector<wxDataViewColumn*> cols = std::vector<wxDataViewColumn*>(4, nullptr);
        wxDataViewColumn* col_amp;
        wxDataViewColumn* col_freq;
        wxDataViewColumn* col_psi;

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

        void m_toggle_StartOnToggleButton(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

        // Plotings
        void SettingThePlots();
        void SettingSignalProperties();
        void UpdatingFreq();
        void LoadingFilter();
        void LoadingSignal();
        void LoadingFilteredSignal();
        void TerminatePlotThread();
        void UpdatingSignalInfo();
    };
}