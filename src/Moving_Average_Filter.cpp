#include "Moving_Average_Filter.h"

// Initialization
void MOVING_AVERAGE_FILTER::Init(int _window_size)
{
    p = _window_size;
    u_in = new double[p]; // dynamic array

    for (int i = 0; i < p; i++)
    {
        u_in[i] = 0.0;
    }
}

// Moving Average Filter (MAF)
void MOVING_AVERAGE_FILTER::Update(double *measured_data, double *filtered_data)
{
    u_in[0] = *measured_data;

    u_out = 0.0;
    for (int i = 0; i < p; i++)
    {
        u_out += u_in[i];
    }
    *filtered_data = u_out / (double)(p);

    for (int i = 1; i < p; i++)
    {
        u_in[p - i] = u_in[p - i - 1];
    }
}
