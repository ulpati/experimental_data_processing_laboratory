#include "particella.h"
#include "elettrone.h"

Elettrone::Elettrone() : Particella{9.1093826e-31, -1.60217653e-19} {}

Elettrone::~Elettrone() {}

void Elettrone::stampa() const {
	fmt::print("Elettorone: m = {}, q = {}", m_massa, m_carica);
}