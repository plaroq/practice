/*
 * Functions to calculate mean and standard deviation.
 */

#include <math.h>
#include "statistics.h"

// Compute mean from sum and count
double mean (const double sum, const int count){
    double result;
    result = sum / count;
    return (result);
}

// Compute sample standard deviation from sum, sum of squares, and count
double ssdev (const double sum, const double sumsq, const int count){
    double sigma;
    sigma = sqrt(((count*sumsq)-(sum*sum))/(count*(count-1)));
    return (sigma);
}