#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cassert>

#include "funzioni.h"

#include "../../root/include/TH1F.h"
#include "../../root/include/TApplication.h"
#include "../../root/include/TCanvas.h"

using namespace std;

int main(int argc, char **argv) {
	
	// test
	test_stat_func();

	// controllo utente
	if (argc < 3) {
		cerr << "Uso del programma: " << argv[0] << "<n_data> <filename> " << endl;
		return -1;
	}


	// 1. Legge i dati dal file
	vector<double>v {letfile<double>(atoi(argv[1]), argv[2])};
	
	// 2. Calcola la media e la varianza
	double media {fmedia<double>(v)};
	double varianza {fvarianza<double>(v, media)};
	
	// 3. Calcola la mediana: copia il vettore di partenza…
	vector<double>vc {v};

	// …e infine calcola la mediana
	double mediana {fmediana<double>(vc)};

	// 4. Visualizza i dati ordinati
	stampa <double>(media, varianza, mediana);

	// root
	TApplication app("app", 0, 0);
	TH1F histo ("histo", "histo", 100, -10, 100);
	histo.StatOverflows(kTRUE);
	for (size_t k {0}; k < v.size(); k++) histo.Fill(v[k]);
	TCanvas mycanvas ("Histo","Histo");
	histo.SetTitle("istogramma");
	histo.GetXaxis()->SetTitle("misure");
	histo.GetYaxis()->SetTitle("n");
	histo.Draw();

	// 5. Scrive l'array ordinato in un file
	ofstream outputFile("output.dat");
	stampa(vc, outputFile);

	app.Run();

	return 0;
}