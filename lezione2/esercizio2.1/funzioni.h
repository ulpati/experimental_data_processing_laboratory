#pragma once

#include "vettore.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cassert>

// test
void test_stat_func(void);

// punto 1
void letfile(Vettore& v, const char filename[]);

// punto 2
double fmedia(const Vettore& v);
double fvarianza(const Vettore& v, double media);

// punto 3
void ordinavect(Vettore& vc);
double fmediana(const Vettore& vc);

// punto 4
void stampa(double media, double varianza, double mediana);

// punto 5
void stampa(const Vettore& vc, std::ofstream &f);