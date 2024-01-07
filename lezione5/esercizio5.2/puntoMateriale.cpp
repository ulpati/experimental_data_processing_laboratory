#include "puntoMateriale.h"

// costruttore
PuntoMateriale::PuntoMateriale(double massa, double carica, const Posizione& p) : Particella(massa, carica), Posizione(p.getX(), p.getY(), p.getZ()) {}

PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z) : Particella(massa, carica) , Posizione(x, y, z) {}

// distruttore
PuntoMateriale::~PuntoMateriale() {}

CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& b) const {
	double r {Distanza(b)};
	double k {m_carica / (4*M_PI*eps0*pow(r, 3))};
	double Ex {k * (b.getX() - getX())};
	double Ey {k * (b.getY() - getY())};
	double Ez {k * (b.getZ() - getZ())};

	return CampoVettoriale(b.getX(), b.getY(), b.getZ(), Ex, Ey, Ez);
}