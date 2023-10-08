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

//---------------------------------------------------------------------------
// Filter
//---------------------------------------------------------------------------

#pragma once
#define M_PI 3.14159265358979323846
#include <thread>
#include <vector>
#include "math.h"

namespace Calc
{
    class Filter
    {
        /** A class contains properties and methods that are relevant for
         *   performing various filter operations.
         */
    private:
        //!< Alpha-Beta filter coefficients
        std::vector<double> vec_lf_a;
        std::vector<double> vec_lf_b;

    protected:
        //!< ID presenting the filter type
        unsigned int un_filterID;
        //!< ID presenting the filter response
        unsigned int un_responseID;

    public:
        Filter(unsigned int filterResponse);
        ~Filter();

        //!< Applying a digital filter to a signal.
        std::vector<double> filting(std::vector<double> y, unsigned int filterType);
        //!< Setting Alpha-Beta filter coefficients.
        void SetAB(int samplingRate, int cutoffFreq);
        //!< Setting ID of filter response.
        void setResponeID(unsigned int filterResponse) { un_responseID = filterResponse; }
        //!< Applying Low-pass response.
        void applyingLowPass(int samplingRate, int cutoffFreq);
        //!< Applying High-pass response.
        void applyingHighPass(int samplingRate, int cutoffFreq);
        //!< Applying Band-pass response.
        void applyingBandPass(int samplingRate, int cutoffFreq);
        //!< Applying Band-stop response.
        void applyingBandStop(int samplingRate, int cutoffFreq);
    };
}
