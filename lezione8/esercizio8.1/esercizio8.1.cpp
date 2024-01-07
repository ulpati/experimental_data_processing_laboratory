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
	
	if (argc != 2) {
		cerr << "Uso del programma: " << argv[0] << "<lunghezza passo>" << endl;
		return -1;
	}

	// inizializzazione variabile
	Eulero eulero;
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
	vector<double> last_x(x.size());
	vector<double> errore_eulero(deltat.size());
	int n_passi{};

	for(size_t i {0}; i < deltat.size(); i++) {
		n_passi = static_cast<int>(lastt / deltat[i] + 0.5);
		last_x = x;

		for(int k {0}; k < n_passi; k++) {
			last_x = eulero.Passo(t,last_x,deltat[i],oscarm);
			t += deltat[i];
		}

        errore_eulero[i] = fabs(last_x[0] - sin(lastt));
		fmt::print( "{0:.{2}f} \t{1:.{2}f} \t{3:.{2}f}\n", deltat[i], last_x[0], 16, errore_eulero[i] );
	}


	// ROOT
	// grafico oscillatore armonico
	TApplication app("app",0,0);
	TCanvas c;
	c.Divide(2);

	// reset di t e x perchè modificati nel calcolo dell'errore
	t = startt;
	x[0] = 0.;
	x[1] = 1.;

	c.cd(1);
	TGraph graficoOA;
	for(unsigned int i {0}; i < npassi; i++) {
		graficoOA.SetPoint(i, t, x[0]);
		x = eulero.Passo(startt, t, x, h, oscarm);
		t = t + h;
	}

	string titoloOA = "Oscillatore armonico (Eulero h = " + to_string(h) + ")" ;
	graficoOA.SetTitle(titoloOA.c_str());
	graficoOA.GetXaxis()->SetTitle("Tempo [s]");
	graficoOA.GetYaxis()->SetTitle("Posizione x [m]");
	graficoOA.Draw("AL");

	// grafico errore
	c.cd(2);
	TGraph graficoErrore;
	
	for(int i {0}; i < int(deltat.size()); i++) {
		graficoErrore.SetPoint(i, deltat[i], errore_eulero[i]);
	}

	graficoErrore.SetTitle("Grafico errore Eulero");
	graficoErrore.GetXaxis()->SetTitle("Passo d'integrazione");
	graficoErrore.GetYaxis()->SetTitle("Errore a t = 70.0 [s]");
	TVirtualPad::Pad()->SetLogx();
	TVirtualPad::Pad()->SetLogy();
	graficoErrore.GetYaxis()->SetTitleOffset(1.5);
	graficoErrore.Draw("AL");

	app.Run();

	return 0;
}