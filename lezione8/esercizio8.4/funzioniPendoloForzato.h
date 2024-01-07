#pragma once

#include <cmath>
#include <vector>
#include "opvect.h"

class PendoloForzato {
    public:
        PendoloForzato( const double omega0, const double alpha) : m_omega0(omega0), m_alpha(alpha) { }
        double GetOmega() const { return m_omega0; }
        double GetAlpha() const { return m_alpha; }
        std::vector<double> pendolo_forzato( const double &omega, const std::vector<double> & x, double t )
			{ return {x[1], -m_omega0 * m_omega0 * x[0] - m_alpha * x[1] + sin(omega * t) }; }
    
    private:
        double m_omega0;
        double m_alpha;
};

class EquazioneDifferenzialeBase {
    public:
        virtual std::vector< std::vector<double> > Passo( const double & omega, const std::vector<double> & x0, const double & startt, const double & endt, const double & h, PendoloForzato *fp ) const = 0;
        virtual std::vector< double > Passo( const double & omega, const std::vector<double> & x, const double & t, const double & h, PendoloForzato *fp ) const = 0;
        virtual ~EquazioneDifferenzialeBase() {}
};

class RungeKutta : public EquazioneDifferenzialeBase {
    public:
            std::vector< std::vector<double> > Passo( const double & omega, const std::vector<double> & x0, const double & startt, const double & endt, const double & h, PendoloForzato *fp ) const override{
            unsigned int n_passi = round( (endt - startt)/h + 0.5);
            
            std::vector< std::vector<double> > risultato( x0.size()+1, std::vector<double>(n_passi) );
            std::vector<double> corrente {x0};
            std::vector<double> k1(x0.size()), k2(x0.size()), k3(x0.size()), k4(x0.size());
        
            for ( unsigned int i {0}; i < n_passi; i++ ){
                risultato[0][i] = startt + h * i;
                for ( size_t j {1}; j < risultato.size(); j++ )
                    risultato[j][i] = corrente[j-1];
                    
                k1 = fp->pendolo_forzato( omega, corrente, risultato[0][i] );
                k2 = fp->pendolo_forzato( omega, corrente + k1 * h / 2.0, risultato[0][i] + h / 2. );
                k3 = fp->pendolo_forzato( omega, corrente + k2 * h / 2.0, risultato[0][i] + h / 2. );
                k4 = fp->pendolo_forzato( omega, corrente + k3 * h, risultato[0][i] + h );
                    
                corrente += (k1 + 2.*k2 + 2.*k3 + k4) * h / 6.;
            }

            return risultato;
        }

            std::vector< double > Passo( const double & omega, const std::vector<double> & x, const double & t, const double & h, PendoloForzato *fp ) const override{
            std::vector< double > risultato{x};
            std::vector<double> k1(x.size()), k2(x.size()), k3(x.size()), k4(x.size());
            
            k1 = fp->pendolo_forzato( omega, risultato, t );
            k2 = fp->pendolo_forzato( omega, risultato + k1 * h / 2.0, t + h / 2. );
            k3 = fp->pendolo_forzato( omega, risultato + k2 * h / 2.0, t + h / 2. );
            k4 = fp->pendolo_forzato( omega, risultato + k3 * h, t + h );
            risultato += (k1 + 2.*k2 + 2.*k3 + k4) * h / 6.;

            return risultato; 
        }
};
