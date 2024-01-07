#pragma once

#include "funzioneBase.h"

class Solutore {
        
    public:
        Solutore() { m_niterazioni = 0; }
        Solutore( double precisione ) : Solutore() { m_precisione = precisione; m_incertezza = precisione; }
        virtual ~Solutore() {}

        virtual double CercaZeriReference( double xmin, double xmax, const FunzioneBase & f ) = 0;
        
        void SetPrecisione( double epsilon ) { m_precisione = epsilon; }
        double GetPrecisione() const { return m_precisione;}
        
        void SetNMaxIterazioni( unsigned int n ) { m_nmax = n; }
        int GetNMaxIterazioni() const { return m_nmax; }
        unsigned int GetNiterazioni() const { return m_niterazioni; }

        virtual bool Trovato( double zero ) const = 0;
        virtual double GetIncertezza() const = 0;

    protected:
        double m_a, m_b; // estremi zona di ricerca
        double m_precisione;
        double m_incertezza;
        unsigned int m_nmax, m_niterazioni;
};