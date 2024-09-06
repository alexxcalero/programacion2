/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Virtual.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:21
 */

#include "Virtual.h"

Virtual::Virtual() {
	licencia = nullptr;
	total = 0;
}

Virtual::Virtual(const Virtual &orig) {
}

Virtual::~Virtual() {
	if(licencia != nullptr) delete licencia;
}

void Virtual::SetTotal(double total) {
	this->total = total;
}

double Virtual::GetTotal() const {
	return total;
}

void Virtual::SetLicencia(const char *licencia) {
	if(this->licencia != nullptr) delete this->licencia;
	this->licencia = new char[strlen(licencia) + 1];
	strcpy(this->licencia, licencia);
}

void Virtual::GetLicencia(char *licencia) const {
	if(this->licencia == nullptr) licencia[0] = 0;
	else strcpy(licencia, this->licencia);
}

void Virtual::leer(ifstream &arch) {
	Alumno::leer(arch);
	char licencia[100];
	arch.getline(licencia, 100, '\n');
	SetLicencia(licencia);
}

void Virtual::mostrar(ofstream &arch) {
	Alumno::mostrar(arch);
	char licencia[100];
	GetLicencia(licencia);
	arch << right << setw(8) << " " << left << setw(15) << licencia;
	arch << right << setw(10) << setprecision(2) << fixed << Alumno::GetTotal() << endl;
}

void Virtual::actualizarTotal(double precioEscala) {
	double totalBruto = GetCreditos() * precioEscala;
	SetTotal(100);
	Alumno::SetTotal(totalBruto + 100);
}
