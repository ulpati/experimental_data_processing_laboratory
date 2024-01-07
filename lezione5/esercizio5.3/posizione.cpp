#include "posizione.h"

// costruttore di default
Posizione::Posizione() : m_x{}, m_y{}, m_z{} {}

// costruttore a partire da una terna cartesiana
Posizione::Posizione(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z} {}

// distruttore 
Posizione::~Posizione() {}

// Cordinate cartesiane
double Posizione::getX() const { return m_x; }

double Posizione::getY() const { return m_y; }

double Posizione::getZ() const { return m_z; }

// coordinate sferiche
double Posizione::getR() const {
	return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
}

double Posizione::getPhi() const { return atan2(m_y, m_x); }

double Posizione::getTheta() const { return acos(m_z / getR()); }

// raggio delle coordinate sferiche
double Posizione::getRho() const { return sqrt(pow(m_x, 2) + pow(m_y, 2)); }

// distanza da un altro punto
double Posizione::Distanza(const Posizione& b) const {
	return sqrt(pow(getX() - b.getX(), 2) + 
	            pow(getY() - b.getY(), 2) +
		    pow(getZ() - b.getZ(), 2));
}