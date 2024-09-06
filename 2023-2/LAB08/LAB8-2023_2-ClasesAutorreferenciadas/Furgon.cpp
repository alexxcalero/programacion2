/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : Furgon.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:25
 */

#include "Furgon.h"

Furgon::Furgon() {
	filas = 0;
	puertas = 0;
}

Furgon::Furgon(const Furgon &orig) {
}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
	this->puertas = puertas;
}

int Furgon::GetPuertas() const {
	return puertas;
}

void Furgon::SetFilas(int filas) {
	this->filas = filas;
}

int Furgon::GetFilas() const {
	return filas;
}

void Furgon::leer(ifstream &arch) {
	Vehiculo::leer(arch);
	arch >> filas;
	arch.get();
	arch >> puertas;
	arch.get();
}

void Furgon::imprimir(ofstream &arch) {
	Vehiculo::imprimir(arch);
	arch << left << setw(25) << "#Filas: ";
	arch << right << setw(10) << filas << endl;
	arch << left << setw(25) << "#Puertas: ";
	arch << right << setw(10) << puertas << endl;
	Vehiculo::imprimirPedidos(arch);
}
