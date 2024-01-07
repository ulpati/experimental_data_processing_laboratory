#include <iostream>
#include "funzioneBase.h"
#include "solutore.h"
#include "tangente.h"
#include "bisezione.h"
#include "assert.h"

using namespace std;

double precision = 1e-8;
double ext_a = -66.;
double ext_b = 0.;
unsigned int maxiter = 100;
int n_zero = 20;

int main(){

    test_zeroes();
    
    int cifre_significative = -log10(precision);

    Tangente T;
    Bisezione bise_tan{ precision, maxiter };
    cout << endl << "Inizio metodo tangente\n" << endl;
    T.cerca_nzeri( n_zero, bise_tan, cifre_significative );
    cout << endl << "Fine metodo tangente" << endl;

    return 0;
}