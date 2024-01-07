#pragma once

#include <iostream>
#include <vector>
#include <cmath>

#include "funzioniPendoloForzato.h"
#include "../fmtlib.h"

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

unsigned int cerca_posizione_maschera( std::vector < std::vector<double> > & dati, double & maschera ){
    if ( maschera > dati[0][dati[0].size()-1] ){
        std::cout << "Coda non trovata, tempo-maschera è più grande del periodo studiato. Riprovare con un maschera più piccolo\n";
        return -1;
    }

    for ( size_t i {0}; i < dati[0].size(); i++ )
        if ( dati[0][i] > maschera )
            return i;
        
    std::cout << "Coda non trovata. Riprovare con una maschera minore.\n";    
    return -1;
}

double ampiezza_forzata( const double & omega, std::vector< std::vector<double> > dati, EquazioneDifferenzialeBase *equazione_differenziale, PendoloForzato *pendolo_forzato ) {
    //maschera per spostarsi sufficentemente dalla regione di instabilità del moto OAF
    double maschera {10./pendolo_forzato->GetAlpha()};
    
    //ricerca posizione corrispondente alla maschera nella matrice con tutti i dati
    unsigned int maschera_pos = cerca_posizione_maschera(dati, maschera);
    
    //coda dei dati solo dopo la maschera
    std::vector< std::vector <double> > coda_oscillazione(dati.size(), std::vector<double> ( dati[0].size() - maschera_pos ));
    for ( size_t i {0}; i < coda_oscillazione[0].size(); i++ )
        for( size_t j {0}; j < coda_oscillazione.size(); j++)
            coda_oscillazione[j][i] = dati[j][maschera_pos+i];
    
    //ricerca inversione nella coda
    unsigned int k {(unsigned int)(cerca_inversione( coda_oscillazione[2] ))};
    
    std::vector <double> ptA {coda_oscillazione[0][k], coda_oscillazione[2][k]};
    std::vector <double> ptB {coda_oscillazione[0][k+1], coda_oscillazione[2][k+1]};
    
    double t0 {interpolazione(ptA, ptB)};
    double deltat {fabs(t0 - coda_oscillazione[0][k])};

    //riesecuzione di RK a partire dal tempo t0 usando come passo il detat(= t_inversione - t0)
    //eseguendo una sola volta la posizione ottenuta dovrebbe essere quella del massimo (velocità ang circa nulla)
    std::vector < std::vector<double> > nuova_soluzione {equazione_differenziale->Passo(omega, {coda_oscillazione[1][k], coda_oscillazione[2][k]}, coda_oscillazione[0][k], coda_oscillazione[0][k] + 1.1 * deltat, deltat, pendolo_forzato)};
    
    fmt::print( "omega = {6:.2f} --> t0 = {0:.4f}, angolo = {1:.4f}, velocità = {2:.4f},\t   t0 + delta_t = {3:.4f}, angolo = {4:.4f}, velocità = {5:.6f}\n", nuova_soluzione[0][0], nuova_soluzione[1][0], nuova_soluzione[2][0], nuova_soluzione[0][1], nuova_soluzione[1][1], nuova_soluzione[2][1], omega);
    if ( fabs(nuova_soluzione[2][1]) <= 10e-6 )
        std::cerr << "\til valore della posizione in questo massimo è uguale all'ampiezza dell'oscillazione\n";
    
    return fabs(nuova_soluzione[1][1]);
}