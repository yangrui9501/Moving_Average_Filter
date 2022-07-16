#pragma once

#include <Arduino.h>
// 2022-01-05
// Moving Average Filter

class MOVING_AVERAGE_FILTER
{
public:
    // Algorithm:
    void Init(int _window_size);
    void Update(double *measured_data, double *filtered_data);
    const double& Update(const double &measured_data);
    
protected:
    double *u_in; // current and past input history
    double u_out; // filtered signal
    int p;        // window size
};
