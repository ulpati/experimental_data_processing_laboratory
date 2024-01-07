#pragma once

#include "posizione.h"
#include <cmath>

class CampoVettoriale : public Posizione {

	public:

		// costruttori
		CampoVettoriale(const Posizione&);
		CampoVettoriale(const Posizione&, double Fx, double Fy, double Fz);
		CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz);

		// distruttore
		~CampoVettoriale();

		CampoVettoriale &operator+=(const CampoVettoriale &);
		CampoVettoriale operator+(const CampoVettoriale & ) const;

		double getFx() const;

		double getFy() const;

		double getFz() const;

		double Modulo();

	private:

		double m_Fx, m_Fy, m_Fz;
};