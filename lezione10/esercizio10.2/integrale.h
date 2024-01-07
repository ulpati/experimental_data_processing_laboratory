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

double error_slope(unsigned int *steps, double *errors, int dim) {
        double deltax {log10(steps[dim-1]) - log10(steps[0])};
        double deltay {log10(errors[dim-1]) - log10(errors[0])};
        return deltay / deltax;
}

// per esercizio7.1 simpson

double simpson(double f(double), double a, double b, size_t n) {
    size_t truen {n};
    if (n%2 != 0) {
        truen++;
    }

    double h {(b - a) / truen};
    double acc {1./3. * (f(a) + f(b))};
    for(size_t i{1}; i < truen; i++)  acc += 2./3. * (double)(1 + i%2) * f(a + (double)(i) * h);

    return acc * h;
}

// per esercizio7.2. trapezoidi
double trapezoidi( double f(double), double a, double b, unsigned int n ){
	double h {(b - a) / (n)};
	double sum{(f(a) + f(b))/ 2.};
	for ( size_t k{1}; k < n; k++ )
	sum += f(a + h*k);

	return sum * h;
}

// trapezoidi con precisione fissata
double trapezoidi(double f(double), double a, double b, double precisione) {
	size_t n{2};
	double h {(b - a) /(n)};
	double sum {(f(a) + f(b))/ 2. + f((a + b)/ 2.)};
	double newint {sum * h}, oldint;

	while (true){
		oldint = newint;
		n *= 2;
		h/= 2;

		for ( size_t k{1}; k < n; k += 2 ) //itera solo dispari
			sum += f(a + h*k);
		newint = sum * h;
		if (4./3 * fabs(newint-oldint) < precisione) break;
	}

	return newint;
}

// integrale della media
double intmean(double f(double), double a, double b, unsigned int n, RandomGen &myGen) {
	double sum {0};
	
	for(unsigned int i = 0; i < n; i++) sum += f(myGen.Unif(a,b));

	return (b - a) * sum / n;
}

// integrale hit-or-miss
double inthm(double f(double), double a, double b, double fmax, unsigned int n, RandomGen &myGen) {
	unsigned int hits {0};
	double x, y;

	for(unsigned int i = 0; i < n; i++) {
		x = myGen.Unif(a, b);
		y = myGen.Unif(0, fmax);
		if (y < f(x)) hits++;
	}

	return (b - a) * fmax * (double(hits) / double(n));
}