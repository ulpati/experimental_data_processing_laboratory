#pragma once

#include <cmath>
#include <cassert>
#include <iostream>
#include "integrale.h"

bool are_close(double calculated, double expected, double epsilon){
    return fabs(calculated - expected) < epsilon;
}

void test_simpson(){
    assert(are_close(simpson(std::sin, 0, M_PI, 10),   2.0001095173150043, 1e-16 )); //16 cfr dec
    assert(are_close(simpson(std::sin, 0, M_PI, 100),  2.000000010824504, 1e-15)); //15 cfr dec
    assert(are_close(simpson(std::sin, 0, 1, 10),      0.45969794982382056, 1e-17)); //17 cfr dec
    assert(are_close(simpson(std::sin, 1, 2, 30),      0.9564491489761575, 1e-16)); //16 cfr dec

    std::cerr << "Tutti i test simpson passati con successo" << std::endl;
}