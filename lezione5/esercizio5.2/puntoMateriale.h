#pragma once

#include <cmath>

#include "particella.h"
#include "posizione.h"
#include "campoVettoriale.h"

const double eps0 {8.85419E-12};

class PuntoMateriale : public Particella, Posizione {

	public:

		// costruttori
		PuntoMateriale(double massa, double carica, const Posizione&);
		PuntoMateriale(double massa, double carica, double x, double y, double z);

		// distruttore
		~PuntoMateriale();

		CampoVettoriale CampoElettrico(const Posizione& ) const;
};