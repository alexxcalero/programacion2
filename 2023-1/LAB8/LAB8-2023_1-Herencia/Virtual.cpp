/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Virtual.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:44
 */

#include "Virtual.h"

Virtual::Virtual() {
	licencia = nullptr;
	total = 0.0;
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
	char lic[100];
	arch.getline(lic, 100, '\n');
	SetLicencia(lic);
	total = 0.0;
}

void Virtual::mostrar(ofstream &arch) {
	Alumno::mostrar(arch);
	char licencia[100];
	GetLicencia(licencia);
	arch << setw(10) << " ";
	arch << left << setw(15) << licencia << right << setw(10);
	arch << setprecision(2) << fixed << Alumno::GetTotal() << endl;
}

void Virtual::modificarTotalAbs(double total) {
	Alumno::SetTotal(total);
}
