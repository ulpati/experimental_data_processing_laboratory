#include <iostream>
#include "funzioneBase.h"
#include "parabola.h"
#include "bisezione.h"
#include "assert.h"
#include "../fmtlib.h"

using namespace std;

double precisione {1e-8};
double ext_a {-66.};
double ext_b {0.};
unsigned int maxiter {100};

int main(){

    test_zeroes();

    Parabola parabola( 3, 5, -2 );
    Bisezione bise_parabola{ precisione, maxiter };
    
    const double zero {bise_parabola.CercaZeriReference( ext_a, ext_b, parabola )};
    
    if ( bise_parabola.Trovato(zero) ){
        int cifre_significative {int(round(-log10(bise_parabola.GetIncertezza()) + 0.5))};
        fmt::print( "Numero iterazioni {0} \t Imprecisione = {1:.{3}f}\nLa parabola ha uno zero in x = {2:.{3}f}\n", bise_parabola.GetNiterazioni(), bise_parabola.GetIncertezza(), zero, cifre_significative );
    }

    return 0;
}