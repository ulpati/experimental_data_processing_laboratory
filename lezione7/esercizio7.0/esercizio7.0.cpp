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
	test_midpoint();

	// inizializzazione variabili
	double a {0}, b {M_PI};
	unsigned int n_passi {100};
	unsigned int cifre_significative {16};

	// stampa
	fmt::print( "Integrale di sin(x) in [0, pigreca] : {0:.{1}f}\n", midpoint(sin, a, b, n_passi), cifre_significative );
	double val {2};

	// vettori steps e errors per grafico
	int steps[] = {10, 50, 100, 500, 1000};
	double *errors {new double[5]};
	for(size_t i{0}; i < 5; i++)  errors[i] = compute_errors(midpoint(sin, a, b, steps[i]), 5, val);


	// stampa errori
	for (size_t i{0}; i < 5; i++) {
		cout << "Errore del computer a " << steps[i] << " step: " << errors[i];
		fmt::print("	{0:.{1}f}\n", compute_errors(midpoint(sin, a, b, steps[i]), 5, val), cifre_significative);
	}

	fmt::print("Error slope: {0:.{1}f}\n", error_slope(steps, errors, 5), cifre_significative);

	// root
	// grafico bilogaritmico errore
	TApplication app ("app", 0, 0);
	TCanvas c("c","c",1000,1000);
	c.Divide(2);
	c.cd(1);

	TGraph *g {new TGraph()};
	for(size_t i {0}; i < 5; i++) {
		g ->SetPoint(i, steps[i], errors[i]);
	}

	g->SetTitle("Grafico errore bilogaritmico");
	TVirtualPad::Pad()->SetLogx();
	TVirtualPad::Pad()->SetLogy();
	g->GetXaxis()->SetTitle("Numero di passi");
	g->GetYaxis()->SetTitle("Errore");
	g->GetYaxis()->SetTitleOffset(1);
	g->Draw("AL+");

	// grafico errore
	c.cd(2);

	TGraph *g2 {new TGraph()};
	for(size_t i{0}; i < 5; i++) {
		g2 ->SetPoint(i, steps[i], errors[i]);
	}

	g2->SetTitle("Grafico errore");
	g2->GetXaxis()->SetTitle("Numero di passi");
	g2->GetYaxis()->SetTitle("Errore");
	g2->GetYaxis()->SetTitleOffset(1.3);
	g2->GetYaxis()->SetRangeUser(-0.0001, 0.009);
	g2->Draw("AL+");

	c.SaveAs("esercizio7.0.png");

	// pulizia memoria
	delete[] errors;
	
	app.Run();

	return 0;

}