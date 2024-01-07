#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include "vettore.h"

// punto 1
template <typename T> void letfile(Vettore<T> &v, const char filename[]) {
	std::ifstream f;
	T data {0};
	f.open(filename);
	for (size_t i{0}; i < v.GetN(); i++) {
		f >> data;
		v.SetComponent(i, data);
	}

	assert(f && "Errore apertura file\n");
	
	f.close();
}

// punto 2
template <typename T> T fmedia (const Vettore<T> & v) {
	T sommam {0};
	for (size_t i{0}; i < v.GetN(); i++) {
		sommam = sommam + v.GetComponent(i);
	}
  return sommam / v.GetN();
}

template <typename T> T fvarianza (const Vettore<T> & v, T media) {
	T sommav {0};
	for (size_t i{0}; i < v.GetN(); i++) {
		sommav = sommav + pow(v.GetComponent(i) - media, 2);
	}
	return sommav / v.GetN();
}

//punto 3
template <typename T> void ordinavect (Vettore<T> & v) {
	int imin {0};
	T min {0};
	for (size_t j{0}; j < v.GetN(); j++) {
		imin = j;
		min = v.GetComponent(imin);
		for (size_t i{j+1}; i < v.GetN(); i++) {
			if (v.GetComponent(i) < min) {
				min = v.GetComponent(i);
				imin = i;		
			}
		}
	double temp {v.GetComponent(j)};
	v.SetComponent(j, v.GetComponent(imin));
	v.SetComponent(imin, temp);
	}
}

template <typename T> T fmediana (const Vettore<T> & v) {
	if (v.GetN()%2 == 0) {
		return (v.GetComponent(v.GetN()/2 - 1) + v.GetComponent(v.GetN()/2)) / 2;
	} else {
		return v.GetComponent(v.GetN()/2);
	}
}

//punto 4
template <typename T> void stampa (T media, T varianza, T mediana) {
	std::cout << "Media = " << media << std::endl;
	std::cout << "Varianza = " << varianza << std::endl;
	std::cout << "Mediana = " << mediana << std::endl;
}

//punto 5
template <typename T> void stampa (const Vettore<T> & v, std::ofstream &f) {
	for (size_t i{0}; i < v.GetN(); i++) {
		f << v.GetComponent(i) << std::endl;
	}

	f.close();
}

// test
bool are_close(double calculated, double expected, double epsilon = 1e-7) {
		return fabs(calculated - expected) < epsilon;
	}

template <typename T> void test_stat_func(void) {
	Vettore <T>v(4);
	for (size_t i{0}; i < 4; i++) {
			v.SetComponent(i, i);
		}
	Vettore <T>vd(3);
	for (size_t i{0}; i < 3; i++) {
		vd.SetComponent(i, i);
	}

	assert(are_close(fmedia <T>(v), 1.5));
	std::cerr << "test media ok" << std::endl;
	assert(are_close(fvarianza <T>(v, 1.5), 1.25));
	std::cerr << "test varianza ok" << std::endl;
	assert(are_close(fmediana <T>(v), 1.5));
	std::cerr << "test mediana n pari ok" << std::endl;
	assert(are_close(fmediana <T>(vd), 1));
	std::cerr << "test mediana n dispari ok" << std::endl;
}