#pragma once

#include <iostream>
#include <cmath>

#include "RandomGen.h"

using namespace std;

class EsperimentoPrisma{
    public:
            // costruttore e distruttore
            EsperimentoPrisma();
            ~EsperimentoPrisma(){};
            
            // get
            double getLambda1() {return m_lambda1;};
            double getLambda2() {return m_lambda2;};
            double getAlpha()   {return m_alpha;};
            double getSigmaTheta()  {return m_sigmatheta;};
            double getA()   {return m_A;};
            double getAmisurato()   {return m_A_misurato;};
            double getB()   {return m_B;};
            double getBmisurato()   {return m_B_misurato;};
            double getN1()  {return m_N1;};
            double getN1misurato()  {return m_N1_misurato;};
            double getN2()  {return m_N2;};
            double getN2misurato()  {return m_N2_misurato;};
            double getTheta0()  {return m_theta0;};
            double getTheta0misurato()  {return m_theta0_misurato;};
            double getTheta1()  {return m_theta1;};
            double getTheta1misurato()  {return m_theta1_misurato;};
            double getTheta2()  {return m_theta2;};
            double getTheta2misurato()  {return m_theta2_misurato;};
            double getDelta1()  {return m_delta1;};
            double getDelta1misurato()  {return m_delta1_misurato;};
            double getDelta2()  {return m_delta2;};
            double getDelta2misurato()  {return m_delta2_misurato;};
            
            // set
            void setLambda1(double valore);
            void setLambda2(double valore);
            void setAlpha(double valore);
            void setSigmaTheta(double valore)   {m_sigmatheta = valore;}
            void setA(double valore);
            void setB(double valore);
            void setTheta0(double valore);
            
            // esegui e analizza
            void Esegui_simulazione();
            void Analizza_dati();
    
    
    private:
        RandomGen m_rgen;
        
        double m_lambda1, m_lambda2, m_alpha, m_sigmatheta;
        
        double m_A, m_A_misurato;
        double m_B, m_B_misurato;
        double m_N1, m_N1_misurato;
        double m_N2, m_N2_misurato;
        double m_theta0, m_theta0_misurato;
        double m_theta1, m_theta1_misurato;
        double m_theta2, m_theta2_misurato;
        double m_delta1, m_delta1_misurato;
        double m_delta2, m_delta2_misurato;
};