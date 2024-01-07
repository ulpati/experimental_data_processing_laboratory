#pragma once

#include <iostream>

class Elettrone : public Particella {

	public:
		// costruttore
		Elettrone();

		// distruttore
		~Elettrone();

		// metodi
		void stampa() const;
};