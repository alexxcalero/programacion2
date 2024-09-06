/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Semipresencial.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:43
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
	descuento = 0.0;
	total = 0.0;
}

Semipresencial::Semipresencial(const Semipresencial &orig) {
}

Semipresencial::~Semipresencial() {
}

void Semipresencial::SetDescuento(double descuento) {
	this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
	return descuento;
}

void Semipresencial::SetTotal(double total) {
	this->total = total;
}

double Semipresencial::GetTotal() const {
	return total;
}

void Semipresencial::leer(ifstream &arch) {
	Alumno::leer(arch);
	arch >> descuento;
	arch.get();
	descuento /= 100.0;
	total = 0.0;
}

void Semipresencial::mostrar(ofstream &arch) {
	Alumno::mostrar(arch);
	arch << setw(25) << " " << setw(10) << setprecision(2) << fixed << Alumno::GetTotal() << endl;
}

void Semipresencial::modificarTotalAbs(double total) {
	Alumno::SetTotal(total);
}
