#include "signal.h"

DigitalFilter::Calc::Signal::Signal() {
	infos.push_back({ 1.0, 5, 0.10 });
	infos.push_back({ 0.6, 50, 0.15 });
	infos.push_back({ 0.8, 80, 0.30 });
}

DigitalFilter::Calc::Signal::Signal(double amp, double freq, double psi) {
	infos.push_back({ freq, amp, psi });
}

void DigitalFilter::Calc::Signal::GenerateSignalData(int numOfSample) {
	x.clear();
	y.clear();

	x = std::vector<double>(numOfSample, 0);
	y = std::vector<double>(numOfSample, 0);

	std::default_random_engine gen;

	for (int i = 0; i < numOfSample; i++) {
		x[i] = 1.0 / (numOfSample - 1) * i;
		y[i] = 0;
		for (Calc::SignalInfo info : infos) {
			std::normal_distribution<double> dist(info.m_freq, info.m_stddev);
			y[i] += info.m_amp * sin(2 * M_PI * dist(gen) * x[i]);
		}
	}
}
