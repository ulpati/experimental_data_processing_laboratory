#include <cassert>
#include <cmath>
#include "RandomGen.h"

//test
bool are_close( double calculated, double expected, double espilon = 1e-2 ) {
  return fabs( expected - calculated ) < espilon;
}

void test_random_numbers() {

	RandomGen myGen{1};
	std::vector<double> v_unif {0.47291105054318905, 0.7385413474403322, 0.008484064601361752, 0.40976652735844254, 0.10108725726604462};
	for(size_t k{}; k < v_unif.size(); k++) {
		assert(are_close(myGen.Unif(0., 1.), v_unif[k]));
	}
	std::cout << "test uniforme ok" << std::endl;

	myGen.SetSeed(1);
	std::vector<double> v_exp {0.6403859601352556, 1.3414791243855002, 0.008520259140710315, 0.5272371040158115, 0.10656930958385337};
	for(size_t k{}; k < v_exp.size(); k++) {
		assert(are_close(myGen.Exp(1), v_exp[k]));
	}
	std::cout << "test esponenziale ok" << std::endl;
	
	myGen.SetSeed(1);
	std::vector<double> v_bm {1.9185906933235062, 1.8898847197814346, 1.9682233298032183, 2.960947466486181, 1.9538792463229713};
	for(size_t k{}; k < v_bm.size(); k++) {
		assert(are_close(myGen.Gauss(2, 1), v_bm[k]));
	}
	std::cout << "test box-muller ok" << std::endl;

	myGen.SetSeed(1);
	std::vector<double> v_ar {1.7291105054318905, 2.4952592495828867, 2.009022830054164, 0.6520544346421957, 1.318840131163597};
	for(size_t k{}; k < v_ar.size(); k++) {
		assert(are_close(myGen.GaussAR(2, 1), v_ar[k]));
	}
	std::cout << "test ar ok\n" << std::endl;
}