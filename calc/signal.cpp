#include "signal.h"

DigitalFilter::Calc::Signal::Signal(Signal* origin) : mpFXYVector(wxT("f(x) = sin(x) + psi"), mpALIGN_LEFT) {
	m_freq = origin->m_freq; m_amp = origin->m_amp;
	m_psi = origin->m_psi; numsOfPts = origin->numsOfPts;

	m_drawOutsideMargins = true;
};

DigitalFilter::Calc::Signal::Signal(double freq, double amp, double psi, int num) : mpFXYVector(wxT("f(x) = sin(x) + psi"), mpALIGN_LEFT) {
	m_freq = freq; m_amp = amp;
	m_psi = psi; numsOfPts = num;

	x = std::vector<double>(numsOfPts, 0);
	y = std::vector<double>(numsOfPts, 0);

	m_drawOutsideMargins = true;
};

void DigitalFilter::Calc::Signal::SetATSignalData() {
	const double mean = 0.0;
	const double stddev_freq = m_psi;
	std::default_random_engine generator;
	std::normal_distribution<double> dist(mean, stddev_freq);

	for (int i = 0; i < numsOfPts; i++) {
		x[i] = 1.0 / (numsOfPts - 1) * i;
		y[i] = m_amp * sin(2 * M_PI * m_freq * x[i])
					+ m_amp * dist(generator) * sin(2 * M_PI * m_freq * (1 - dist(generator)) * x[i])
					+ m_amp * dist(generator) * sin(2 * M_PI * m_freq * (1 - dist(generator)) * x[i]);
	}
	this->SetData(x, y);
};

void DigitalFilter::Calc::Signal::SetMFSignalData(DigitalFilter::Calc::Signal* sample) {
	int N = sample->y.size();
	int K = static_cast<int>(m_freq);

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

	std::vector<double> freqs;
	std::vector<double> modus;

	for (int n = 0; n < K; n++)
	{
		freqs.push_back(n);
	}

	for (auto& ii : output)
	{
		ii = ii / static_cast<double>(N);
		modus.push_back(std::abs(ii));
	}

	this->SetData(freqs, modus);
};