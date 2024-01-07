#include <iostream>
#include <string>

#include "equazioneDifferenzialeBase.h"
#include "assert.h"
#include "../fmtlib.h"

#include "../../root/include/TApplication.h"
#include "../../root/include/TAxis.h"
#include "../../root/include/TCanvas.h"
#include "../../root/include/TGraph.h"

using namespace std;

int main(int argc, char** argv) {

	// test
	test_opvect();
	test_eulero();
	test_runge_kutta();
	
	if (argc != 2) {
		cerr << "Uso del programma: " << argv[0] << "<lunghezza passo>" << endl;
		return -1;
	}

	// inizializzazione variabile
	Eulero eulero;
	Runge_Kutta rk;
	OscillatoreArmonico oscarm{1.};
	double h{atof(argv[1])};
	double t {0.};
	const double startt {0.};
	const double lastt{70.};
	unsigned int npassi{(unsigned int) (lastt / h + 0.5)};
	std::vector<double> x {0.,1.};


	// deltat
	const double ki{2.}, kf{4.}, l_passo{0.2};

	vector<unsigned int> n_passi_vec((unsigned int)round((kf - ki) / l_passo + 0.6));
	double j{ki};
	for(size_t i{0}; i < n_passi_vec.size(); i++, j = ki + i * l_passo)
		n_passi_vec[i] = 7 * round(pow(10,j));

	vector<double> deltat;
	deltat = lastt / n_passi_vec;

	// valori per errore
	cout << "\n  δt [s]\t x(70s) [m]\t errore" << endl;
	vector<double> last_x_eulero(x.size());
	vector<double> last_x_rk(x.size());
	vector<double> errore_eulero(deltat.size());
	vector<double> errore_rk(deltat.size());
	int n_passi{};

	for(size_t i {0}; i < deltat.size(); i++) {
		n_passi = static_cast<int>(lastt / deltat[i] + 0.5);
		last_x_eulero = x;
		last_x_rk = x;

		for(int k {0}; k < n_passi; k++) {
			last_x_eulero = eulero.Passo(t,last_x_eulero,deltat[i],oscarm);
			last_x_rk = rk.Passo(t,last_x_rk,deltat[i],oscarm);
			t += deltat[i];
		}

        	errore_eulero[i] = fabs(last_x_eulero[0] - sin(lastt));
		errore_rk[i] = fabs(last_x_rk[0] - sin(lastt));
		fmt::print( "{0:.{2}f} \t{1:.{2}f} \t{3:.{2}f}\n", deltat[i], last_x_eulero[0], 16, errore_eulero[i] );
	}


	// ROOT
	TApplication app("app",0,0);
	TCanvas c;
	c.Divide(2,2);

	// reset di t e x perchè modificati nel calcolo dell'errore
	t = startt;
	x[0] = 0.;
	x[1] = 1.;

	// grafico oscillatore armonico Eulero
	c.cd(1);
	TGraph graficoOAeu;
	for(unsigned int i {0}; i < npassi; i++) {
		graficoOAeu.SetPoint(i, t, x[0]);
		x = eulero.Passo(startt, t, x, h, oscarm);
		t = t + h;
	}

	string titoloOAeu = "Oscillatore armonico (Eulero h = " + to_string(h) + ")" ;
	graficoOAeu.SetTitle(titoloOAeu.c_str());
	graficoOAeu.GetXaxis()->SetTitle("Tempo [s]");
	graficoOAeu.GetYaxis()->SetTitle("Posizione x [m]");
	graficoOAeu.Draw("AL");

	// reset di t e x perchè modificati per grafico oscillatore armonico Eulero
	t = startt;
	x[0] = 0.;
	x[1] = 1.;

	// grafico oscillatore armonico Runge-Kutta
	c.cd(2);
	TGraph graficoOArk;
	for(unsigned int i {0}; i < npassi; i++) {
		graficoOArk.SetPoint(i, t, x[0]);
		x = rk.Passo(startt, t, x, h, oscarm);
		t = t + h;
	}

	string titoloOArk = "Oscillatore armonico (Runge-Kutta h = " + to_string(h) + ")" ;
	graficoOArk.SetTitle(titoloOArk.c_str());
	graficoOArk.GetXaxis()->SetTitle("Tempo [s]");
	graficoOArk.GetYaxis()->SetTitle("Posizione x [m]");
	graficoOArk.Draw("AL");

	// reset di t e x perchè modificati per grafico oscillatore armonico Runge-Kutta
	t = startt;
	x[0] = 0.;
	x[1] = 1.;

	// grafico errore Eulero
	c.cd(3);
	TGraph graficoErroreeu;
	
	for(int i {0}; i < int(deltat.size()); i++) {
		graficoErroreeu.SetPoint(i, deltat[i], errore_eulero[i]);
	}

	graficoErroreeu.SetTitle("Grafico errore Eulero");
	graficoErroreeu.GetXaxis()->SetTitle("Passo d'integrazione");
	graficoErroreeu.GetYaxis()->SetTitle("Errore a t = 70.0 [s]");
	TVirtualPad::Pad()->SetLogx();
	TVirtualPad::Pad()->SetLogy();
	graficoErroreeu.GetYaxis()->SetTitleOffset(1.5);
	graficoErroreeu.Draw("AL");

	// grafico errore Runge-Kutta
	c.cd(4);
	TGraph graficoErrorerk;
	
	for(int i {0}; i < int(deltat.size()); i++) {
		graficoErrorerk.SetPoint(i, deltat[i], errore_rk[i]);
	}

	graficoErrorerk.SetTitle("Grafico errore Runge-Kutta");
	graficoErrorerk.GetXaxis()->SetTitle("Passo d'integrazione");
	graficoErrorerk.GetYaxis()->SetTitle("Errore a t = 70.0 [s]");
	TVirtualPad::Pad()->SetLogx();
	TVirtualPad::Pad()->SetLogy();
	graficoErrorerk.GetYaxis()->SetTitleOffset(1.5);
	graficoErrorerk.Draw("AL");

	app.Run();

	return 0;
}