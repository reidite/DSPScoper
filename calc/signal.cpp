#include "signal.h"

DigitalFilter::Calc::Signal::Signal() {
	infos.push_back({ 5, 1, 0.1 });
	infos.push_back({ 50, 0.6, 0.1 });
	infos.push_back({ 80, 0.8, 0.1 });
}

DigitalFilter::Calc::Signal::Signal(double amp, double freq, double psi) {
	infos.push_back({ freq, amp, psi });
}

void DigitalFilter::Calc::Signal::GenerateSignalData(int numOfSample) {
	x.clear();
	y.clear();

	x = std::vector<double>(numOfSample, 0);
	y = std::vector<double>(numOfSample, 0);
	/*const double mean = 0.0;
	const double stddev_freq = m_psi;
	std::default_random_engine generator;
	std::normal_distribution<double> dist(mean, stddev_freq);*/
	for (int i = 0; i < numOfSample; i++) {
		x[i] = 1.0 / (numOfSample - 1) * i;
		y[i] = 0;
		for (Calc::SignalInfo info : infos) {
			y[i] += info.m_amp * sin(2 * M_PI * info.m_freq * x[i]);
		}
	}
}
