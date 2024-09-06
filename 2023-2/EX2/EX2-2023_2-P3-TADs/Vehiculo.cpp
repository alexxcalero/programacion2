/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : Vehiculo.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:31
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
	cargaActual = 0.0;
}

Vehiculo::Vehiculo(const Vehiculo &orig) {
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetCargaActual(double cargaActual) {
	this->cargaActual = cargaActual;
}

double Vehiculo::GetCargaActual() const {
	return cargaActual;
}

void Vehiculo::SetCargaMaxima(double cargaMaxima) {
	this->cargaMaxima = cargaMaxima;
}

double Vehiculo::GetCargaMaxima() const {
	return cargaMaxima;
}

void Vehiculo::SetPlaca(string placa) {
	this->placa = placa;
}

string Vehiculo::GetPlaca() const {
	return placa;
}

void Vehiculo::SetDni(int dni) {
	this->dni = dni;
}

int Vehiculo::GetDni() const {
	return dni;
}

void Vehiculo::leer(ifstream &arch) {
	char plaquita[100], c;
	arch >> dni >> c;
	arch.getline(plaquita, 100, ',');
	placa = plaquita;
	arch >> cargaMaxima >> c;
	cargaActual = 0;
}

void Vehiculo::mostrar(ofstream &arch) {
	arch << left << setw(25) << "Codigo de cliente: ";
	arch << dni << endl;
	arch << left << setw(25) << "Placa: ";
	arch << placa << endl;
	arch << left << setw(25) << "Carga maxima: ";
	arch << cargaMaxima << endl;
	arch << left << setw(25) << "Carga actual: ";
	arch << cargaActual << endl;
}
