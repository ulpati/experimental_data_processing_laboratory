#include <iostream>
#include <cstdlib>
#include <cmath>

#include "puntoMateriale.h"
#include "campoVettoriale.h"
#include "particella.h"
#include "posizione.h"
#include "../fmtlib.h"
#include "assert.h"

#include "../../root/include/TApplication.h"
#include "../../root/include/TCanvas.h"
#include "../../root/include/TGraph.h"
#include "../../root/include/TF1.h"
#include "../../root/include/TAxis.h"


using namespace std;

int main (int argc, char **argv) {

	// test
	test_coordinate();
	test_legge_coulomb();
  
	// controllo utente
	if (argc!=4 ){
		cerr << "Uso del programma: " << argv[0]<< "<x> <y> <z>" << endl;
		return -1;
	}

	// inizializzazione variabili
	double x {atof(argv[1])};
	double y {atof(argv[2])};
	double z {atof(argv[3])};
	Posizione r(x, y, z);
	const double delta {1e-10};

	const double e {1.60217653E-19};
	const double me {9.1093826E-31};
	const double mp {1.6726217E-27};
	const double d {1.E-10};

	PuntoMateriale elettrone (me, -e, 0., 0., d/2);
	PuntoMateriale protone (mp, e, 0., 0., -d/2);

	CampoVettoriale E {elettrone.CampoElettrico(r) + protone.CampoElettrico(r)};

	// stampa
	fmt::print("E = ({}, {}, {})\n", E.getFx(), E.getFy(), E.getFz());
	cout << "Modulo E = " << E.Modulo() << endl;

	// root
	// grafiico bilogaritmico Campo Elettrico
	TApplication app ("app", 0, 0);
	TCanvas c("c","c",1000,1000);
	c.Divide(2);
	c.cd(1);

	TGraph *g {new TGraph()};
	int i {0};
	for(double dist = 100 * delta; dist <= 1000 * delta; dist += 10 * delta, i++) {
		double x {log10(dist)};
		Posizione r (0, 0, dist);
		CampoVettoriale E {elettrone.CampoElettrico(r) + protone.CampoElettrico(r)};
		double y {log10(E.Modulo())};
		g ->SetPoint(i, x, y);
	}

	g->SetTitle("Grafico bilogaritmico Campo Elettrico");
	g->GetXaxis()->SetTitle("distanza [nm]");
	g->GetYaxis()->SetTitle("campo elettrico [N/C]");
	g->Draw("AL*");

	// grafico Campo Elettrico
	c.cd(2);

	TGraph *g2 {new TGraph()};
	int j {0};
	for(double dist = 100 * delta; dist <= 1000 * delta; dist += 10 * delta, j++) {
		double x {dist};
		Posizione r (0, 0, dist);
		CampoVettoriale E {elettrone.CampoElettrico(r) + protone.CampoElettrico(r)};
		double y {E.Modulo()};
		g2 ->SetPoint(j, x, y);
	}

	g2->SetTitle("Grafico Campo Elettrico");
	g2->GetXaxis()->SetTitle("distanza [nm]");
	g2->GetYaxis()->SetTitle("campo elettrico [N/C]");
	g2->Draw();

	c.SaveAs("esercizio5.3.png");
	
	app.Run();

	return 0;
}