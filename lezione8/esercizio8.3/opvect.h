#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

// somma tra vettori
template <typename T> std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b) {

    assert(a.size() == b.size());
    std::vector<T> sum(a.size());
    for(int i = 0; i < static_cast<int>(a.size()); i++) sum[i] = a[i] + b[i];

    return sum;
}

// differenza tra vettori
template <typename T> std::vector<T> operator-(const std::vector<T> &a, const std::vector<T> &b) {

    assert(a.size() == b.size());
    std::vector<T> diff(a.size());
    for(int i = 0; i < static_cast<int>(a.size()); i++) diff[i] = a[i] - b[i];
    
    return diff;
}

// prodotto scalare tra vettori
template <typename T> T operator*(const std::vector<T> &a, const std::vector<T> &b) {

    assert(a.size() == b.size());
    T sum = 0;
    for (int i = 0; i < static_cast<int>(a.size()); i++) sum += a[i] * b[i];

    return sum;
}

// prodotto tra scalare e vettore
template <typename T> std::vector<T> operator*(T n, const std::vector<T> &a) {

    std::vector<T> prod(a.size());
    for(int i = 0; i < static_cast<int>(a.size()); i++) prod[i] = n * a[i];

    return prod;
}

// prodotto tra vettore e scalare
template <typename T> std::vector<T> operator*(const std::vector<T> &a, T n) {

    std::vector<T> prod(a.size());
    for (int i = 0; i < static_cast<int>(a.size()); i++) prod[i] = n * a[i];

    return prod;
}

// divisione tra vettore e scalare
template <typename T>
std::vector<T> operator/( const std::vector<T> & a, const T & n ) {    
	std::vector<T> divisione(a.size());
	for ( size_t i = 0; i < divisione.size(); i++ )
		divisione[i] = a[i] / n;

	return divisione;
}

// divisione tra scalare e vettore di tipi differenti
template <typename T, typename C>
std::vector<T> operator/( const T & n, const std::vector<C> & a ) {    
  	std::vector<T> divisione(a.size());
	for ( size_t i = 0; i < divisione.size(); i++ )
		divisione[i] = n / a[i];
		
	return divisione;
}

// somma tra vettori con risultato nel primo vettore
template <typename T> std::vector<T>& operator+=(std::vector<T> &a,const std::vector<T> &b) {

    assert(a.size() == b.size());
    for (int i = 0; i < static_cast<int>(a.size()); i++) a[i] += b[i];

    return a;
}

// differenza tra vettori con risultato nel primo vettore
template <typename T> std::vector<T>& operator-=(std::vector<T> &a, const std::vector<T> &b) {

    assert(a.size() == b.size());
    for (int i = 0; i < static_cast<int>(a.size()); i++) a[i] -= b[i];

    return a;
}

// stampa vettore
template <typename T> void stampa(const std::vector<T> &v) {

    std::cout << "Inizio stampa vettore" << std::endl;
    for(int i = 0; i < static_cast<int>(v.size()); i++) std::cout << v[i] << std::endl;
    std::cout << "Fine stampa vettore" << std::endl;
}