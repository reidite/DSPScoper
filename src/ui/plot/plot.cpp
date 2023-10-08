#include "plot.h"
UI::Plot::SignalPlot::SignalPlot(const wxColour &colour) : mpFXYVector(wxT("f(x) = A*sin(2*PI*Freq*x)"), mpALIGN_LEFT)
{
	/**
	 * Setting up resources on initializing time of the application.
	 *
	 * @param colour The chosen colour to draw the figure.
	 */
	wxPen drawingPen(colour, 2, wxPENSTYLE_SOLID);
	this->SetDrawOutsideMargins(true);
	this->SetContinuity(true);
	this->SetPen(drawingPen);
};

void UI::Plot::SignalPlot::DrawingSignalData(std::vector<double> x, std::vector<double> y)
{
	/**
	 * Drawing the assigned signal data.
	 *
	 * @param x The assigned x-axis signal data.
	 * @param y The assigned y-axis signal data.
	 */
	this->Clear();
	this->SetData(x, y);
}

void UI::Plot::SignalPlot::DrawingDFTData(std::vector<double> x, std::vector<double> y, int maxFreq)
{
	/**
	 * Drawing the assigned signal data after DFT.
	 *
	 * @param x The assigned x-axis signal data.
	 * @param y The assigned y-axis signal data.
	 * @param maxFreq The maximum frequency existing.
	 */
	double N = y.size();
	int K = x.size();

	std::complex<double> intSum;

	std::vector<std::complex<double>> output;
	output.reserve(K);

	for (int k = 0; k < K; k++)
	{
		intSum = std::complex<double>(0.0, 0.0);
		for (int n = 0; n < N; n++)
		{
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

UI::Plot::ATPlotWindow::ATPlotWindow(wxWindow *parent) : mpWindow(parent, -1, wxPoint(0, 0), wxSize(-1, -1), wxSUNKEN_BORDER)
{
	/**
	 * Setting up the properties for the plot window.
	 *
	 * @param parent Pointer to the parent that this UI component belongs.
	 */
	mpScaleX *timeAxis = new mpScaleX(wxT("Time"), mpALIGN_BORDER_BOTTOM, false, mpX_NORMAL);
	mpScaleY *amplitudeAxis = new mpScaleY(wxT("Amplitude"), mpALIGN_BORDER_LEFT, false);

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

void UI::Plot::ATPlotWindow::UpdatingBoundingBox(double sumAmp)
{
	/**
	 * Updating the new values for the viewing bounding box.
	 *
	 * @param maxAmp The sum of all signal amplitude existing.
	 */
	lf_minX = 0;
	lf_maxX = 1;
	lf_minY = -sumAmp - 0.2;
	lf_maxY = sumAmp + 0.2;
	this->Fit(lf_minX, lf_maxX, lf_minY, lf_maxY);
};

void UI::Plot::ATPlotWindow::OnFit(wxCommandEvent &event)
{
	this->Fit(lf_minX, lf_maxX, lf_minY, lf_maxY);
};

UI::Plot::MFPlotWindow::MFPlotWindow(wxWindow *parent) : mpWindow(parent, -1, wxPoint(0, 0), wxSize(-1, -1), wxSUNKEN_BORDER)
{
	/**
	 * Setting up the properties for the plot window.
	 *
	 * @param parent Pointer to the parent that this UI component belongs.
	 */
	mpScaleX *freqAxis = new mpScaleX(wxT("Frequency"), mpALIGN_BORDER_BOTTOM, false, mpX_NORMAL);
	mpScaleY *modulusAxis = new mpScaleY(wxT("Modulus"), mpALIGN_BORDER_LEFT, false);

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

void UI::Plot::MFPlotWindow::UpdatingBoundingBox(double maxAmp, double maxFreq)
{
	/**
	 * Updating the new values for the viewing bounding box.
	 *
	 * @param maxAmp The maximum amplitude of all signals existing.
	 * @param maxFreq The maximum frequency of all signals existing.
	 */
	lf_minX = 0;
	lf_maxX = maxFreq + 10;
	lf_minY = 0;
	lf_maxY = maxAmp / 2 + 0.1;
	this->Fit(lf_minX, lf_maxX, lf_minY, lf_maxY);
};

void UI::Plot::MFPlotWindow::OnFit(wxCommandEvent &event)
{
	this->Fit(lf_minX, lf_maxX, lf_minY, lf_maxY);
}