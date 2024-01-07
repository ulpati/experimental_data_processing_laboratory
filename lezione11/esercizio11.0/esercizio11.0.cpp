#include <iostream>

#include "assert.h"
#include "esperimentoPrisma.h"
#include "histo.h"
#include "RandomGen.h"

#include "../../root/include/TApplication.h"
#include "../../root/include/TCanvas.h"
#include "../../root/include/TGraph.h"

using namespace std;

int main(int argc, const char * argv[]) {

    // test
    test_random_numbers();

    // ROOT
    // inizializzazione variabili
    TApplication app("app", 0, 0);
    EsperimentoPrisma prisma;
    const int n_simulazione {10000};

    // theta
    TCanvas theta("theta", "Angoli theta");
    theta.Divide(3,1);
    TH1F histoTheta0("Theta 0", "Theta 0", 100, prisma.getTheta0()-3*prisma.getSigmaTheta(), prisma.getTheta0()+3*prisma.getSigmaTheta());
    TH1F histoTheta1("Theta 1", "Theta 1", 100, prisma.getTheta1()-3*prisma.getSigmaTheta(), prisma.getTheta1()+3*prisma.getSigmaTheta());
    TH1F histoTheta2("Theta 2", "Theta 2", 100, prisma.getTheta2()-3*prisma.getSigmaTheta(), prisma.getTheta2()+3*prisma.getSigmaTheta());

    // delta
    TCanvas delta("delta", "Delta");
    delta.Divide(3,1);
    TH1F histoDelta1("delta1 misurati", "delta1 misurati", 100, 0.975, 0.982);
    TH1F histoDelta2("delta2 misurati", "delta2 misurati", 100, 1.0841, 1.088);
    TH2F histoDELTA("DELTA misurati", "DELTA misurati", 100, 0.975, 0.982, 100, 1.0841, 1.088);

    // n
    TCanvas n("n", "indici di rifrazione n");
    n.Divide(3,1);
    TH1F histoN1("n1 misurati", "n1 misurati", 100, 1.695, 1.698);
    TH1F histoN2("n2 misurati", "n2 misurati", 100, 1.749, 1.752);
    TH2F histoN("n misurati", "n misurati", 100, 1.695, 1.698, 100, 1.749, 1.752);

    // A e B
    TCanvas AeB("AeB", "A e B");
    AeB.Divide(3,1);
    TH1F histoA("A misurati", "A misurati", 100, 2.695, 2.705);
    TH1F histoB("B misurati", "B misurati", 100, 5.9e-14, 6.1e-14);
    TH2F histoAB("AB misurati", "AB misurati", 100, 2.695, 2.705, 100, 5.9e-14, 6.1e-14);

    double mediaDelta12 {0}; // media delta1*delta2
    double median1n2 {0}; // media n1*n2
    double mediaAB {0}; // media A*B

    // esecuzione esperimento
    for(int i{0}; i<n_simulazione; i++){

        prisma.Esegui_simulazione();
        prisma.Analizza_dati();
        
        histoTheta0.Fill(prisma.getTheta0misurato());
        histoTheta1.Fill(prisma.getTheta1misurato());
        histoTheta2.Fill(prisma.getTheta2misurato());

        histoDelta1.Fill(prisma.getDelta1misurato());
        histoDelta2.Fill(prisma.getDelta2misurato());
        histoDELTA.Fill(prisma.getDelta1misurato(), prisma.getDelta2misurato());

        mediaDelta12 = ((i*1.) / (i+1) * mediaDelta12)  +  1./(i+1)*(prisma.getDelta1misurato())*(prisma.getDelta2misurato());

        histoN1.Fill(prisma.getN1misurato());
        histoN2.Fill(prisma.getN2misurato());
        histoN.Fill(prisma.getN1misurato(),prisma.getN2misurato());
        
        median1n2 = ((i*1.) / (i+1) * median1n2)  +  1./(i+1)*(prisma.getN1misurato())*(prisma.getN2misurato());
        
        histoA.Fill(prisma.getAmisurato());
        histoB.Fill(prisma.getBmisurato());
        histoAB.Fill(prisma.getAmisurato(),prisma.getBmisurato());
        
        mediaAB = ((i*1.) / (i+1) * mediaAB)  +  1./(i+1)*(prisma.getAmisurato())*(prisma.getBmisurato());
    }

    // stampa grafici
    // theta
    theta.cd(1);
    SetHisto1(histoTheta0,kRed,"Valori di Theta0","Numero eventi");
    theta.cd(2);
    SetHisto1(histoTheta1,kBlue,"Valori di Theta1","Numero eventi");
    theta.cd(3);
    SetHisto1(histoTheta2,kGreen,"Valori di Theta2","Numero eventi");

    // delta
    delta.cd(1);
    SetHisto1(histoDelta1,kRed,"Valori di delta1 misurato","Numero eventi");
    delta.cd(2);
    SetHisto1(histoDelta2,kBlue,"Valori di delta2 misurato","Numero eventi");
    delta.cd(3);
    SetHisto2(histoDELTA,"Valori di delta1 misurato","Valori di delta2 misurato");

    // n
    n.cd(1);
    SetHisto1(histoN1,kRed,"Valori di n1 misurato","Numero eventi");
    n.cd(2);
    SetHisto1(histoN2,kBlue,"Valori di n2 misurato","Numero eventi");
    n.cd(3);
    SetHisto2(histoN,"Valori di n1 misurato","Valori di n2 misurato");

    // A e B
    AeB.cd(1);
    SetHisto1(histoA,kRed,"Valori di A misurato","Numero eventi");
    AeB.cd(2);
    SetHisto1(histoB,kRed,"Valori di B misurato","Numero eventi");
    AeB.cd(3);
    SetHisto2(histoAB,"Valori di A misurato","Valori di B misurato");

    // stampa
    cout << "Theta0 misurato = " << histoTheta0.GetMean() << " ± " << histoTheta0.GetStdDev() << endl;
    cout << "Theta1 misurato = " << histoTheta1.GetMean() << " ± " << histoTheta1.GetStdDev() << endl;
    cout << "Theta2 misurato = " << histoTheta2.GetMean() << " ± " << histoTheta2.GetStdDev() << endl;

    cout << "delta1 = " << histoDelta1.GetMean() << " ± " << histoDelta1.GetStdDev() << endl;
    cout << "delta2 = " << histoDelta2.GetMean() << " ± " << histoDelta2.GetStdDev() << endl;
    cout << "Coefficiente di correlazione = " << (mediaDelta12-histoDelta1.GetMean()*histoDelta2.GetMean())/(histoDelta1.GetStdDev()*histoDelta2.GetStdDev()) << endl;

    cout << "n1 = " << histoN1.GetMean() << " ± " << histoN1.GetStdDev() << endl;
    cout << "n2 = " << histoN2.GetMean() << " ± " << histoN2.GetStdDev() << endl;
    cout << "Coefficiente di correlazione = " << (median1n2-histoN1.GetMean()*histoN2.GetMean())/(histoN1.GetStdDev()*histoN2.GetStdDev()) << endl;

    cout << "A = " << histoA.GetMean() << " ± " << histoA.GetStdDev() << endl;
    cout << "B = " << histoB.GetMean() << " ± " << histoB.GetStdDev() << endl;
    cout << "Coefficiente di correlazione = " << (mediaAB-histoA.GetMean()*histoB.GetMean())/(histoA.GetStdDev()*histoB.GetStdDev()) << endl;

    app.Run();

    return 0;
}