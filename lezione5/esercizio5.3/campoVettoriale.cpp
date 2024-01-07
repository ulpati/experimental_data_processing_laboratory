#include "campoVettoriale.h"

// costruttori
CampoVettoriale::CampoVettoriale(const Posizione&){
	m_Fx = 0;
	m_Fy = 0;
	m_Fz = 0; 
}

CampoVettoriale::CampoVettoriale(const Posizione&, double Fx, double Fy, double Fz) {
	Posizione();
	m_Fx = Fx;
	m_Fy = Fy;
	m_Fz = Fz;
}

CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz) {
	m_x = x;
	m_y = y;
	m_z = z;
	m_Fx = Fx;
	m_Fy = Fy;
	m_Fz = Fz;
}

// distruttore
CampoVettoriale::~CampoVettoriale() {}

CampoVettoriale & CampoVettoriale::operator+=(const CampoVettoriale & v) {
	return (*this) = (*this) + v;
}

CampoVettoriale CampoVettoriale:: operator+(const CampoVettoriale & v ) const {
	CampoVettoriale sum(v);
	sum.m_Fx += getFx();
	sum.m_Fy += getFy();
	sum.m_Fz += getFz();
	return sum;
}

double CampoVettoriale::getFx() const {
	return m_Fx;
}

double CampoVettoriale::getFy() const {
	return m_Fy;
}

double CampoVettoriale::getFz() const {
	return m_Fz;
}

double CampoVettoriale::Modulo() {
	return sqrt(pow(m_Fx, 2) + pow(m_Fy, 2) + pow(m_Fz, 2));
}