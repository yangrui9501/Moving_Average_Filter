#pragma once

// 2022-01-05
// Moving Average Filter

class MOVING_AVERAGE_FILTER
{
public:
    double *u_in; // current and past input history
    double u_out; // filtered singal
    int p;        // window size

    // Algorithm:
    void Init(int _window_size);
    void Update(double *measured_data, double *filtered_data);
};
