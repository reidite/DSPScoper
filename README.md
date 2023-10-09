# DSPScoper
DSPScoper is a simple visualize tool for some digital filter algorithms.

![alt text](https://github.com/reidite/wxwidgets-digital-filters/blob/master/doc/img.JPG?raw=true)


Author: __Vincent Nguyen__

## Table of Contents

- [Introduction](#introduction)
- [Dependencies](#dependencies)
- [Compilation](#compilation)
- [Usage](#usage)
- [Citation](#citation)
- [Issues](#issues)
- [Changelog](#changelog)

### Introduction



A cross-platform application nicely visualizes and computes coefficients for some sequential signal digital filters. Initial testing of this code was on Windows but will work on any other Linux/Windows/Mac machine with little effort.

### Dependencies

*  [wxWidgets](https://github.com/wxWidgets/wxWidgets) for creating cross-platform application.

### Compilation

__Linux__

If you compile this repository on Linux, do the following in the project directory:

    $ mkdir build
    $ cd build
    $ ../configure
    $ make
    $ sudo make install


__Windows__

If you compile this repository on Windows, do the following in the project directory:

__MacOS__

If you compile this repository on MacOS, do the following in the project directory:


### Usage

* __Filter Control__
    * `Filter Order:` In signal processing, the filter order refers to the number of reactive components, such as capacitors and inductors, in the filter circuit. A first-order filter has one reactive component, while a second-order filter has two reactive components. Generally, higher-order filters have steeper roll-off rates, meaning they can more effectively attenuate unwanted frequencies.
    * `Filter Type:` In signal processing, there are two main types of filters: IIR (Infinite Impulse Response) and FIR (Finite Impulse Response).
        * __IIR__ filters use feedback, which means that the output of the filter is fed back into the input. They can have an infinite number of coefficients and can achieve a very sharp transition between the passband and stopband. However, they can be unstable and may introduce phase distortion.
        * __FIR__ filters, on the other hand, have no feedback and only use feedforward. They are always stable and have linear phase response, which makes them useful for applications such as audio processing. However, they require more coefficients to achieve the same level of sharpness as an IIR filter.
    * `Filter Class:` In signal processing, there are several classes of filters used to achieve different filtering characteristics.
        * __Butterworth__: A Butterworth filter has a maximally flat response in the passband and a monotonic roll-off in the stopband. It is commonly used in audio applications.
        * __Chebyshev__: A Chebyshev filter has a steeper roll-off than a Butterworth filter, but with some ripple in the passband. It is often used in applications where a sharp transition between the passband and stopband is required.
        * __Elliptic__: An elliptic filter has the steepest roll-off of any filter class, but with ripples in both the passband and stopband. It is used when a very sharp transition is required.
        * __Bessel__: A Bessel filter has a maximally flat phase response, which makes it useful in applications where preserving the phase relationship between different frequencies is important.
        * __Gaussian__: A Gaussian filter has a bell-shaped response curve and is used for smoothing and noise reduction.
        * __Legendre__: A Legendre filter has a maximally flat response in the passband, but with ripples in the stopband. It is used when a maximally flat passband response is required.
        * __Linkwitz-Riley__: A Linkwitz-Riley filter is a type of crossover filter used in audio applications to split a signal into two or more frequency bands. It has a flat response at the crossover frequency and a steep roll-off on either side.
    * `Filter Response:` In signal processing, there are four main types of filter responses:
        * __Low-pass__: A low-pass filter allows low-frequency signals to pass through while attenuating high-frequency signals. It is used to remove high-frequency noise from a signal or to isolate the low-frequency components of a signal.
        * __High-pass__: A high-pass filter allows high-frequency signals to pass through while attenuating low-frequency signals. It is used to remove low-frequency noise from a signal or to isolate the high-frequency components of a signal.
        * __Band-pass__: A band-pass filter allows a specific range of frequencies, called the passband, to pass through while attenuating frequencies outside the passband. It is used to isolate a specific frequency range in a signal.
        * __Band-stop__: A band-stop filter, also known as a notch filter, attenuates a specific range of frequencies, called the stopband, while allowing frequencies outside the stopband to pass through. It is used to remove a specific frequency range from a signal.
    * `Applied Frequency:` The applied frequency for a digital filter refers to the frequency of the input signal that is being filtered. 

* __Signal Control__
    * __Table of Signal Infomation__ is a component typically including various details about the observed signals, such as:
        * `Amp:` The magnitude or strength of the signal.
        * `Freq:` The frequency or range of frequencies present in the signal.
        * `Stddev:` The measurement of the amount of variation or dispersion in the frequency of a typical signal.
    * __Sampling Rate__ is the rate at which the synthesized signal is sampled. The Nyquist-Shannon sampling theorem states that the sampling rate must be at least twice the highest frequency component of the input signal in order to avoid aliasing. Therefore, the applied frequency for a digital filter is limited by the sampling rate and the characteristics of the filter itself.

### Citation

* A. V. Oppenheim and R. W. Schafer, Discrete-Time Signal Processing, 3rd ed. Upper Saddle River, NJ: Prentice Hall, 2010.

* S. K. Mitra, Digital Signal Processing: A Computer-Based Approach, 4th ed. New York: McGraw-Hill Education, 2011.

* J. G. Proakis and D. G. Manolakis, Digital Signal Processing: Principles, Algorithms, and Applications, 4th ed. Upper Saddle River, NJ: Prentice Hall, 2006.

* R. J. Schilling and S. L. Harris, Fundamentals of Digital Signal Processing Using MATLAB, 3rd ed. Belmont, CA: Thomson Higher Education, 2008.

* A. Antoniou, Digital Signal Processing: Signals, Systems, and Filters, 2nd ed. New York: McGraw-Hill Education, 2005.

### Issues

* There are lots of classes of filtes not implemented, it's necessary to allocate more resources or seek additional help to implement the missing filters.

* There are lots of types of plots not implemented, it may be necessary to redesign the layout of the UI so that it could support visualizing more plots.

* The functionality of the plot interaction is unpleasant and requires reimplementation.