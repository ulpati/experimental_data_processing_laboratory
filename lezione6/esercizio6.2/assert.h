#pragma once

#include <cassert>
#include <cmath>
#include "parabola.h"
#include "bisezione.h"


//test
bool are_close( double calculated, double expected, double espilon = 1e-2 ) {
  return fabs( expected - calculated ) < espilon;
}

void test_zeroes() {
  Bisezione s{};
  Parabola f{3, 5, -2}; // zeri noti, x₁ = −2, x₂ = 1/3
  s.SetPrecisione(1.0e-8);
  s.SetNMaxIterazioni(100);

  assert(are_close(s.CercaZeriReference(-3.0, -1.0, f), -2.0));
  std::cout << "assert zero compreso in [a,b] ok" << std::endl;
  assert(are_close(s.CercaZeriReference(0.0, 1.0, f), 1.0 / 3));
  std::cout << "assert zero compreso in [a,b] ok" << std::endl;
  assert(are_close(s.CercaZeriReference(-2.0, 0.0, f), -2.0));
  std::cout << "assert zero = a ok" << std::endl;
  assert(are_close(s.CercaZeriReference(-4.0, -2.0, f), -2.0));
  std::cout << "assert zero = b ok" << std::endl;
}