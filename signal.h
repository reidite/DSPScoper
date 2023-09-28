#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include "mathplot.h"
#include <complex>
#include <vector>
#include <cmath>
#include <ctime>
namespace DigitalFilter {
	namespace Calc {
		class Signal : public mpFXYVector {

		protected:
			double m_freq;
			double m_amp;
			double m_psi;
			std::vector<double> x;
			std::vector<double> y;

		public:
			Signal(Signal* origin);
			Signal(double freq, double amp, double psi);
			

			void SetATSignalData(int sample);
			void SetMFSignalData(Signal* sample);
		};
	}
}
