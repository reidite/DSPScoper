#pragma once
#include "Filter.h"

DigitalFilter::Calc::Filter::Filter() {
}

void DigitalFilter::Calc::Filter::test_signal(int sample, std::vector<double> a, std::vector<double> b)
{
    std::vector<double> tt, yy;

    double dt = 1.0 / sample;
    double y;

    for (double t = 0.0; t <= 1.0; t = t + dt)
    {
        y = sin(2 * M_PI * 5.0 * t)
            + 0.6 * sin(2 * M_PI * 50.0 * t)
            + 0.8 * sin(2 * M_PI * 80.0 * t);

        tt.push_back(t);
        yy.push_back(y);

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    //emit generated(tt, yy);

    std::vector<double> yy_filtered(yy.size(), 0.0);

    for (int i = 3; i < yy.size(); i++)
    {
        yy_filtered[i] = a[1] * yy_filtered[i - 1] + a[2] * yy_filtered[i - 2]
            + b[0] * yy[i] + b[1] * yy[i - 1] + b[2] * yy[i - 2];
    }

    //emit finishedFilter(tt, yy_filtered);
}