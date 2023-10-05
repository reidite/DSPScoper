#include "signal.h"

DigitalFilter::Calc::Signal::Signal() {
	infos.push_back({ 1.0, 5, 0.10 });
	infos.push_back({ 0.8, 35, 0.15 });
	infos.push_back({ 0.6, 50, 0.25 });
	infos.push_back({ 0.4, 80, 0.30 });
}

DigitalFilter::Calc::Signal::Signal(double amp, double freq, double psi) {
	infos.push_back({ freq, amp, psi });
}

void DigitalFilter::Calc::Signal::GenerateSignalData(int numOfSample) {
	x.clear();
	y.clear();

	x = std::vector<double>(numOfSample, 0);
	y = std::vector<double>(numOfSample, 0);
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::vector<std::normal_distribution<double>> dists(infos.size());
	for (int i = 0; i < infos.size(); i++) {
		if (infos[i].m_stddev > 0) {
			dists[i] = std::normal_distribution<double>(infos[i].m_freq, infos[i].m_stddev);
		}
	}
	for (int i = 0; i < numOfSample; i++) {
		x[i] = 1.0 / (numOfSample - 1) * i;
		y[i] = 0;
		for (int j = 0; j < infos.size(); j++) {
			if (infos[j].m_stddev > 0) {
				y[i] += infos[j].m_amp * sin(2 * M_PI * dists[j](gen) * x[i]);
			}
			else y[i] += infos[j].m_amp * sin(2 * M_PI * infos[j].m_freq * x[i]);
		}
	}
}