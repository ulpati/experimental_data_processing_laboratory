#include "particella.h"

Particella::Particella(double massa, double carica) : m_massa{massa}, m_carica{carica} {}

Particella::~Particella() {}

void Particella::stampa() const {
	fmt::print("Particella: m = {}, q = {}", m_massa, m_carica);
}