#pragma once
#include "mathplot.h"
#include <complex>
#include <vector>
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
			Signal(double freq, double amp, double psi) : mpFXYVector(wxT("f(x) = sin(x) + psi"), mpALIGN_LEFT) {
				m_freq = freq; m_amp = amp;
				m_psi = psi;
				m_drawOutsideMargins = false;
			};

			Signal(Signal* origin) : mpFXYVector(wxT("f(x) = sin(x) + psi"), mpALIGN_LEFT) {
				m_freq = origin->m_freq; m_amp = origin->m_amp;
				m_psi = origin->m_psi;
				m_drawOutsideMargins = false;
			};

			void SetATSignalData(int sample) {
				double dx = 1.0 / sample;
				for (double i = 0.0; i <= 1.0; i += dx) {
					x.push_back(i);
					y.push_back(sin(2 * M_PI * 5.0 * i)
						+ 0.6 * sin(2 * M_PI * 50.0 * i)
						+ 0.8 * sin(2 * M_PI * 80.0 * i));
				}
				this->SetData(x, y);
			};

			void SetMFSignalData(Signal* sample) {
				int N = sample->y.size();
				int K = N;

				std::complex<double> intSum;
				std::vector<std::complex<double>> output;
				output.reserve(K);

				for (int k = 0; k < K; k++) {
					intSum = std::complex<double>(0.0, 0.0);

					for (int n = 0; n < N; n++) {
						double realPart = cos((2 * M_PI / N) * k * n);
						double imagPart = sin((2 * M_PI / N) * k * n);

						std::complex<double> w(realPart, -imagPart);

						intSum += sample->y[n] * w;
					}

					output.push_back(intSum);	
				}
				int j = sample->x.size();
				for (int n = 0; n < N; n++) {
					x.push_back(n);
				}

				for (auto& ii : output) {
					ii = ii / static_cast<double>(j);
					y.push_back(std::abs(ii));
				}

				this->SetData(x, y);
			};

		};
	}
}
