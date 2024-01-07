#pragma once

#include <cmath>
#include <cassert>
#include <iostream>
#include "integrale.h"

bool are_close(double calculated, double expected, double epsilon){
    return fabs(calculated - expected) < epsilon;
}

void test_trapezoidi(){
    unsigned int steps[] = {10, 30, 100};
    assert(are_close(trapezoidi(std::sin, 0, M_PI, steps[0]), 1.9835235375094546, 1e-16 )); //16 cfr dec
    assert(are_close(trapezoidi(std::sin, 0, 1, steps[0]), 0.45931454885797635, 1e-17)); //17 cfr dec
    assert(are_close(trapezoidi(std::sin, 1, 2, steps[1]), 0.956360580669458, 1e-15)); //15 cfr dec
    assert(are_close(trapezoidi(std::sin, 0, M_PI, steps[2]), 1.9998355038874436, 1e-16)); //16 cfr dec

    std::cerr << "Tutti i test trapezoidi passati con successo" << std::endl;
}

void test_simpson(){
    assert(are_close(simpson(std::sin, 0, M_PI, 10),   2.0001095173150043, 1e-16 )); //16 cfr dec
    assert(are_close(simpson(std::sin, 0, M_PI, 100),  2.000000010824504, 1e-15)); //15 cfr dec
    assert(are_close(simpson(std::sin, 0, 1, 10),      0.45969794982382056, 1e-17)); //17 cfr dec
    assert(are_close(simpson(std::sin, 1, 2, 30),      0.9564491489761575, 1e-16)); //16 cfr dec

    std::cerr << "Tutti i test simpson passati con successo" << std::endl;
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