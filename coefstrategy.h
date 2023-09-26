#define _USE_MATH_DEFINES
#include <vector>
#include <tuple>
#include "math.h"

namespace DigitalFilter {
	namespace Calc {
		class CoefStrategy {
		public:
			virtual ~CoefStrategy() = default;
			virtual std::tuple<std::vector<double>, std::vector<double>> coefCalc(int sample_freq, int cutoff_freq) = 0;
		};

		class Context {
		private:
			CoefStrategy* strategy;

		public:
			Context(CoefStrategy* strategy);
			std::tuple<std::vector<double>, std::vector<double>> coefCalc(int sample_freq, int cutoff_freq);
		};

		class lowpass : public CoefStrategy {
		public:
			std::tuple<std::vector<double>, std::vector<double>> coefCalc(int sample_freq, int cutoff_freq) override;
		};

		class highpass : public CoefStrategy {
		public:
			std::tuple<std::vector<double>, std::vector<double>> coefCalc(int sample_freq, int cutoff_freq) override;
		};

		class bandpass : public CoefStrategy {
		public:
			std::tuple<std::vector<double>, std::vector<double>> coefCalc(int sample_freq, int cutoff_freq) override;
		};

		class bandstop : public CoefStrategy {
		public:
			std::tuple<std::vector<double>, std::vector<double>> coefCalc(int sample_freq, int cutoff_freq) override;
		};
	}
}