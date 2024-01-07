#pragma once

#include <iostream>
#include <cmath>

#include "funzioneBase.h"
#include "bisezione.h"
#include "../fmtlib.h"

class Tangente : public FunzioneBase {
    public:
        Tangente() {};
        ~Tangente() {}

        double Eval(double x) const override 
        {
            return sin(x) - x * cos(x);
        }

        void cerca_nzeri( int , Bisezione &, int );
};

void Tangente::cerca_nzeri( int n_zero, Bisezione & bis_tan, int cifre_significative ){
    double zero;

    for (int i = 0; i < n_zero; i++ ){
        zero = bis_tan.CercaZeriReference( i*M_PI, i*M_PI + M_PI/2, (*this) );
        if ( std::isnan(zero) )
            std::cout << "Errore, impossibile trovare uno zero in questo intervallo. Non rispettata condizione della Bisezione." << std::endl;
        else{
            std::cout << i+1 << " zero tangente:\t";
            fmt::print( "x_{2} = {0:{1}f}", zero, cifre_significative, i+1 );
            std::cout << std::endl;
        }
    }
}