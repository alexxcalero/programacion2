/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Presencial.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:40
 */

#include "Presencial.h"

Presencial::Presencial() {
	recargo = 0.0;
	total = 0.0;
}

Presencial::Presencial(const Presencial &orig) {
}

Presencial::~Presencial() {
}

void Presencial::SetRecargo(double recargo) {
	this->recargo = recargo;
}

double Presencial::GetRecargo() const {
	return recargo;
}

void Presencial::SetTotal(double total) {
	this->total = total;
}

double Presencial::GetTotal() const {
	return total;
}

void Presencial::leer(ifstream &arch) {
	Alumno::leer(arch);
	arch >> recargo;
	arch.get();
	recargo /= 100.0;
	total = 0.0;
}

void Presencial::mostrar(ofstream &arch) {
	Alumno::mostrar(arch);
	arch << setw(25) << " " << setw(10) << setprecision(2) << fixed << Alumno::GetTotal() << endl;
}

void Presencial::modificarTotalAbs(double total) {
	Alumno::SetTotal(total);
}
