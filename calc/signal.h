#define M_PI 3.14159265358979323846
#include <complex>
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
