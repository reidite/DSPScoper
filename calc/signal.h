#include "../plot/mathplot.h"
#include "filter.h"
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
			
			void SetX(std::vector<double> val) { x = val; }
			void SetY(std::vector<double> val) { y = val; }
			void SetFiltedData() { this->SetData(x, y); };
			std::vector<double> GetX() { return x; }
			std::vector<double> GetY() { return y; }
			void SetATSignalData(int sample);
			void SetMFSignalData(Signal* sample);
		};
	}
}
