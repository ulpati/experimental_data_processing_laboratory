#include <iostream>
#include <cmath>

#include "integrale.h"
#include "assert.h"

#include "../fmtlib.h"
#include "../../root/include/TApplication.h"
#include "../../root/include/TCanvas.h"
#include "../../root/include/TGraph.h"
#include "../../root/include/TF1.h"
#include "../../root/include/TAxis.h"

using namespace std;

int main(){

	// test
	test_simpson();

	// inizializzazione variabili
	double a {0}, b {M_PI};
	unsigned int n_passi {100};
	unsigned int cifre_significative {15};

	// stampa
	fmt::print( "Integrale di sin(x) in [0, pigreca] : {0:.{1}f}\n", simpson(sin, a, b, n_passi), cifre_significative );
	double val {2};

	// vettori steps e errors per grafico
	int steps[] = {10, 50, 100, 500, 1000};
	double *errors {new double[5]};
	for(size_t i{0}; i < 5; i++)  errors[i] = compute_errors(simpson(sin, a, b, steps[i]), 5, val);


	// stampa errori
	for (size_t i{0}; i < 5; i++) {
		cout << "Errore del computer a " << steps[i] << " step: " << errors[i];
		fmt::print("      {0:.{1}f}\n", compute_errors(simpson(sin, a, b, steps[i]), 5, val), cifre_significative);
	}

	fmt::print("Error slope: {0:.{1}f}\n", error_slope(steps, errors, 5), cifre_significative);

	// root
	// grafico bilogaritmico errore
	TApplication app ("app", 0, 0);
	TCanvas c("c","c",1000,1000);

	TGraph *g {new TGraph()};
	for(size_t i{0}; i < 5; i++) {
		g ->SetPoint(i, steps[i], errors[i]);
	}

	g->SetTitle("Grafico errore bilogaritmico");
	TVirtualPad::Pad()->SetLogx();
	TVirtualPad::Pad()->SetLogy();
	g->GetXaxis()->SetTitle("Numero di passi");
	g->GetYaxis()->SetTitle("Errore");
	g->Draw("AL+");

	c.SaveAs("esercizio7.1.png");

	// pulizia memoria
	delete[] errors;
	
	app.Run();

	return 0;
}