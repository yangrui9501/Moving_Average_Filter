# Moving Average Filter

## Introduction
* Release: 2022-04-03
* This library performs the moving average filtering with a user-defined window size p.
* *Algorithm*
    $$ 
    y_f[k] = \frac{1}{p}\left(y[k] + y[k-1] + \cdots + y[k-p+1]\right)
    $$
    where $y[k]$ is the measured data in time index $k$ and $y_f[k]$ is the corresponding filtered data.
## How to use?
* Initialization
```cpp
MOVING_AVERAGE_FILTER MAF; // Define the MAF object
MAF.Init(10); // Initialize MAF
```
* Filter Update
```cpp
double data_m; // Measured data, it will be updated by your program
double data_f; // Filtered data that we want

/* < ... something here ... > */

MAF.Update(&data_m, &data_f); // Update MAF
// data_f = MAF.Update(data_m); // Or this
```