/////////////////////////////////////////////////////////////////////////////
// Name:            filter.cpp
// Purpose:         Definition for the class Filter to provide functionality 
//                  for filtering data
// Author:          Vincent Nguyen
// Maintainer:      Vincent Nguyen
// Contributors:    N/A
// Created:         25/09/2023
// Last edit:       06/10/2023
// Copyright:       Anyone
// Licence:         GPL-3.0 license
/////////////////////////////////////////////////////////////////////////////
#pragma once
#define _USE_MATH_DEFINES
#include <thread>
#include <vector>
#include "math.h"

namespace DigitalFilter {
    namespace Calc {
        class Filter {
        private:
            std::vector<double> a;
            std::vector<double> b;

        protected:
            unsigned int _filterID;
            unsigned int _responeID;
            
        public:
            Filter(unsigned int respone);
            ~Filter();

            std::vector<double> filting(std::vector<double> y, unsigned int filterType);
            void SetAB(int sample_freq, int cutoff_freq);
            unsigned int getFilterID() { return _filterID; }
            void setResponeID(unsigned int respone) { _responeID = respone; }
            void applyingLowPass(int sample_freq, int cutoff_freq);
            void applyingHighPass(int sample_freq, int cutoff_freq);
            void applyingBandPass(int sample_freq, int cutoff_freq);
            void applyingBandStop(int sample_freq, int cutoff_freq);
        };
    }
}