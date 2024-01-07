#include <cmath>

#include "esperimentoPrisma.h"

EsperimentoPrisma::EsperimentoPrisma() : m_rgen(1), m_lambda1(579.1E-9), m_lambda2(404.7E-9), m_alpha(60.*M_PI/180.), m_sigmatheta(0.3E-3), m_A(2.7), m_B(60000E-18){
    
    m_N1 = sqrt(m_A + m_B/pow(m_lambda1,2));
    m_N2 = sqrt(m_A + m_B/pow(m_lambda2,2));
    
    m_theta0 = M_PI/2.;
    
    m_delta1 = 2.*asin(m_N1 * sin(0.5*m_alpha)) - m_alpha;
    m_theta1 = m_theta0 + m_delta1;
    
    m_delta1 = 2.*asin(m_N2 * sin(0.5*m_alpha)) - m_alpha;
    m_theta2 = m_theta0 + m_delta1;
}

void EsperimentoPrisma::setLambda1(double valore){
    m_lambda1 = valore;
    m_N1 = sqrt(m_A + m_B/pow(m_lambda1,2));
    m_delta1 = 2.*asin(m_N1 * sin(0.5*m_alpha)) - m_alpha;
    m_theta1 = m_theta0 + m_delta1;
}

void EsperimentoPrisma::setLambda2(double valore){
    m_lambda2 = valore;
    m_N2 = sqrt(m_A + m_B/pow(m_lambda2,2));
    m_delta1 = 2.*asin(m_N2 * sin(0.5*m_alpha)) - m_alpha;
    m_theta2 = m_theta0 + m_delta1;
}

void EsperimentoPrisma::setAlpha(double valore){
    m_alpha=valore;
    m_delta1 = 2.*asin(m_N1 * sin(0.5*m_alpha)) - m_alpha;
    m_theta1 = m_theta0 + m_delta1;
    
    m_delta1 = 2.*asin(m_N2 * sin(0.5*m_alpha)) - m_alpha;
    m_theta2 = m_theta0 + m_delta1;
}

void EsperimentoPrisma::setA(double valore){
    m_A=valore;
    m_N1 = sqrt(m_A + m_B/pow(m_lambda1,2));
    m_N2 = sqrt(m_A + m_B/pow(m_lambda2,2));
    
    m_delta1 = 2.*asin(m_N1 * sin(0.5*m_alpha)) - m_alpha;
    m_theta1 = m_theta0 + m_delta1;
    
    m_delta1 = 2.*asin(m_N2 * sin(0.5*m_alpha)) - m_alpha;
    m_theta2 = m_theta0 + m_delta1;
}

void EsperimentoPrisma::setB(double valore){
    m_B=valore;
    m_N1 = sqrt(m_A + m_B/pow(m_lambda1,2));
    m_N2 = sqrt(m_A + m_B/pow(m_lambda2,2));
    
    m_delta1 = 2.*asin(m_N1 * sin(0.5*m_alpha)) - m_alpha;
    m_theta1 = m_theta0 + m_delta1;
    
    m_delta1 = 2.*asin(m_N2 * sin(0.5*m_alpha)) - m_alpha;
    m_theta2 = m_theta0 + m_delta1;
}

void EsperimentoPrisma::setTheta0(double valore){
    m_theta0 = valore;
    m_theta1 = m_theta0 + m_delta1;
    m_theta2 = m_theta0 + m_delta1;
}

void EsperimentoPrisma::Esegui_simulazione(){
    m_theta0_misurato = m_rgen.Gauss(m_theta0, m_sigmatheta);
    m_theta1_misurato = m_rgen.Gauss(m_theta1, m_sigmatheta);
    m_theta2_misurato = m_rgen.Gauss(m_theta2, m_sigmatheta);
}

void EsperimentoPrisma::Analizza_dati(){
    m_delta1_misurato = m_theta1_misurato-m_theta0_misurato;
    m_delta2_misurato = m_theta2_misurato-m_theta0_misurato;
    m_N1_misurato = sin((m_delta1_misurato+m_alpha)/2.)/sin(m_alpha/2.);
    m_N2_misurato = sin((m_delta2_misurato+m_alpha)/2.)/sin(m_alpha/2.);
    m_A_misurato = (pow(m_lambda2*m_N2_misurato,2)-pow(m_lambda1*m_N1_misurato,2))/(pow(m_lambda2,2)-pow(m_lambda1,2));
    m_B_misurato = (pow(m_N2_misurato,2)-pow(m_N1_misurato,2))/((1/pow(m_lambda2,2))-(1/pow(m_lambda1,2)));
}