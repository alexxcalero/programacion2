/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Presencial.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:19
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

void Presencial::SetTotal(double total) {
	this->total = total;
}

double Presencial::GetTotal() const {
	return total;
}

void Presencial::SetRecargo(double recargo) {
	this->recargo = recargo;
}

double Presencial::GetRecargo() const {
	return recargo;
}

void Presencial::leer(ifstream &arch) {
	Alumno::leer(arch);
	arch >> recargo;
	recargo /= 100.0;
	arch.get();  // Leo el salto de linea
}

void Presencial::mostrar(ofstream &arch) {
	Alumno::mostrar(arch);
	arch << right << setw(23) << " " << setw(10) << setprecision(2) << fixed << Alumno::GetTotal() << endl;
}

void Presencial::actualizarTotal(double precioEscala) {
	double totalBruto = GetCreditos() * precioEscala;
	double montoRecargo = recargo * totalBruto;
	SetTotal(montoRecargo);
	Alumno::SetTotal(totalBruto + montoRecargo);
}
