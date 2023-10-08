/////////////////////////////////////////////////////////////////////////////
// Name:            plot.cpp
// Purpose:         Definition for the plotting classes providing functionality
//                  for creating plots and graph
// Author:          Vincent Nguyen
// Maintainer:      Vincent Nguyen
// Contributors:    N/A
// Created:         25/09/2023
// Last edit:       06/10/2023
// Copyright:       Anyone
// Licence:         GPL-3.0 license
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
// Customized Plots
//---------------------------------------------------------------------------

//!< Definition of the default margin value of the plot windows
#define PLOT_MARGIN 5

#pragma once
#include "mathplot.h"
#include <vector>
#include <complex>

namespace UI
{
    namespace Plot
    {
        class SignalPlot : public mpFXYVector
        {
            /** A customized class inheriting mpFXYVector to present some
             *	properties of the output figure.
             */
        public:
            SignalPlot(const wxColour &colour);
            void DrawingSignalData(std::vector<double> x, std::vector<double> y);
            void DrawingDFTData(std::vector<double> x, std::vector<double> y, int maxFreq);
        };

        class ATPlotWindow : public mpWindow
        {
            /** A customized class inheriting mpWindow to operate some GUI
             *	interacting on the plot figure.
             */
        private:
            //!< Constraint viewing the bounding box of the plot figure.
            double lf_minX, lf_maxX, lf_minY, lf_maxY;

        public:
            ATPlotWindow(wxWindow *parent);

            //!< Updating new constraint bounding box.
            void UpdatingBoundingBox(double sumAmp);

            //!< Override interaction events.
            void OnFit(wxCommandEvent &event);
            void OnMouseLeftDown(wxMouseEvent &event) {}
            void OnMouseLeftRelease(wxMouseEvent &event) {}
        };

        class MFPlotWindow : public mpWindow
        {
            /** A customized class inheriting mpWindow to operate some GUI
             *	interacting on the plot figure.
             */
        private:
            //!< Constraint viewing the bounding box of the plot figure.
            double lf_minX, lf_maxX, lf_minY, lf_maxY;

        public:
            MFPlotWindow(wxWindow *parent);

            //!< Updating new constraint bounding box.
            void UpdatingBoundingBox(double maxAmp, double maxFreq);

            //!< Override interaction events.
            void OnFit(wxCommandEvent &event);
            void OnMouseLeftDown(wxMouseEvent &event) {}
            void OnMouseLeftRelease(wxMouseEvent &event) {}
        };
    }
}