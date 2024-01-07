#include <iostream>
#include <vector>
#include <cmath>
#include "RandomGen.h"
#include "assert.h"
#include "../../root/include/TApplication.h"
#include "../../root/include/TCanvas.h"
#include "../../root/include/TH1F.h"
#include "../../root/include/TAxis.h"

using namespace std;

int main() {

	test_random_numbers();

	RandomGen myGen{1};

	// uniforme
	vector<double> samples_unif(10000);
	cout << "Uniforme" << endl;
	for(size_t k{}; k < samples_unif.size(); k++) {
		samples_unif[k] = myGen.Unif(0., 1.);
		if ( k < 10) cout << samples_unif[k] << endl;
	}

	// esponenziale
	myGen.SetSeed(1);
	vector<double> samples_exp(10000);
	cout << "Esponenziale" << endl;
	for(size_t k{}; k < samples_exp.size(); k++) {
		samples_exp[k] = myGen.Exp(1);
		if ( k < 10) cout << samples_exp[k] << endl;
	}

	// box-muller
	myGen.SetSeed(1);
	vector<double> samples_bm(10000);
	cout << "box-muller" << endl;
	for(size_t k{}; k < samples_bm.size(); k++) {
		samples_bm[k] = myGen.Gauss(2, 1);
		if ( k < 10) cout << samples_bm[k] << endl;
	}

	// ar
	myGen.SetSeed(1);
	vector<double> samples_ar(10000);
	cout << "ar" << endl;
	for(size_t k{}; k < samples_ar.size(); k++) {
		samples_ar[k] = myGen.GaussAR(2, 1);
		if ( k < 10) cout << samples_ar[k] << endl;
	}

	// ROOT
	TApplication app {"app", 0, 0};
	TCanvas c("Grafici","Grafici");
	c.Divide(2,2);
	
	// grafico uniforme
	c.cd(1);
	TH1F unif{"Uniforme", "Uniforme", 100, -0.5, 1.5};
	for(double sample : samples_unif) unif.Fill(sample);
	unif.GetXaxis()->SetTitle("x [AU]");
	unif.GetYaxis()->SetTitle("Numero di campioni");
	unif.Draw();
	
	// grafico esponenziale
	c.cd(2);
	TH1F exp{"Esponenziale", "Esponenziale", 100, -1, 9};
	for(double sample : samples_exp) exp.Fill(sample);
	exp.GetXaxis()->SetTitle("x [AU]");
	exp.GetYaxis()->SetTitle("Numero di campioni");
	exp.Draw();

	// grafico box-muller
	c.cd(3);
	TH1F bm{"Box-Muller", "Box-Muller", 100, -6, 8};
	for(double sample : samples_bm) bm.Fill(sample);
	bm.GetXaxis()->SetTitle("x [AU]");
	bm.GetYaxis()->SetTitle("Numero di campioni");
	bm.Draw();

	// grafico box-muller
	c.cd(4);
	TH1F ar{"Gausss AR", "Gausss AR", 100, -6, 8};
	for(double sample : samples_ar) ar.Fill(sample);
	ar.GetXaxis()->SetTitle("x [AU]");
	ar.GetYaxis()->SetTitle("Numero di campioni");
	ar.Draw();
	
	app.Run();
	return 0;
}