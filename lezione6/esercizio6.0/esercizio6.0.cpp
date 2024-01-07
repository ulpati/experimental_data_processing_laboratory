#include <iostream>

#include "particella.h"
#include "elettrone.h"

using namespace std;

int main() {

	Particella *a{new Particella{1., 2.}};
	Elettrone *e{new Elettrone{}};
	Particella *b{new Elettrone{}};

	// stampa
	a->stampa();
	cout << endl;
	e->stampa();
	cout << endl;
	b->stampa();
	cout << endl;

	delete a;
	delete e;
	delete b;

	return 0;
}