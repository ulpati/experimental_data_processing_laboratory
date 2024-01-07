#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>

template <typename T> class Vettore {
	public:

		// costruttore di default
		Vettore() {
			std::cerr << "Invocazione del costruttore di default" << std::endl;
			m_N = 0;
			m_v = nullptr;
		}

		// costruttore con dimensione del vettore
		Vettore(size_t N) {
			std::cerr << "Invocazione del costruttore con argomenti" << std::endl;
			m_N = N;
			m_v = new double[N];
			for(size_t k {0}; k < N; k++) m_v[k] = 0;	
		}

		// copia costruttore
		Vettore(const Vettore& V) {
			m_N = V.GetN();
			m_v = new double[m_N];
			for(size_t i {0}; i < m_N; i++) m_v[i] = V.GetComponent(i);
		}

		// distruttore
		~Vettore() {
			std::cerr << "Invocazione del distruttore " << std::endl;
			delete[] m_v;
		}

		// restituisce la dimensione del vettore
		size_t GetN() const {return m_N; } 

		// modifica la componente i-esima
		void SetComponent(size_t i, T a) {
			assert((i < m_N) && "Errore: l'indice è troppo grande");
			m_v[i] = a;
		}

		// accede alla componente i-esima
		T GetComponent(size_t i) const {
			assert((i < m_N) && "Errore: l'indice è troppo grande");
			return m_v[i];
		}

		void Scambia(size_t primo, size_t secondo) {
			double temp {m_v[primo]};
			m_v[primo] = m_v[secondo];
			m_v[secondo] = temp;
		}

		T& operator[] (size_t i) {
			assert((i < m_N) && "Errore: l'indice è troppo grande");
			return m_v[i];
		}

		// operatore di assegnazione
		Vettore& operator=(const Vettore& V) {
			m_N = V.GetN();
			if (m_v) delete[] m_v;

			m_v = new double[m_N];

			for(size_t i {0}; i < m_N; i++) m_v[i] = V.GetComponent(i);

			return *this;
		}

		

	private:

		size_t m_N; // dimensione del vettore
		T* m_v; // puntatore all'array dei dati

};