#pragma once

#include <vector>
#include <cmath>

#include "opvect.h"

// classe astratta che restituisce la derivata valutata nel punto x
class FunzioneVettorialeBase {

	public:
		virtual std::vector<double> Eval(double t, const std::vector<double> &x) const = 0;
};

// oscillatore armonico
class OscillatoreArmonico : public FunzioneVettorialeBase {

	public:
		OscillatoreArmonico() {};
		OscillatoreArmonico(double omega0) {m_omega0 = omega0;};
		~OscillatoreArmonico() {};

		double GetOmega() const {return m_omega0;}
		void SetOmega(double omega0) {m_omega0 = omega0;}

		std::vector<double> Eval(double t, const std::vector<double> &x) const override {
			std::vector<double> sol(x.size());
			sol[0] = x[1];
			sol[1] = -x[0] * m_omega0 * m_omega0;
			return sol;
		}

	private:
		double m_omega0;
};

// classe astratta per un integratore di equazioni differenziali
class EquazioneDifferenzialeBase {
	
	public:

		virtual std::vector<double> Passo (double t0, double tf, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const = 0;
		virtual std::vector<double> Passo (double t, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const = 0;
};

// metodo Eulero
class Eulero : public EquazioneDifferenzialeBase {

	public:
		Eulero() {};
		~Eulero() {};

		std::vector<double> Passo (double t0, double tf, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const override {
			return x + f.Eval(tf-t0,x) * h;
		}
		
		std::vector<double> Passo (double t, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const override {
			return x + f.Eval(t,x) * h;
		}
};

// metodo Runge-Kutta
class Runge_Kutta : public EquazioneDifferenzialeBase {

	public:
		Runge_Kutta() {};
		~Runge_Kutta() {};

		std::vector<double> Passo (double t0, double tf, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const override {

			double t {tf - t0};

			std::vector<double> k1 {f.Eval(t,x)},
			k2 {f.Eval(t + h / 2., x + k1 * h / 2.)},
			k3 {f.Eval(t + h / 2., x + k2 * h / 2.)},
			k4 {f.Eval(t + h, x + k3 * h)};

			return x + ((k1 + 2. * k2 + 2. * k3 + k4) * h / 6.);
		}

		std::vector<double> Passo (double t, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const override {

			std::vector<double> k1 {f.Eval(t,x)},
			k2 {f.Eval(t + h / 2., x + k1 * h / 2.)},
			k3 {f.Eval(t + h / 2., x + k2 * h / 2.)},
			k4 {f.Eval(t + h, x + k3 * h)};

			return x + ((k1 + 2. * k2 + 2. * k3 + k4) * (h / 6.));
		}
};