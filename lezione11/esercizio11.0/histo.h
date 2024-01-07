#pragma once

#include "../../root/include/TH1F.h"
#include "../../root/include/TH2F.h"
#include "../../root/include/TAxis.h"

void SetHisto1(TH1F &histo, const Color_t colore, const char* asse_x, const char* asse_y)
{
    histo.StatOverflows(kTRUE);
    histo.GetXaxis()->SetTitle(asse_x);
    histo.GetYaxis()->SetTitle(asse_y);
    histo.GetYaxis()->SetTitleOffset(1.5);
    histo.SetLineColor(colore);
    histo.Draw();
}

void SetHisto2(TH2F &histo, const char* asse_x, const char* asse_y)
{
    histo.StatOverflows(kTRUE);
    histo.GetXaxis()->SetTitle(asse_x);
    histo.GetYaxis()->SetTitle(asse_y);
    histo.GetYaxis()->SetTitleOffset(1.5);
    histo.Draw();
}