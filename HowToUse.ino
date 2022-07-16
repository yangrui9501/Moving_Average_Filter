#include <Arduino.h>
#include "Moving_Average_Filter.h"

const double T = 0.001; // Sample interval

MOVING_AVERAGE_FILTER MAF;

double t;
double data;
double data_n;
double data_m;
double data_f;

void setup()
{
    Serial.begin(115200);
    while (!Serial) {};
    
    const int _win_size = 10;
    MAF.Init(_win_size);

    randomSeed(1);
}

void loop()
{
    static int idx;
    
    t = (double)(idx) * T;
    data = sin(2.0 * PI * 1.0 * t);
    data_n = (double)(random(-1000, 1000)) / 1000.0;
    data_m = data + data_n;

    data_f = MAF.Update(data_m);

    /* Print Measured, Filtered, and Ground-Truth Data */
    Serial.println(String() + data_m + " " + data_f + " " + data);
    Serial.flush();
    
    idx++;
    
    delay(1);
}

