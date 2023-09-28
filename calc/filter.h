#pragma once
#define _USE_MATH_DEFINES
#include <thread>
#include <vector>
#include "math.h"

//enum DESIGN_METHOD {
//    IIR,
//    FIR
//};
//
//enum FILTER_ORDER {
//    FIRST,
//    SECOND
//};
//
//enum RESPOND_TYPE {
//    LOWPASS,
//    HIGHPASS,
//    BANDPASS,
//    BANDSTOP
//};

namespace DigitalFilter {
    namespace Calc {
        class Filter {
        private:
            std::vector<double> _a;
            std::vector<double> _b;

        protected:
            unsigned int _filterID;
            
        public:
            Filter(unsigned int filterType) { _filterID = filterType; }
            ~Filter();

            std::vector<double> filting(std::vector<double> y);
            void SetAB(int sample_freq, int cutoff_freq);
            unsigned int getFilterID() { return _filterID; }
            void setFilterID(unsigned int filterID) { _filterID = filterID; }
            void applyingLowPass(int sample_freq, int cutoff_freq);
            void applyingHighPass(int sample_freq, int cutoff_freq);
            void applyingBandPass(int sample_freq, int cutoff_freq);
            void applyingBandStop(int sample_freq, int cutoff_freq);
        };
    }
}