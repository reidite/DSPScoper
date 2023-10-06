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
#define PLOT_MARGIN 5

#pragma once
#include "./mathplot.h"
#include <vector>
#include <complex>

namespace DigitalFilter {
	namespace Plot {
        class SignalPlot : public mpFXYVector {
        public:
            SignalPlot(const wxColour& colour);
            void DrawingSignalData(std::vector<double> x, std::vector<double> y);
            void DrawingDFTData(std::vector<double> x, std::vector<double> y, int maxFreq);
        };

        class ATPlotWindow : public mpWindow {
        private:
            double _minX, _maxX, _minY, _maxY;
        public:
            ATPlotWindow(wxWindow* parent);

            void UpdatingBoundingBox(double maxAmp);
            void OnFit(wxCommandEvent& event);
            void OnMouseLeftDown(wxMouseEvent& event) {}
            void OnMouseLeftRelease(wxMouseEvent& event) {}
        };

        class MFPlotWindow : public mpWindow {
        private:
            double _minX, _maxX, _minY, _maxY;
        public:
            MFPlotWindow(wxWindow* parent);

            void UpdatingBoundingBox(double maxAmp, double maxFreq);
            void OnFit(wxCommandEvent& event);
            void OnMouseLeftDown(wxMouseEvent& event) {}
            void OnMouseLeftRelease(wxMouseEvent& event) {}
        };
	}
}