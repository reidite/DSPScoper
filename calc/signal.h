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

#define M_PI 3.14159265358979323846
#include <vector>
#include <cmath>
#include <random>

namespace DigitalFilter {
	namespace Calc {
		struct SignalInfo {
			double m_amp;
			double m_freq;
			double m_stddev;
		};

		class Signal {
		public:
			std::vector<SignalInfo> infos;
			std::vector<double> x;
			std::vector<double> y;

			Signal();
			Signal(double amp, double freq, double psi);
			
			void GenerateSignalData(int numOfSample);
		};
	}
}
