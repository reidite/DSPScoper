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

	std::default_random_engine gen;

	for (int i = 0; i < numOfSample; i++) {
		x[i] = 1.0 / (numOfSample - 1) * i;
		y[i] = 0;
		for (Calc::SignalInfo info : infos) {
			if (info.m_stddev > 0) {
				std::normal_distribution<double> dist(info.m_freq, info.m_stddev);
				y[i] += info.m_amp * sin(2 * M_PI * dist(gen) * x[i]);
			}
			else y[i] += info.m_amp * sin(2 * M_PI * info.m_freq * x[i]);
		}
	}
}

double DigitalFilter::Calc::Signal::GetMaxAmp() {
	double result = 0.0;
	for (int i = 0; i < infos.size(); i++)
		result += infos[i].m_amp;
	return result;
}

double DigitalFilter::Calc::Signal::GetMaxFreq() {
	double result = INT_MIN;
	for (int i = 0; i < infos.size(); i++)
		result = std::max(result, infos[i].m_freq);
	return result;
}