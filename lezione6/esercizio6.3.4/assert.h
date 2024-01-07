#include <cassert>
#include <cmath>
#include "tangente.h"
#include "bisezione.h"


//test
bool are_close( double calculated, double expected, double espilon = 1e-2 ) {
  return fabs( expected - calculated ) < espilon;
}

void test_zeroes() {
  Bisezione s{};
  Tangente f{};
  s.SetPrecisione(1.0e-8);
  s.SetNMaxIterazioni(100);

  assert(are_close(s.CercaZeriReference(-5.0, -4.0, f), -4.5));
  std::cout << "assert zero compreso in [a,b] ok" << std::endl;
  assert(are_close(s.CercaZeriReference(5.0, 10.0, f), 7.72));
  std::cout << "assert zero compreso in [a,b] ok" << std::endl;
  assert(are_close(s.CercaZeriReference(-4.5, -1.0, f), -4.5));
  std::cout << "assert zero = a ok" << std::endl;
  assert(are_close(s.CercaZeriReference(2.0, 4.5, f), 4.5));
  std::cout << "assert zero = b ok" << std::endl;
}