#pragma once

#include "funzioneBase.h"

class Parabola : public FunzioneBase {

	public:
		Parabola() : m_a{}, m_b{}, m_c{1} {}
		Parabola(double a, double b, double c) : m_a{a}, m_b{b}, m_c{c} {}
		~Parabola() {}

		double Eval(double x) const override {
			return (m_a * x + m_b) * x + m_c;
		}
		
		void SetA(double a) { m_a = a; }
		void SetB(double b) { m_b = b; }
		void SetC(double c) { m_c = c; }

		double GetA() const { return m_a; }
		double GetB() const { return m_b; }
		double GetC() const { return m_c; }

	private:
		double m_a, m_b, m_c;

};