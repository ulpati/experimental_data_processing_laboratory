#pragma once

#include <cmath>
#include <iostream>

#include "solutore.h"

double default_precisione {1e-8};
double default_nmax {100};


class Bisezione : public Solutore {
        
    public:
        Bisezione() { m_precisione = default_precisione; m_nmax = default_nmax; }
        Bisezione( double precisione, unsigned int max_iter );
        Bisezione( double precisione, double a, double b, unsigned int nmax );
        ~Bisezione() override {};

        bool Trovato( double zero ) const override { return zero != std::nan("") ? "true" : "false"; }
        double GetIncertezza() const override { return m_incertezza; }

        double CercaZeriReference( double, double, const FunzioneBase & ) override;
        double cerca_middle_zero( double &, double &, const FunzioneBase & );
        double cerca_extremant_zero( double &, double &, const FunzioneBase & );
        double bisezione_condizionefail();
};

// controllo segno della funzione in coordinata x
double sign(double x){
    return x != 0 ? std::copysign(1.0, x) : 0.0;
}

double controllo_condizione( double & xmin, double & xmax, const FunzioneBase & f ){
    return sign(f.Eval(xmin)) * sign(f.Eval(xmax));
}

// metodi classi

Bisezione::Bisezione( double precisione, unsigned int nmax) : Bisezione(){
    m_precisione = precisione;
    m_incertezza = precisione;
    m_nmax = nmax;    
}

Bisezione::Bisezione( double precisione, double a, double b, unsigned int nmax )  : Bisezione(precisione, nmax){
    m_a = a;
    m_b = b;
}

double Bisezione::cerca_middle_zero( double & xmin, double & xmax, const FunzioneBase & f ){

    int niterazioni {0};
    double *ext_neg {new double};
    double *ext_pos {new double};
    double middle_point {(xmax + xmin) / 2};
    if ( sign( f.Eval(xmax)) == 1. ){
        ext_pos = &xmax;
        ext_neg = &xmin;
    }
    else{
        ext_pos = &xmin;
        ext_neg = &xmax;
    }
  
// algoritmi

    while( (fabs( xmax-xmin ) > m_precisione) && (m_niterazioni < m_nmax) ) {        
        niterazioni++;

        if ( f.Eval(middle_point) == 0. ){
            m_niterazioni = niterazioni;
            m_incertezza = 0.;
            return middle_point;
        }

        else if ( sign( f.Eval(middle_point) ) == 1. )
            *ext_pos = middle_point;
        else
            *ext_neg = middle_point;

        middle_point = (xmax + xmin) / 2;
    }
        
    if ( m_niterazioni == m_nmax )
        std::cout << "Massimo numero di iterazioni raggiunte, n = " << niterazioni << std::endl;
    else if ( fabs( xmax-xmin ) < m_precisione )
        std::cout << "Massima precisione raggiunta: " << m_precisione << std::endl;
    
    m_incertezza = fabs( xmax-xmin )/2;
    m_niterazioni = niterazioni;

    return middle_point;
}

double Bisezione::cerca_extremant_zero( double & xmin, double & xmax, const FunzioneBase & f ){
    int niterazioni {0};
    m_incertezza = 0.;
    m_niterazioni = niterazioni;
    if (f.Eval(xmin) == 0. ) return xmin;
    else return xmax;
}

double Bisezione::bisezione_condizionefail(){
    std::cout << "Errore, impossibile trovare uno zero in questo intervallo. Non rispettata condizione della Bisezione." << std::endl;
    return  std::nan("");
}

double Bisezione::CercaZeriReference( double xmin, double xmax, const FunzioneBase & f ){
    m_a = xmin;
    m_b = xmax;

    if( controllo_condizione( xmin, xmax, f ) == -1. ) // o < 0
        return cerca_middle_zero ( xmin, xmax, f );

// ricerca zero negli estremi
    else if( controllo_condizione( xmin, xmax, f ) == 0. )
        return cerca_extremant_zero ( xmin, xmax, f );

    else return bisezione_condizionefail();
}