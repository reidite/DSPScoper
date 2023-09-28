#pragma once
#include "mathplot.h"
#include <complex>
#include <vector>
#include <ctime>
namespace DigitalFilter {
	namespace Calc {
		class Signal : public mpFXYVector {
		private:

		protected:
			double m_freq;
			double m_amp;
			double m_psi;
			std::vector<double> x;
			std::vector<double> y;

		public:
			Signal(double freq, double amp, double psi);
			Signal(Signal* origin);

			void SetATSignalData(int sample);
			void SetMFSignalData(Signal* sample);
		};
	}
}
