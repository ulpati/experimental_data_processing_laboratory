#pragma once

#include <iostream>

class Elettrone : public Particella {

	public:
		// costruttore
		Elettrone();

		// distruttore
		~Elettrone() override;

		// metodi
		void stampa() const override;
};