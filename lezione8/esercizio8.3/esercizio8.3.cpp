#include <iostream>
#include <cstdlib>
#include <vector>

#include "equazioneDifferenzialeBase.h"
#include "opvect.h"
#include "periodoPendolo.h"
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
	test_interpolazione();

	// controllo utente
	if (argc != 3) {
		cerr << "Uso del programma: " << argv[0] << " <lunghezza corda> <costante accelerazione>\n" << endl;
		return -1;
	}

	// inizializzazione variabili
	const double lunghezza_corda {atof(argv[1])};
	const double g {atof(argv[2])};

	Runge_Kutta rk;
	Pendolo pendolo(lunghezza_corda, g);

	const double startt{0.}, lastt{3.};
	vector<double> theta {M_PI / 3., 0.};
	const double l_passo{0.01};

	vector < vector<double> > dati {rk.Passo(startt,lastt,theta,l_passo,pendolo)};

	// stampa
	cout << "\n tempo [s], \t theta[rad],	\t omega[rad/s] \n\n";
	for (size_t i {0}; i < dati[0].size(); i++) {
		cout << "[";
		for(size_t j {0}; j < dati.size()-1; j++)
			cout << dati[j][i] << ",           \t";
		cout << dati[dati.size()-1][i] << "]\n";
	}

	double periodo_ideale {2 * M_PI / sqrt(g / lunghezza_corda)};
	fmt::print("\n\n periodo ideale -> {0:.{3}f} \t\t- periodo per 0 =  {2:.4f} - > {1:.{3}f}\n\n", periodo_ideale, periodo(dati), theta[0], 16);

	// ROOT
	TApplication app("app",0,0);
	TCanvas c;
	c.Divide(2);

	// grafico periodo in funzione di theta
	cout << "\n Grafico Pendolo T(theta)\n";
	const double start_theta{0.1}, last_theta{3.};
	const double l_passo_theta{0.1};
	const int ntheta_passi = round((last_theta - start_theta) / l_passo_theta + 0.6);
	
	// theta per grafico
	vector < vector<double> > theta_grafico(ntheta_passi, vector<double>(theta.size()));
	for(size_t i {0}; i < theta_grafico.size(); i++)
		theta_grafico[i] = {start_theta + i * l_passo_theta, 0.};

	TGraph grafico_periodo;
	c.cd(1);
	double Periodo;
	double lastt_expandable = lastt;
	vector< vector<double> > dati_grafico;
	for(size_t i{0}; i < theta_grafico.size(); i++) {
		dati_grafico = rk.Passo(startt,lastt_expandable,theta_grafico[i],l_passo,pendolo);

		Periodo = periodo(dati_grafico);

		if (Periodo > 0){
			grafico_periodo.SetPoint(i, theta_grafico[i][0], Periodo);

			cout << "lastt : " << lastt_expandable << "\t" 
			<< "theta : " << theta_grafico[i][0] << "\t"
			<< "Periodo : " << Periodo <<endl;
		}
		else {
			fmt::print("\tAumentare il tempo della simulazione di {0}s (=50*lunghezza passo) \n", l_passo*50);
				lastt_expandable += l_passo*50;
				i--;
		}

		dati_grafico.clear();
	}

	grafico_periodo.SetTitle("Grafico periodo in funzione dell'angolo di oscillazione");
	grafico_periodo.GetXaxis()->SetTitle("theta [rad]");
	grafico_periodo.GetYaxis()->SetTitle("Periodo [s]");
	grafico_periodo.Draw("AL");

	//grafico omega in funzione del tempo
	TGraph grafico_omega;
	c.cd(2);

	for(unsigned int i{0}; i < (unsigned int)(dati[0].size()); i++)
		grafico_omega.SetPoint(i, dati[0][i], dati[2][i]);

	grafico_omega.SetTitle("Grafico velocità angolare in funzione del tempo");
	grafico_omega.GetXaxis()->SetTitle("Tempo [s]");
	grafico_omega.GetYaxis()->SetTitle("Velocità angolare [rad/s]");
	grafico_omega.Draw("AL");
	app.Run();

	return 0;
}