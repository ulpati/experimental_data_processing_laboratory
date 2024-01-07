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

		virtual std::vector< std::vector<double> > Passo (double t0, double tf, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const = 0;
		virtual std::vector<double> Passo (double t, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const = 0;
};

// metodo Eulero
class Eulero : public EquazioneDifferenzialeBase {

	public:
		Eulero() {};
		~Eulero() {};

        std::vector< std::vector<double> > Passo (double t0, double tf, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const override {
            unsigned int num_steps {(unsigned int)(round( (tf - t0)/h + 0.5))};
            std::vector< std::vector<double> > matrice_dati_risultati( num_steps, std::vector<double>(x.size()+1) );
            std::vector<double> x_v_corrente {x};

            for ( unsigned int i = 0; i < num_steps; i++ ){
                matrice_dati_risultati[i][0] = t0 + h * i;

                for ( size_t j = 1; j < x.size(); j++ )
                    matrice_dati_risultati[i][j] = x_v_corrente[j-1];  // x = x_v_corrente[x] & v = x_v_corrente[v];

                x_v_corrente += f.Eval( matrice_dati_risultati[i][0], x_v_corrente ) * h;
            }

            return matrice_dati_risultati;
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
		
		std::vector< std::vector<double> > Passo (double t0, double tf, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const override {
            unsigned int num_steps = round( (tf - t0)/h + 0.5);
			
			//matrice dati ottenuti da metodo di risoluzione con tempo, poszione e velocità
            std::vector< std::vector<double> > matrice_dati_risultati( x.size()+1, std::vector<double>(num_steps) );
            std::vector<double> x_v_corrente {x};
            std::vector<double> k1(x.size()), k2(x.size()), k3(x.size()), k4(x.size());
        
            for ( unsigned int i = 0; i < num_steps; i++ ){
                matrice_dati_risultati[0][i] = t0 + h * i;

                for ( size_t j = 1; j < matrice_dati_risultati.size(); j++ )
                    matrice_dati_risultati[j][i] = x_v_corrente[j-1]; // x = x_v_corrente[x] & v = x_v_corrente[v];
                    
                k1 = f.Eval( matrice_dati_risultati[0][i], x_v_corrente );
                k2 = f.Eval( matrice_dati_risultati[0][i] + h / 2., x_v_corrente + k1 * h / 2.0 );
                k3 = f.Eval( matrice_dati_risultati[0][i] + h / 2., x_v_corrente + k2 * h / 2.0 );
                k4 = f.Eval( matrice_dati_risultati[0][i] + h, x_v_corrente + k3 * h );
                
				x_v_corrente += (k1 + 2.*k2 + 2.*k3 + k4) * h / 6.;
            }

            return matrice_dati_risultati;
        }

		std::vector<double> Passo (double t, const std::vector<double> &x, double h, const FunzioneVettorialeBase &f) const override {

			std::vector<double> k1 {f.Eval(t,x)},
			k2 {f.Eval(t + h / 2., x + k1 * h / 2.)},
			k3 {f.Eval(t + h / 2., x + k2 * h / 2.)},
			k4 {f.Eval(t + h, x + k3 * h)};

			return x + ((k1 + 2. * k2 + 2. * k3 + k4) * (h / 6.));
		}
};

// pendolo
class Pendolo : public FunzioneVettorialeBase {

	public:
		Pendolo() {};
		~Pendolo() {};

		Pendolo(double lunghezza_corda, double accelerazione) : m_lunghezza_corda(lunghezza_corda), m_accelerazione(accelerazione) {}

		std::vector<double> Eval (double t, const std::vector<double> &x) const override {
			return {x[1], -m_accelerazione / m_lunghezza_corda * sin(x[0])}; // omega  0 = 1*
		}

	private:
		double m_lunghezza_corda;
		double m_accelerazione;
};