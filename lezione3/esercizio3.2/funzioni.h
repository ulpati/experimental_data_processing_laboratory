#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>

// punto 1

template <typename T> std::vector<T> letfile (size_t ndata, const char* filename) {
	std::vector<T> v;
	std::ifstream in(filename);

	assert(in && "Errore apertura file!\n");
		
	for (size_t i {0}; i < ndata; i++) {
		T val {0};
		in >> val;
		v.push_back(val);

		assert(!in.eof() && "Fine file\n");
	}

	in.close();
	
	return v;
}

// punto 2
template <typename T> T fmedia (const std::vector<T> & v) {
	T sommam {0};
	for (size_t i {0}; i < v.size(); i++) {
		sommam = sommam + v[i];
	}
  return sommam / v.size();
}

template <typename T> T fvarianza (const std::vector<T> & v, T media) {
	T sommav {0};
	for (size_t i {0}; i < v.size(); i++) {
		sommav = sommav + pow(v[i] - media, 2);
	}
	return sommav / v.size();
}

//punto 3
template <typename T> T fmediana (std::vector<T> & v) {
	sort( v.begin(), v.end());
	T mediana {0};
	if (v.size()%2 == 0) {
		mediana = (v[v.size() / 2 - 1] + v[v.size()/2]) / 2;
	} else {
		mediana = v[v.size() / 2];
	}
	return mediana;
}

//punto 4
template <typename T> void stampa (T media, T varianza, T mediana) {
	std::cout << "Media = " << media << std::endl;
	std::cout << "Varianza = " << varianza << std::endl;
	std::cout << "Mediana = " << mediana << std::endl;
}

//punto 5
template <typename T> void stampa (const std::vector<T> & v, std::ofstream &f) {
	for (size_t i {0}; i < v.size(); i++) {
		f << v[i] << std::endl;
	}

	f.close();
}

// test
bool are_close(double calculated, double expected, double epsilon = 1e-7) {
		return fabs(calculated - expected) < epsilon;
	}

void test_stat_func(void) {
	std::vector<double> mydata{1, 2, 3, 4};
	std::vector<double> mydata2{1, 2, 3};

	assert(are_close(fmedia<double>(mydata), 2.5));
	std::cerr << "test media ok" << std::endl;
	assert(are_close(fvarianza<double>(mydata, 2.5), 1.25));
	std::cerr << "test varianza ok" << std::endl;
	assert(are_close(fmediana<double>(mydata), 2.5));
	std::cerr << "test mediana n pari ok" << std::endl;
	assert(are_close(fmediana<double>(mydata2), 2));
	std::cerr << "test mediana n dispari ok" << std::endl;
}