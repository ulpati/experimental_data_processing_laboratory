#pragma once

#include <cmath>

class Posizione {

	public:
		// costruttori
		Posizione();
		Posizione(double x, double y, double z);

		// distruttore
		~Posizione();
		
		// metodi
		double getX() const;
		double getY() const;
		double getZ() const;
		double getR() const;
		double getPhi() const;
		double getTheta() const;
		double getRho() const;
		double Distanza(const Posizione&) const;

	private:
		double m_x, m_y, m_z;
};