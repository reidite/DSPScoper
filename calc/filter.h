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
            
        public:
            Filter(unsigned int filterType);
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