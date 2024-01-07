#pragma once

#include <cmath>
#include <cassert>
#include <iostream>

#include "integrale.h"

bool are_close(double calculated, double expected, double epsilon){
    return fabs(calculated - expected) < epsilon;
}

void test_midpoint(){
    assert(are_close(midpoint(std::sin, 0, M_PI, 10),   2.0082484079079745, 1e-16 )); //16 cfr dec
    assert(are_close(midpoint(std::sin, 0, M_PI, 100),  2.000082249070986, 1e-15)); //15 cfr dec
    assert(are_close(midpoint(std::sin, M_PI, 0, 10),  -2.0082484079079745, 1e-16)); //16 cfr dec
    assert(are_close(midpoint(std::sin, 0, 1, 10),      0.45988929071851814, 1e-17)); //17 cfr dec
    assert(are_close(midpoint(std::sin, 1, 2, 30),      0.9564934239032155, 2e-16)); //16-> errore(1.11e-16) > 1e-16!

   // per controllare se funziona anche nel semipiano negativo e con entrambi i piani
    assert(are_close(midpoint(std::sin, -M_PI, 0, 100),  -2.000082249070986, 1e-15)); //15 cfr dec 
    assert(are_close(midpoint(std::sin, 0, -1, 10),      0.45988929071851814, 1e-17)); //17 cfr dec
    assert(are_close(midpoint(std::sin, 0, -M_PI, 100),  2.000082249070986, 1e-15)); //15 cfr dec
    assert(are_close(midpoint(std::sin, -M_PI, 1, 10),  -1.55136616452649823, 1e-17)); //17 cfr dec

    std::cerr << "Tutti i test midpoint passati con successo" << std::endl;
}