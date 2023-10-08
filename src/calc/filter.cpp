#include "filter.h"

Calc::Filter::Filter(unsigned int filterResponse) {
	/**
	* Constructs a new filter object with some default filter parameters.
	* 
	* @param filterResponse Chosen ID of the filter response.
	*/
	un_responseID = filterResponse;
	vec_lf_a = std::vector<double>(3, 1.0);
	vec_lf_b = std::vector<double>(3, 1.0);
}

std::vector<double> Calc::Filter::filting(std::vector<double> y, unsigned int filterType) {
	/**
	* Appling the settle filter to remove the unwanted frequencies
	*
	* @param y The y-axis input signal data.
	* @param filterType Chosen ID of the filter type.
	*/
    std::vector<double> filtered(y.size(), 0.0);
	switch (filterType) {
	case 0:
		for (int i = 3; i < y.size(); i++) {
			filtered[i] = vec_lf_a[1] * filtered[i - 1] + vec_lf_a[2] * filtered[i - 2]
				+ vec_lf_b[0] * y[i] + vec_lf_b[1] * y[i - 1] + vec_lf_b[2] * y[i - 2];
		}
		break;
	case 1:
		for (int i = 3; i < y.size(); i++) {
			filtered[i] = (1 * y[i] - 2 * y[i - 1] + 1 * y[i - 2]);
		}
		break;
	}
    
    return filtered;
}

void Calc::Filter::SetAB(int samplingRate, int cutoffFreq) {
	/**
	* Setting Alpha-Beta filter coefficients based on the current settle
	* properties.
	* 
	* @param samplingRate The rate at which the synthesized signal is sampled.
	* @param cutoffFreq Applied frequency for the digital filter.
	*/
	switch (un_responseID) {
		case 0:
			applyingLowPass(samplingRate, cutoffFreq);
			break;
		case 1:
			applyingHighPass(samplingRate, cutoffFreq);
			break;
		case 2:
			applyingBandPass(samplingRate, cutoffFreq);
			break;
		case 3:
			applyingBandStop(samplingRate, cutoffFreq);
			break;
		default:
			break;
	}
}

void Calc::Filter::applyingLowPass(int samplingRate, int cutoffFreq) {
	/**
	* Setting Alpha-Beta filter coefficients to perform Low-pass filter response.
	*
	* @param samplingRate The rate at which the synthesized signal is sampled.
	* @param cutoffFreq Applied frequency for the digital filter.
	*/
	double omega0 = 2 * M_PI * cutoffFreq;
	double dt = 1.0 / samplingRate;
	double alpha = omega0 * dt;

	double alphaSq = alpha * alpha;
	std::vector<double> beta = { 1, sqrt(2), 1 };
	double D = alphaSq * beta[0] + 2 * alpha * beta[1] + 4 * beta[2];

	vec_lf_b[0] = alphaSq / D;
	vec_lf_b[1] = 2 * vec_lf_b[0];
	vec_lf_b[2] = vec_lf_b[0];

	vec_lf_a[1] = -(2 * alphaSq * beta[0] - 8 * beta[2]) / D;
	vec_lf_a[2] = -(beta[0] * alphaSq - 2 * beta[1] * alpha + 4 * beta[2]) / D;
}

void Calc::Filter::applyingHighPass(int samplingRate, int cutoffFreq) {
	/**
	* Setting Alpha-Beta filter coefficients to perform High-pass filter response.
	*
	* @param samplingRate The rate at which the synthesized signal is sampled.
	* @param cutoffFreq Applied frequency for the digital filter.
	*/
	double omega0 = 2 * M_PI * cutoffFreq;
	double dt = 1.0 / samplingRate;

	double dtSq = dt * dt;
	std::vector<double> c = { omega0 * omega0, sqrt(2) * omega0, 1 };
	double E = c[0] * dtSq + 2 * c[1] * dt + 4 * c[2];

	vec_lf_b[0] = 4.0 / E;
	vec_lf_b[1] = -8.0 / E;
	vec_lf_b[2] = 4.0 / E;

	vec_lf_a[1] = -(2 * c[0] * dtSq - 8 * c[2]) / E;
	vec_lf_a[2] = -(c[0] * dtSq - 2 * c[1] * dt + 4 * c[2]) / E;
}

void Calc::Filter::applyingBandPass(int samplingRate, int cutoffFreq) {
	/**
	* Setting Alpha-Beta filter coefficients to perform Band-pass filter response.
	*
	* @param samplingRate The rate at which the synthesized signal is sampled.
	* @param cutoffFreq Applied frequency for the digital filter.
	*/
	int band_width = 6;

	double omega0 = 2 * M_PI * cutoffFreq;
	double dt = 1.0 / samplingRate;
	double alpha = omega0 * dt;

	double domega = 2 * M_PI * band_width;
	double Q = omega0 / domega;
	double G = alpha * alpha + 2 * alpha / Q + 4;

	vec_lf_b[0] = 2 * alpha / (Q * G);
	vec_lf_b[1] = 0;
	vec_lf_b[2] = -(vec_lf_b[0]);

	vec_lf_a[1] = -(2 * pow(alpha, 2) - 8) / G;
	vec_lf_a[2] = -(pow(alpha, 2) - 2 * alpha / Q + 4) / G;
}

void Calc::Filter::applyingBandStop(int samplingRate, int cutoffFreq) {
	/**
	* Setting Alpha-Beta filter coefficients to perform Band-stop filter response.
	*
	* @param samplingRate The rate at which the synthesized signal is sampled.
	* @param cutoffFreq Applied frequency for the digital filter.
	*/
	int band_width = 6;

	double omega0 = 2 * M_PI * cutoffFreq;
	double dt = 1.0 / samplingRate;
	double alpha = omega0 * dt;

	double domega = 2 * M_PI * band_width;
	double Q = omega0 / domega;
	double G = alpha * alpha + 2 * alpha / Q + 4;

	vec_lf_b[0] = (alpha * alpha + 4) / G;
	vec_lf_b[1] = (2 * alpha * alpha - 8) / G;
	vec_lf_b[2] = vec_lf_b[0];

	vec_lf_a[1] = -(2 * alpha * alpha - 8) / G;
	vec_lf_a[2] = -(alpha * alpha - 2 * alpha / Q + 4) / G;
}
