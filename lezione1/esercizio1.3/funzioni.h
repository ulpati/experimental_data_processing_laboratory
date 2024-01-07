#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cassert>

// test
void test_stat_func(void);

// punto 1
void letfile(size_t n, double *d, const char filename[]);

// punto 2
double fmedia(size_t n, double *d);
double fvarianza(size_t n, double *d, double media);

// punto 3
void copiavect(size_t n, double *d, double *dc);
void ordinavect(size_t n, double *dc);
double fmediana(size_t n, double *dc);

// punto 4
void stampa(double media, double varianza, double mediana);

// punto 5
void stampa(size_t n, double *dc, std::ofstream &f);