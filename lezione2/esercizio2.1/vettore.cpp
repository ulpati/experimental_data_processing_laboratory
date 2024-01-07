#include "vettore.h"

// costruttore di default
Vettore::Vettore() {
	std::cerr << "Invocazione del costruttore di default" << std::endl;
	m_N = 0;
	m_v = nullptr;
}

// costruttore con dimensione del vettore
Vettore::Vettore(size_t N) {
	std::cerr << "Invocazione del costruttore con argomenti" << std::endl;
	m_N = N;
	m_v = new double[N];
	for(size_t k {0}; k < N; k++) m_v[k] = 0;	
}

// copia costruttore
Vettore::Vettore(const Vettore& V) {
	m_N = V.GetN();
	m_v = new double[m_N];
	for(size_t i {0}; i < m_N; i++) m_v[i] = V.GetComponent(i);
}

// distruttore
Vettore::~Vettore() {
	std::cerr << "Invocazione del distruttore " << std::endl;
	delete[] m_v;
}

// modifica la componente i-esima
void Vettore::SetComponent(size_t i, double a) {
	assert((i < m_N) && "Errore: l'indice è troppo grande");
	m_v[i] = a;
}

// accede alla componente i-esima
double Vettore::GetComponent(size_t i) const {
	assert((i < m_N) && "Errore: l'indice è troppo grande");
	return m_v[i];
}

void Vettore::Scambia(size_t primo, size_t secondo) {
	double temp {m_v[primo]};
	m_v[primo] = m_v[secondo];
	m_v[secondo] = temp;
}

double& Vettore::operator[] (size_t i) {
	assert((i < m_N) && "Errore: l'indice è troppo grande");
	return m_v[i];
}

// operatore di assegnazione
Vettore& Vettore::operator=(const Vettore& V) {
	m_N = V.GetN();
	if (m_v) delete[] m_v;

	m_v = new double[m_N];

	for(size_t i{0}; i < m_N; i++) m_v[i] = V.GetComponent(i);

	return *this;
}