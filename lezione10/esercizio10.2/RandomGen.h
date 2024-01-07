#pragma once

class RandomGen {
	public:
		RandomGen(unsigned int seed) {m_seed = seed; m_a = 1664525; m_c = 1013904223; m_m = pow(2, 31);}
		void SetA(unsigned int a) {m_a = a;}
		void SetC(unsigned int c) {m_c = c;}
		void SetM(unsigned int m) {m_m = m;}
		void SetSeed(unsigned int seed) {m_seed = seed;}


		double Rand() {
			return Unif(0., 1.);
		}
		double Unif(double xmin, double xmax) {
			m_seed = (m_a * m_seed + m_c) % m_m;
			return xmin + (xmax - xmin) * m_seed / m_m;
		}
		
		double Exp(double mean) {
			return (-1/mean)*log(1-Unif(0., 1.));
		}

		double Gaus(double mean, double sigma) {
			return mean + sigma * (sqrt(-2 * log(1 - Rand())) * cos(2 * M_PI * Rand()));
		}

		double GausAR(double mean, double sigma) {
			double x, y, f;
			while (true) {
				x = Unif(-5., 5.);
				y = Rand();
				f = exp(-pow(x, 2) / 2);
				if(y <= f) return mean + x * sigma;
			}
		}

	private:
		unsigned int m_a, m_c, m_m;
		unsigned int m_seed;
};