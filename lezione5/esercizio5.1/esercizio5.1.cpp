#include <iostream>

#include "particella.h"
#include "elettrone.h"
#include "../fmtlib.h"

using namespace std;

int main() {

	// inizializzazione variabili
	Particella *a {new Particella(1., 1.6E-19)};
	Elettrone *e {new Elettrone()};

	// metodi della classe base
	cout << "A" << endl;
	fmt::print("Particella con massa {} e carica {}\n", a->GetMassa(), a->GetCarica());
	a->stampa();
	cout << endl;

	// metodi della classe derivata
	cout << "E" << endl;
	fmt::print("Elettrone con massa {} e carica {}\n", e->GetMassa(), e->GetCarica());
	e->stampa();
	cout << endl;

	Particella b{*a}; // costruisco una Particella a partire da una Particella
	Particella d{*e}; // costruisco una Particella a partire da un Elettrone
	Particella f{d}; // costruisco un Elettrone a partire da una Particella

	cout << "B" << endl;
	fmt::print("Particella con massa {} e carica {}\n", b.GetMassa(), b.GetCarica());
	b.stampa();
	cout << endl;

	cout << "F" << endl;
	fmt::print("Particella con massa {} e carica {}\n", f.GetMassa(), f.GetCarica());
	f.stampa();
	cout << endl;

	cout << "D" << endl;
	fmt::print("Particella con massa {} e carica {}\n", d.GetMassa(), d.GetCarica());
	d.stampa();
	cout << endl;

	return 0;
}