#include "signal.h"
DigitalFilter::Calc::Signal::Signal(double freq, double amp, double psi) : mpFXYVector(wxT("f(x) = sin(x) + psi"), mpALIGN_LEFT) {
	m_freq = freq; m_amp = amp;
	m_psi = psi;
	m_drawOutsideMargins = false;
};

DigitalFilter::Calc::Signal::Signal(Signal* origin) : mpFXYVector(wxT("f(x) = sin(x) + psi"), mpALIGN_LEFT) {
	m_freq = origin->m_freq; m_amp = origin->m_amp;
	m_psi = origin->m_psi;
	m_drawOutsideMargins = false;
};

void DigitalFilter::Calc::Signal::SetATSignalData(int sample) {
	double dx = 1.0 / sample;
	for (double i = 0.0; i <= 1.0; i += dx) {
		x.push_back(i);
		y.push_back(m_amp * (sin(2 * M_PI * 5.0 * i)
								+ 0.6 * sin(2 * M_PI * 50.0 * i)
								+ 0.8 * sin(2 * M_PI * 80.0 * i)));
	}
	this->SetData(x, y);
};

void DigitalFilter::Calc::Signal::SetMFSignalData(DigitalFilter::Calc::Signal* sample) {
	int N = sample->x.size();
	std::vector<double> diff(N - 1, 0);

	for (int i = 0; i < N - 1; i++)
		diff[i] = sample->y[i + 1] - sample->y[i];

	for (int i = 0; i < 5 * N; i++)


		this->SetData(x, y);
};