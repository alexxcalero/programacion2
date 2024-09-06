/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Semipresencial.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:20
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

void Semipresencial::SetTotal(double total) {
	this->total = total;
}

double Semipresencial::GetTotal() const {
	return total;
}

void Semipresencial::SetDescuento(double descuento) {
	this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
	return descuento;
}

void Semipresencial::leer(ifstream &arch) {
	Alumno::leer(arch);
	arch >> descuento;
	descuento /= 100.0;
	arch.get();  // Leo el salto de linea
}

void Semipresencial::mostrar(ofstream &arch) {
	Alumno::mostrar(arch);
	arch << right << setw(23) << " " << setw(10) << setprecision(2) << fixed << Alumno::GetTotal() << endl;
}

void Semipresencial::actualizarTotal(double precioEscala) {
	double totalBruto = GetCreditos() * precioEscala;
	double montoDescontado = descuento * totalBruto;
	SetTotal(montoDescontado);
	Alumno::SetTotal(totalBruto - montoDescontado);
}
