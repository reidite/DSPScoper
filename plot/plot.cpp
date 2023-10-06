#include "plot.h"
DigitalFilter::Plot::SignalPlot::SignalPlot(const wxColour& colour) : mpFXYVector(wxT("f(x) = A*sin(2*PI*Freq*x)"), mpALIGN_LEFT) {
	wxPen drawingPen(colour, 2, wxPENSTYLE_SOLID);
	this->SetDrawOutsideMargins(true);
	this->SetContinuity(true);
	this->SetPen(drawingPen);
};

void DigitalFilter::Plot::SignalPlot::DrawingSignalData(std::vector<double> x, std::vector<double> y) {
	this->Clear();
	this->SetData(x, y);
}

void DigitalFilter::Plot::SignalPlot::DrawingDFTData(std::vector<double> x, std::vector<double> y, int maxFreq) {
	double N = y.size();
	int K = x.size();

	std::complex<double> intSum;

	std::vector<std::complex<double>> output;
	output.reserve(K);

	for (int k = 0; k < K; k++) {
		intSum = std::complex<double>(0.0, 0.0);
		for (int n = 0; n < N; n++) {
			double realPart = cos((2 * M_PI / N) * k * n);
			double imagPart = sin((2 * M_PI / N) * k * n);

			std::complex<double> w(realPart, -imagPart);

			intSum += y[n] * w;
		}

		output.push_back(intSum);
	}

	std::vector<double> freqs;
	std::vector<double> modus;

	int dataPts = (maxFreq + 10 <= N) ? maxFreq + 10 : N;
	for (int i = 0; i < dataPts; i++)
	{
		freqs.push_back(i);
		modus.push_back(std::abs(output[i] / N));
	}

	this->SetData(freqs, modus);
}


DigitalFilter::Plot::ATPlotWindow::ATPlotWindow(wxWindow* parent) : mpWindow(parent, -1, wxPoint(0, 0), wxSize(-1, -1), wxSUNKEN_BORDER) {
	mpScaleX* timeAxis = new mpScaleX(wxT("Time"), mpALIGN_BORDER_BOTTOM, false, mpX_NORMAL);
	mpScaleY* amplitudeAxis = new mpScaleY(wxT("Amplitude"), mpALIGN_BORDER_LEFT, false);

	timeAxis->SetContinuity(true);
	amplitudeAxis->SetContinuity(true);

	timeAxis->SetDrawOutsideMargins(false);
	amplitudeAxis->SetDrawOutsideMargins(false);

	m_popmenu.Remove(mpID_CENTER);
	m_popmenu.Remove(mpID_LOCKASPECT);
	m_popmenu.Remove(mpID_HELP_MOUSE);

	this->EnableMousePanZoom(false);
	this->SetMargins(PLOT_MARGIN, PLOT_MARGIN, PLOT_MARGIN, PLOT_MARGIN);
	this->AddLayer(timeAxis);
	this->AddLayer(amplitudeAxis);
};

void DigitalFilter::Plot::ATPlotWindow::UpdatingBoundingBox(double maxAmp) {
	_minX = 0; _maxX = 1;
	_minY = -maxAmp - 0.2; _maxY = maxAmp + 0.2;
	this->Fit(_minX, _maxX, _minY, _maxY);
};

void DigitalFilter::Plot::ATPlotWindow::OnFit(wxCommandEvent& event) {
	this->Fit(_minX, _maxX, _minY, _maxY);
};


DigitalFilter::Plot::MFPlotWindow::MFPlotWindow(wxWindow* parent) : mpWindow(parent, -1, wxPoint(0, 0), wxSize(-1, -1), wxSUNKEN_BORDER) {
	mpScaleX* freqAxis = new mpScaleX(wxT("Frequency"), mpALIGN_BORDER_BOTTOM, false, mpX_NORMAL);
	mpScaleY* modulusAxis = new mpScaleY(wxT("Modulus"), mpALIGN_BORDER_LEFT, false);

	freqAxis->SetContinuity(true);
	modulusAxis->SetContinuity(true);

	freqAxis->SetDrawOutsideMargins(false);
	modulusAxis->SetDrawOutsideMargins(false);

	m_popmenu.Remove(mpID_CENTER);
	m_popmenu.Remove(mpID_LOCKASPECT);
	m_popmenu.Remove(mpID_HELP_MOUSE);

	this->EnableMousePanZoom(false);
	this->SetMargins(PLOT_MARGIN, PLOT_MARGIN, PLOT_MARGIN, PLOT_MARGIN);
	this->AddLayer(freqAxis);
	this->AddLayer(modulusAxis);
};

void DigitalFilter::Plot::MFPlotWindow::UpdatingBoundingBox(double maxAmp, double maxFreq) {
	_minX = 0; _maxX = maxFreq + 10;
	_minY = 0; _maxY = maxAmp / 2 + 0.1;
	this->Fit(_minX, _maxX, _minY, _maxY);
};

void DigitalFilter::Plot::MFPlotWindow::OnFit(wxCommandEvent& event) {
	this->Fit(_minX, _maxX, _minY, _maxY);
}