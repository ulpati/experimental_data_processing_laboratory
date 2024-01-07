#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>

#include "ampiezza.h"

#include "../fmtlib.h"
#include "../../root/include/TApplication.h"
#include "../../root/include/TAxis.h"
#include "../../root/include/TCanvas.h"
#include "../../root/include/TGraph.h"

using namespace std;

//lettura di frazione da riga di comando
double leggi_frazione( char *str ) {
    
    //puntatore utilizzato per posizione del '/'
    char *ptr;

    double frazione = atoi(str);

    ptr = strchr(str, '/');
    
    frazione /= atoi(ptr+1);
    
    return frazione;
}

int main( int argc, char** argv ) {
    
    // inizializzazione variabili

    const double omega0 {atof(argv[1])};
    const double alpha {leggi_frazione(argv[2])};
    EquazioneDifferenzialeBase *rk{new RungeKutta()};
    PendoloForzato *pf{new PendoloForzato(omega0, alpha)};
    const double startt{0.}, lastt{(15./alpha)};

    //velocità angolare della forzante
    double omega{8.};
    
    // vettore con dati iniziali [angolo; velocità ang]
    vector<double> posizione_iniziale{0., 0.};
    const double lunghezza_passo{0.01};
    
    // matrice di dimensioni [teta_v.size()][(startt-lastt) / Passot_lenght], ogni colonna contiene tempo-angolo-velocità
    vector < vector<double> > dati {rk->Passo(omega, posizione_iniziale, startt, lastt, lunghezza_passo, pf)};
    
    // ROOT
    TApplication app("app",0,0);
	TCanvas c;
	c.Divide(2,1);

    // ampiezza oscillazione
    c.cd(1);
    cout << "\n*** Grafico angolo - tempo ***\n";
    vector <double> grafico_omega{};
    for (double i{9.01}; i < 11.01; i+=0.1)
        grafico_omega.push_back(i);
    
    TGraph grafico_oscillazione;
    for (int i{0}; i < (int)(dati[0].size()); i++)
        grafico_oscillazione.SetPoint(i,dati[0][i],dati[1][i]);
    
    grafico_oscillazione.SetTitle("Grafico oscillazione");
    grafico_oscillazione.GetXaxis()->SetTitle("t [s]");
    grafico_oscillazione.GetYaxis()->SetTitleOffset(1.5);
    grafico_oscillazione.GetYaxis()->SetTitle("x [m]");
    grafico_oscillazione.Draw("AL");

    // grafico ampiezza
    c.cd(2);
    cout << "\n*** Grafico ampiezza ***\n";
    TGraph grafico_risonanza;
    for(int i{0}; i < (int)(grafico_omega.size()); i++)
        grafico_risonanza.SetPoint(i,grafico_omega[i],ampiezza_forzata(grafico_omega[i],
        rk->Passo(grafico_omega[i],posizione_iniziale,startt,lastt,lunghezza_passo,pf),rk,pf));

    grafico_risonanza.SetTitle("Curva di risonanza");
    grafico_risonanza.GetXaxis()->SetTitle("Pulsazione [rad/s]");
    grafico_risonanza.GetYaxis()->SetTitle("Ampiezza [u.a.]");
    grafico_risonanza.Draw("AL");

    app.Run();

    return 0;
}