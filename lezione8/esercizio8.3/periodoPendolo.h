#pragma once

#include <iostream>
#include <vector>

int cerca_inversione (const std::vector<double> &x) {
	for(size_t i {2}; i < x.size(); i++)
		if (x[i-1] * x[i] <= 0)
			return i - 1;
	
	std::cerr << "Inversione non trovata, far andare la simulazione per un tempo maggiore" << std::endl;
	return -1;
}

double interpolazione (std::vector<double> & a, std::vector<double> &b, const double y) {
	return a[0] + ((a[0] - b[0]) / (a[1] - b[1])) * (y - a[1]);
}

double interpolazione (std::vector<double> &a, std::vector<double> &b) {
	return interpolazione(a,b,0.);
}

// x e t separati
double inversione_tempo (const std::vector<double> &tempo, const std::vector<double> &omega) {
	int i {cerca_inversione(omega)}; //ricerca posizione inversione velocità
    if ( i == -1 ) return -1; //posizione negativa = inversione non trovata
	std::vector<double> a{tempo[i], omega[i]};
	std::vector<double> b{tempo[i+1], omega[i+1]};

	return fabs(interpolazione(a,b));
}

double periodo (std::vector< std::vector<double> > &oscillazione) {
	return 2 * inversione_tempo(oscillazione[0], oscillazione[2]); // rispettivamente tempo e omega
}