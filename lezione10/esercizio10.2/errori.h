#pragma once

#include <cmath>
#include <vector>

// deviazione standard

double devstd (std::vector<double> &data) {
	double sum{0};
	for(unsigned int i = 0; i < data.size(); i++) sum += data[i];
	double media{sum / data.size()};
	double s2{0};
	for(unsigned int i = 0; i < data.size(); i++) s2 += pow(data[i] - media, 2);

	return sqrt(s2 / data.size());
}

double trova_k(double devstd, unsigned int n) {
	return sqrt(n) * devstd;
}

double noptim(double k) {
	return round(pow(k / 0.001, 2));
}