#include <iostream>
#include <cmath>
#include "integrale.h"
#include "assert.h"
#include "../fmtlib.h"
#include "../../root/include/TApplication.h"
#include "../../root/include/TCanvas.h"
#include "../../root/include/TGraph.h"
#include "../../root/include/TF1.h"
#include "../../root/include/TH1.h"
#include "../../root/include/TAxis.h"
#include "../../root/include/TLegend.h"

using namespace std;

int main(){

	// test
	test_trapezoidi();
	test_simpson();
	test_midpoint();

	// inizializzazione variabili
	double a {0}, b {M_PI};
	unsigned int n_passi {100};
	unsigned int cifre_significative {16};
	unsigned int steps[] = {10, 50, 100, 500, 1000};
	double precisione[] = {1e-1, 1e-2, 1e-3, 1e-4, 1e-5};

	// stampa trapezoidi
	fmt::print( "Integrale di sin(x) in [0, pigreca] : {0:.{1}f}\n", trapezoidi(sin, a, b, n_passi), cifre_significative );
	double val {2};

	// vettori steps e errors per grafico trapezoidi
	double *errors_trapezoidi = new double[5];
	for(unsigned int i = 0; i < 5; i++)  errors_trapezoidi[i] = compute_errors(trapezoidi(sin, a, b, steps[i]), 5, val);

	// vettori steps e errors per grafico simpson
	double *errors_simpson = new double[5];
	for(unsigned int i = 0; i < 5; i++)  errors_simpson[i] = compute_errors(simpson(sin, a, b, steps[i]), 5, val);	

	// vettori steps e errors per grafico midpoint
	double *errors_midpoint = new double[5];
	for(unsigned int i {0}; i < 5; i++)  errors_midpoint[i] = compute_errors(midpoint(sin, a, b, steps[i]), 5, val);	

	// stampa errori
	for (unsigned int i{0}; i < 5; i++) {
		cout << "Errore del computer a " << steps[i] << " step: " << errors_trapezoidi[i];
		fmt::print("      {0:.{1}f}\n", compute_errors(trapezoidi(sin, a, b, steps[i]), 5, val), cifre_significative);
	}

	fmt::print("Error slope: {0:.{1}f}\n", error_slope(steps, errors_trapezoidi, 5), cifre_significative);

	// vettori steps e errors per grafico trapezoidi con precisione fissata
	double *errors_trapezoidi_precisione = new double[5];
	for(unsigned int i = 0; i < 5; i++)  errors_trapezoidi_precisione[i] = compute_errors(trapezoidi(sin, a, b, precisione[i]), 5, val);

	// stampa trapezoidi con precisione fissata
	for(unsigned int i{0}; i < 5; i++){
		fmt::print( "Integrale di sin(x) in [0, pigreca] : {0:.{1}f}\n", trapezoidi(sin, a, b, precisione[i]), cifre_significative );
		fmt::print("Precisione impostata: {0}\t Precisione ottenuta:{1}\n",precisione[i], errors_trapezoidi_precisione[i]);		
	}
	

	// ROOT
	//grafico bilogaritmico errore trapezoidi
	TApplication app ("app", 0, 0);
	TCanvas c("c","c",1000,1000);
	c.Divide(2,2);
	c.cd(1);

	TGraph *g {new TGraph()};
	for(size_t i{0}; i < 5; i++) {
		g ->SetPoint(i, log10(steps[i]), log10(errors_trapezoidi[i]));
	}

	g->SetTitle("Grafico errore bilogaritmico");
	g->GetXaxis()->SetTitle("Numero di passi");
	g->GetYaxis()->SetTitle("Errore");
	g->Draw("AL+");

	c.cd(2);
	// grafico comparazione metodi di integrazione

	// trapezoidi
	TGraph *trapezoidi {new TGraph()};
	for(size_t i{0}; i < 5; i++) {
		trapezoidi ->SetPoint(i, log10(steps[i]), log10(errors_trapezoidi[i]));
	}

	// stampa per poter usare DrawFrame
	trapezoidi->Draw("AL+");
	
	// impaginazione
	TH1 *frame = c.DrawFrame(0.9, -14., 3.1, -1.5);
	frame->SetTitle("Grafico errore");
	frame->GetXaxis()->SetTitle("Numero di passi");
	frame->GetYaxis()->SetTitle("Errore");
	c.Update();

	trapezoidi->SetLineColor(kBlue);
	trapezoidi->Draw("same");

	// simpson
	TGraph *simpson {new TGraph()};
	for(size_t i{0}; i < 5; i++) {
		simpson ->SetPoint(i, log10(steps[i]), log10(errors_simpson[i]));
	}
	simpson->SetLineColor(kRed);
	simpson->Draw("same");

	// midpoint
	TGraph *midpoint {new TGraph()};
	for(size_t i{0}; i < 5; i++) {
		midpoint ->SetPoint(i, log10(steps[i]), log10(errors_midpoint[i]));
	}
	midpoint->SetLineColor(kGreen);
	midpoint->Draw("same");

	// legenda
	auto legend = new TLegend(0.15,0.15,0.55,0.35);
	legend->SetHeader("Legenda","C");
	legend->AddEntry(trapezoidi, "Trapezoidi","l");
	legend->AddEntry(simpson, "Simpson","l");
	legend->AddEntry(midpoint, "Midpoint","l");
	legend->Draw();

	c.cd(3);
	// grafico trapezoidi precisione fissata
	TGraph *trapezoide_precisione {new TGraph()};
	for(size_t i{0}; i < 5; i++) {
		trapezoide_precisione ->SetPoint(i, log10(precisione[i]), log10(errors_trapezoidi_precisione[i]));
	}

	// stampa per poter usare DrawFrame
	trapezoide_precisione->Draw("AL+");

	// impaginazione
	
	TH1 *frame2 = c.DrawFrame(-6, -6, -0.5, -0.5);
	frame2->SetTitle("Grafico trapezoidi precisione fissata");
	frame2->GetXaxis()->SetTitle("Precisione impostata");
	frame2->GetYaxis()->SetTitle("Precisione ottenuta");
	c.Update();

	trapezoide_precisione->SetLineColor(kGreen);
	trapezoide_precisione->Draw("same");

	TGraph *trapezoide_precisione_teorico_peggiore {new TGraph()};
	for(size_t i{0}; i < 5; i++) {
		trapezoide_precisione_teorico_peggiore ->SetPoint(i, log10(precisione[i]), log10(precisione[i]));
	}
	trapezoide_precisione_teorico_peggiore->SetLineColor(kRed);
	trapezoide_precisione_teorico_peggiore->Draw("same");
	
	// legenda
	auto legend2 = new TLegend(0.15,0.65,0.55,0.85);
	legend2->SetHeader("Legenda","C");
	legend2->AddEntry(trapezoide_precisione, "Trapezoidi precisione","l");
	legend2->AddEntry(trapezoide_precisione_teorico_peggiore, "Trapezoidi precisione teorico peggiore","l");
	legend2->Draw();

	c.SaveAs("esercizio7.2.png");

	// pulizia memoria
	delete[] errors_trapezoidi;
	delete[] errors_simpson;
	delete[] errors_midpoint;
	delete[] errors_trapezoidi_precisione;

	app.Run();

	return 0;
}