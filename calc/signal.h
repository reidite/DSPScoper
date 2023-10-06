/////////////////////////////////////////////////////////////////////////////
// Name:            signal.cpp
// Purpose:         Definition for the class Signal providing functionality 
//					related to synthesizing and handling signals.
// Author:          Vincent Nguyen
// Maintainer:      Vincent Nguyen
// Contributors:    N/A
// Created:         25/09/2023
// Last edit:       06/10/2023
// Copyright:       Anyone
// Licence:         GPL-3.0 license
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
// Signal
//---------------------------------------------------------------------------

#pragma once
#define M_PI 3.14159265358979323846
#include <vector>
#include <cmath>
#include <random>

namespace DSP {
	namespace Calc {
		// Signal metadata
		struct SignalInfo {
			double lf_amp;
			double lf_freq;
			double lf_stddev;
		};

		class Signal {
		/** A class contains various properties and methods that are 
		*	relevant to the representation and processing of digital signals.
		*/
		public:
			//!< Relevant metadata associated with the signal.
			std::vector<SignalInfo> vec_infos;
			//!< X-axis data representing a signal.
			std::vector<double> vec_lf_x;
			//!< Y-axis data representing a signal.
			std::vector<double> vec_lf_y;

			Signal();
			Signal(double amp, double freq, double std);

			~Signal();
			
			//!< Amplitude-Y = f(Time-X) signal data generator.
			void SynthesizeSignalData(int numOfSample);
		};
	}
}
