#include <iostream>

#include "funzioneBase.h"
#include "parabola.h"

using namespace std;

int main() {

	// inizializzazione variabili
	double a, b, c;

	// interazione utente
	cout << "Inserire parametri parabola a, b, c: " << endl;
	cin >> a >> b >> c;

	// Parabola
	Parabola p(a, b, c);
	
	// stampa valore y in x del vertice
	cout << "y(" << -b/(2*a) << "): " << p.Eval(-b/(2*a)) << endl;

	return 0;
}