/////////////////////////////////////////////////////////////////////////////
// Name:            MainFrame.cpp
// Purpose:         Definition for the class MainFrame as the main GUI
// Author:          Vincent Nguyen
// Maintainer:      Vincent Nguyen
// Contributors:    N/A
// Created:         25/09/2023
// Last edit:       06/10/2023
// Copyright:       Anyone
// Licence:         GPL-3.0 license
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
// MainFrame
//---------------------------------------------------------------------------

//!< Definition of name and default size for the application main frame 
#define MAINFRAME_NAME "DSPScoper"
#define MAINFRAME_WIDTH 780
#define MAINFRAME_HEIGHT 570

//!< Default value of the applied frequency in filter control
#define DEFAULT_APPLIED_FREQ 50

//!< Default value of the sampling rate in signal control
#define DEFAULT_SAMPLING_RATE 1024

#include <thread>
#include <atomic>

#include "wx/aboutdlg.h"

#include "../calc/filter.h"
#include "../calc/signal.h"
#include "./plot/plot.h"
#include "GUI.h"

namespace UI {
    class MainFrame : public MainFrameUI {
    /** @brief The main frame of the application handling user inputs and events generated
        by the GUI elements contained within it. This class defines plot
        windows for signal visualizations, and input data from the user to
        control the application.
    */
    private:
        //!< Drawing plots thread to update and refresh plots.
        std::thread* pthrd_PlotUpdater;

        //!< Tracking states of a drawing plots thread.
        std::atomic_bool atomic_b_drawingPlotsInProgress;
        std::atomic_bool atomic_b_updatingPlotsRaised;
        std::atomic_bool atomic_b_drawingFiltedResultRaised;

        //!< Operating signal synthesizing
        Calc::Signal* p_signal;

        //!< Operating signal filtering
        Calc::Filter* p_filter;

        //!< Current number of row of signal infos
        unsigned int un_numRowInfos = 0;
        //!< Current sum amplitude in signal infos
        double lf_sumAmpSignal = 0.0;
        //!< Current max amplitude in signal infos
        double lf_maxAmpSignal = INT_MIN;
        //!< Current max frequency in signal infos
        double lf_maxFreqSignal = INT_MIN;

        //!< Current apllied frequency value
        int n_appliedFreq = DEFAULT_APPLIED_FREQ;
        //!< Current sampling rate value
        int n_numSampling = DEFAULT_SAMPLING_RATE;

        //!< Current current user selections
        unsigned int un_filterOrder = 0;
        unsigned int un_filterType = 0;
        unsigned int un_filterClass = 0;
        unsigned int un_filterRespone = 0;

        //!< Filter Control Loading
        void LoadingFilter();

        //!< Signal Control Loading
        void LoadingSignalInfos();

        //!< Plot Windows Loading
        void SettingPlotsUI();
        void LoadingPlotsUpdater();

    protected:
        //!< Canvas context menu of signal information
        wxMenu* mp_infoPopMenu;

        //!< Windows to contain signal plots
        Plot::ATPlotWindow* mp_FigAT;
        Plot::MFPlotWindow* mp_FigMF;

        //!< Signal plots
        Plot::SignalPlot* mp_originalATPlot;
        Plot::SignalPlot* mp_filteredATPlot;
        Plot::SignalPlot* mp_originalMFPlot;
        Plot::SignalPlot* mp_filteredMFPlot;

        //!< Columns of signal information
        std::vector<wxDataViewColumn*> m_colInfos = std::vector<wxDataViewColumn*>(4, nullptr);

        //!< MainFrame Events
        void MainFrameUIOnClose(wxCloseEvent& event);
        void MainFrameUIOnAbout(wxCommandEvent& event);

        //!< Filter Control Events
        void m_choice_FilterOrderOnChoice(wxCommandEvent& event);
        void m_choice_FilterTypeOnChoice(wxCommandEvent& event);
        void m_choice_FilterClassOnChoice(wxCommandEvent& event);
        void m_choice_FilterResponseOnChoice(wxCommandEvent& event);
        void m_textCtrl_AppliedFreqOnKeyUp(wxKeyEvent& event);

        //!< Signal Control Events
        void m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemActivated(wxDataViewEvent& event);
        void m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemContextMenu(wxDataViewEvent& event);
        void m_dataViewListCtrl_SignalInfoOnDataViewListCtrlOnMenuSelect(wxCommandEvent& event);
        void m_textCtrl_SamplingRateOnKeyUp(wxKeyEvent& event);

        //!< Start Button Events
        void m_toggle_StartOnToggleButton(wxCommandEvent& event);

    public:
        MainFrame();
        virtual ~MainFrame();

        wxDECLARE_NO_COPY_CLASS(MainFrame);
    };
}