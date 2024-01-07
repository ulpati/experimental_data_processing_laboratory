#pragma once

#include <iostream>

#include "../fmtlib.h"

class Particella {

	public:

		// costruttori
		Particella();
		Particella(double massa, double carica);

		// distruttore
		virtual ~Particella();

		// metodi
		double GetMassa() const { return m_massa; }

		double GetCarica() const { return m_carica; }

		virtual void stampa() const;

	protected:
		
		double m_massa;
		double m_carica;
};