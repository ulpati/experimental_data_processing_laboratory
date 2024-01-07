#include <iostream>
#include <vector>
#include <cmath>

#include "RandomGen.h"
#include "assert.h"
#include "integrale.h"
#include "errori.h"
#include "../fmtlib.h"

#include "../../root/include/TApplication.h"
#include "../../root/include/TCanvas.h"
#include "../../root/include/TH1F.h"
#include "../../root/include/TAxis.h"

using namespace std;

int main() {

	// test
	test_integrale();

	// integrale della media
	RandomGen myGen{1};
	fmt::print("Integrale (metodo media): {0:.{1}f}\n", intmean(sin, 0, M_PI, 100, myGen), 16);

	// integrale hit or miss
	myGen.SetSeed(1);
	fmt::print("Integrale (metodo hit-or-miss): {0:.{1}f}\n", inthm(sin, 0, M_PI, 1, 100, myGen), 16);
	
	// ROOT
	TApplication app {"app", 0, 0};
	TCanvas c("Grafici","Grafici");
	c.Divide(2,2);

	// grafico integrale della media n = 100
	c.cd(1);
	myGen.SetSeed(1);
	
	vector<double> samples_intmean(10000);
	for(size_t k{}; k < samples_intmean.size(); k++) {
		samples_intmean[k] = intmean(sin, 0, M_PI, 100, myGen);
	}

	// calcolo e stampa k N
	double devstdmean {devstd(samples_intmean)};
	double k_mean {trova_k(devstdmean, 100)};
	double noptim_mean {noptim(k_mean)};
	fmt::print("k con n = 100 (media) = {0:.{1}f}\n", k_mean, 16);
	fmt::print("N con n = 100 (media) = {0}\n", noptim_mean);

	TH1F mean{"Mean", "Mean", 100, 1, 3};
	for(double sample : samples_intmean) mean.Fill(sample);
	mean.GetXaxis()->SetTitle("Valore integrale");
	mean.GetYaxis()->SetTitle("Numero di campioni");
	mean.SetFillColor(kRed);
	mean.Draw("BAR4");

	// grafico integrale hit or miss con n = 100
	c.cd(2);
	myGen.SetSeed(1);

	vector<double> samples_inthm(10000);
	for(size_t k{}; k < samples_inthm.size(); k++) {
		samples_inthm[k] = inthm(sin, 0, M_PI, 1, 100, myGen);
	}
	
	// calcolo e stampa k N
	double devstdhm {devstd(samples_inthm)};
	double k_hm {trova_k(devstdhm, 100)};
	double noptim_hm {noptim(k_hm)};
	fmt::print("k con n = 100 (hit-or-miss) = {0:.{1}f}\n", k_hm, 16);
	fmt::print("N con n = 100 (hit-or-miss) = {0}\n", noptim_hm);

	TH1F hm{"Hit or miss", "Hit or miss", 100, 1, 3};
	for(double sample : samples_inthm) hm.Fill(sample);
	hm.GetXaxis()->SetTitle("Valore integrale");
	hm.GetYaxis()->SetTitle("Numero di campioni");
	hm.SetFillColor(kBlue);
	hm.Draw("BAR4");

	// istogramma metodo media ottimizzato
	c.cd(3);
	myGen.SetSeed(1);
	cout << "Creazione istogramma metodo media ottimizzato" << endl;
	TH1F histo("histo","histo",14,1.996,2.004);
	vector<double> samples_intmean_opt(1000);
	for(size_t i{0}; i < samples_intmean_opt.size(); i++) {
		samples_intmean_opt[i] = intmean(sin, 0, M_PI, noptim_mean, myGen);
		histo.Fill(samples_intmean_opt[i]);
	}
	
	histo.SetTitle("Istogramma metodo media ottimizzato");
	histo.GetXaxis()->SetTitle("Valore integrale");
	histo.GetYaxis()->SetTitle("Numero di campioni");
	histo.Draw();

	// istogramma metodo hit or miss ottimizzato
	c.cd(4);
	myGen.SetSeed(1);
	cout << "Creazione istogramma metodo hit-or-miss ottimizzato" << endl;
	TH1F histohm("histohm","histohm",14,1.995,2.005);
	vector<double> samples_inthm_opt(1000);
	for(size_t i{0}; i < samples_inthm_opt.size(); i++) {
		samples_inthm_opt[i] = inthm(sin, 0, M_PI, 1, noptim_hm, myGen);
		histohm.Fill(samples_inthm_opt[i]);
	}
	
	histohm.SetTitle("Istogramma metodo Hit or miss ottimizzato");
	histohm.GetXaxis()->SetTitle("Valore integrale");
	histohm.GetYaxis()->SetTitle("Numero di campioni");
	histohm.Draw();

	app.Run();

	return 0;
}