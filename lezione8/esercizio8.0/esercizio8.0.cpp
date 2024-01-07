#include <iostream>
#include <vector>
#include "opvect.h"
#include "assert.h"

using namespace std;

int main() {

    // test
    test_opvect();

    // inizializzazione vettori
    vector<double> a {1, 2, 3};
    vector<double> b {2, 3, 5};
    double c = 3.5;

    // stampa vettori
    cout << "Vettore 1: " << endl;
    stampa(a);

    cout << endl;

    cout << "Vettore 2: " << endl;
    stampa(b);

    cout << endl;

    cout << "scalare c: " << c << endl;
    cout << "------------------------" << endl;
    cout << endl;

    // somma tra vettori
    cout << "Somma tra vettori: a+b" << endl;
    stampa(a+b);
    cout << endl;
    

    // differenza tra vettori
    cout << "Differenza tra vettori: a-b" << endl;
    stampa(a-b);
    cout << endl;

    // prodotto scalare tra vettori
    cout << "Prodotto scalare tra vettori: a*b" << endl;
    cout << a*b << endl;
    cout << endl;

    // prodotto tra scalare e vettore
    cout << "Prodotto tra scalare c e vettore a" << endl;
    stampa(c*a);
    cout << endl;

    // prodotto tra vettore e scalare
    cout << "Prodotto tra vettore b e scalare c" << endl;
    stampa(b*c);
    cout << endl;

    // divisione tra un vettore e uno scalare
    cout << "Divisione tra vettore a e scalare c" << endl;
    stampa(a/c);
    cout << endl;

    // somma tra vettori con risultato nel primo vettore
    cout << "Somma tra vettori con risultato nel primo vettore" << endl;
    stampa(a+=b);
    cout << endl;

    // differenza tra vettori con risultato nel primo vettore
    cout << "Differenza tra vettori con risultato nel primo vettore" << endl;
    stampa(a-=b);
    cout << endl;

    return 0;
}