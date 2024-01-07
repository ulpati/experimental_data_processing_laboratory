#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cassert>

class Vettore {
	public:

		Vettore(); // costruttore di default
		Vettore(size_t N); // costruttore con dimensione del vettore
		Vettore(const Vettore&); // copia costruttore

		~Vettore(); // distruttore

		size_t GetN() const {return m_N; } // restituisce la dimensione del vettore
		void SetComponent(size_t, double); // modifica la componente i-esima
		double GetComponent(size_t) const; // accede alla componente i-esima
		
		void Scambia(size_t, size_t);
		
		double& operator[] (size_t );
		Vettore& operator=(const Vettore &V); // operatore di assegnazione

		

	private:

		size_t m_N; // dimensione del vettore
		double* m_v; // puntatore all'array dei dati

};