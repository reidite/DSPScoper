#include "signal.h"

DSP::Calc::Signal::Signal() {
	/**
	* Constructs a new signal object with some default signal metadata.
	*/
	vec_infos = std::vector<SignalInfo>({{ 1.0, 05, 0.10 },
									{ 0.8, 35, 0.15 },
									{ 0.6, 50, 0.25 },
									{ 0.4, 80, 0.30 } });
}

DSP::Calc::Signal::~Signal() {
	/**
	* Destroys the signal object and frees any allocated resources.
	*/
}

DSP::Calc::Signal::Signal(double amp, double freq, double std) {
	/**
	* Constructs a new signal object with a assigned signal metadata.
	* 
	* @param amp Amplitude of the assigned signal.
	* @param freq Frequency of the assigned signal.
	* @param std Stdddev of the assigned signal.
	*/
	vec_infos.push_back({ freq, amp, std });
}

void DSP::Calc::Signal::SynthesizeSignalData(int numOfSample) {
	/**
	* Generates simulated digital signal data based on the concept of
	* Gaussian random distribution.
	* 
	* @param numOfSample Sampling rate of the synthesized signal.
	*/
	vec_lf_x.clear();
	vec_lf_y.clear();

	vec_lf_x = std::vector<double>(numOfSample, 0);
	vec_lf_y = std::vector<double>(numOfSample, 0);
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::vector<std::normal_distribution<double>> dists(vec_infos.size());
	for (int i = 0; i < vec_infos.size(); i++) {
		if (vec_infos[i].lf_stddev > 0) {
			dists[i] = std::normal_distribution<double>(vec_infos[i].lf_freq, vec_infos[i].lf_stddev);
		}
	}
	for (int i = 0; i < numOfSample; i++) {
		vec_lf_x[i] = 1.0 / (numOfSample - 1) * i;
		vec_lf_y[i] = 0;
		for (int j = 0; j < vec_infos.size(); j++) {
			if (vec_infos[j].lf_stddev > 0) {
				vec_lf_y[i] += vec_infos[j].lf_amp * sin(2 * M_PI * dists[j](gen) * vec_lf_x[i]);
			}
			else vec_lf_y[i] += vec_infos[j].lf_amp * sin(2 * M_PI * vec_infos[j].lf_freq * vec_lf_x[i]);
		}
	}
}