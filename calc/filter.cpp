#include "filter.h"

std::vector<double> DigitalFilter::Calc::Filter::filting(std::vector<double> y) {
    std::vector<double> filtered(y.size(), 0.0);
    for (int i = 3; i < y.size(); i++)
    {
        filtered[i] = _a[1] * filtered[i - 1] + _a[2] * filtered[i - 2]
            + _b[0] * y[i] + _b[1] * y[i - 1] + _b[2] * y[i - 2];
    }

    return filtered;
}

void DigitalFilter::Calc::Filter::SetAB(int sample_freq, int cutoff_freq) {
	switch (_filterID) {
		case 0:
			applyingLowPass(sample_freq, cutoff_freq);
			break;
		case 1:
			applyingHighPass(sample_freq, cutoff_freq);
			break;
		case 2:
			applyingBandPass(sample_freq, cutoff_freq);
			break;
		case 3:
			applyingBandStop(sample_freq, cutoff_freq);
			break;
		default:
			break;
	}
}

void DigitalFilter::Calc::Filter::applyingLowPass(int sample_freq, int cutoff_freq) {
	std::vector<double> a(3);
	std::vector<double> b(3);

	double omega0 = 2 * M_PI * cutoff_freq;
	double dt = 1.0 / sample_freq;
	double alpha = omega0 * dt;

	double alphaSq = alpha * alpha;
	std::vector<double> beta = { 1, sqrt(2), 1 };
	double D = alphaSq * beta[0] + 2 * alpha * beta[1] + 4 * beta[2];

	b[0] = alphaSq / D;
	b[1] = 2 * b[0];
	b[2] = b[0];

	a[1] = -(2 * alphaSq * beta[0] - 8 * beta[2]) / D;
	a[2] = -(beta[0] * alphaSq - 2 * beta[1] * alpha + 4 * beta[2]) / D;

	_a = a; _b = b;
}

void DigitalFilter::Calc::Filter::applyingHighPass(int sample_freq, int cutoff_freq) {
	std::vector<double> a(3);
	std::vector<double> b(3);

	double omega0 = 2 * M_PI * cutoff_freq;
	double dt = 1.0 / sample_freq;

	double dtSq = dt * dt;
	std::vector<double> c = { omega0 * omega0, sqrt(2) * omega0, 1 };
	double E = c[0] * dtSq + 2 * c[1] * dt + 4 * c[2];

	b[0] = 4.0 / E;
	b[1] = -8.0 / E;
	b[2] = 4.0 / E;

	a[1] = -(2 * c[0] * dtSq - 8 * c[2]) / E;
	a[2] = -(c[0] * dtSq - 2 * c[1] * dt + 4 * c[2]) / E;

	_a = a; _b = b;
}

void DigitalFilter::Calc::Filter::applyingBandPass(int sample_freq, int cutoff_freq) {
	std::vector<double> a(3);
	std::vector<double> b(3);

	int band_width = 6;

	double omega0 = 2 * M_PI * cutoff_freq;
	double dt = 1.0 / sample_freq;
	double alpha = omega0 * dt;

	double domega = 2 * M_PI * band_width;
	double Q = omega0 / domega;
	double G = alpha * alpha + 2 * alpha / Q + 4;

	b[0] = 2 * alpha / (Q * G);
	b[1] = 0;
	b[2] = -(b[0]);

	a[1] = -(2 * pow(alpha, 2) - 8) / G;
	a[2] = -(pow(alpha, 2) - 2 * alpha / Q + 4) / G;

	_a = a; _b = b;
}

void DigitalFilter::Calc::Filter::applyingBandStop(int sample_freq, int cutoff_freq) {
	std::vector<double> a(3);
	std::vector<double> b(3);

	int band_width = 6;

	double omega0 = 2 * M_PI * cutoff_freq;
	double dt = 1.0 / sample_freq;
	double alpha = omega0 * dt;

	double domega = 2 * M_PI * band_width;
	double Q = omega0 / domega;
	double G = alpha * alpha + 2 * alpha / Q + 4;

	b[0] = (alpha * alpha + 4) / G;
	b[1] = (2 * alpha * alpha - 8) / G;
	b[2] = b[0];

	a[1] = -(2 * alpha * alpha - 8) / G;
	a[2] = -(alpha * alpha - 2 * alpha / Q + 4) / G;

	_a = a; _b = b;
}
