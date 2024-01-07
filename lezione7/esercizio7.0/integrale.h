#pragma once

#include <cmath>
#include "../fmtlib.h"

// per esercizio7.0 midpoint

double midpoint ( double f(double), double a, double b, size_t n ){
    double h { (b - a) / n };
    double sum {0};
    for ( size_t k{0}; k < n; k++ )
        sum += f( a + (k + 0.5) * h );
    return h * sum;
}

double compute_errors(double fn, int dim, double val) {
    return fabs(fn - val);    
}

double error_slope(int *steps, double *errors, int dim) {
        double deltax {log10(steps[dim-1]) - log10(steps[0])};
        double deltay {log10(errors[dim-1]) - log10(errors[0])};
        return deltay / deltax;
}