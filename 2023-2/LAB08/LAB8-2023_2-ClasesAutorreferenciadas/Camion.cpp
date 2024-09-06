/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : Camion.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:24
 */

#include "Camion.h"

Camion::Camion() {
	ejes = 0;
	llantas = 0;
}

Camion::Camion(const Camion &orig) {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
	this->llantas = llantas;
}

int Camion::GetLlantas() const {
	return llantas;
}

void Camion::SetEjes(int ejes) {
	this->ejes = ejes;
}

int Camion::GetEjes() const {
	return ejes;
}

void Camion::leer(ifstream &arch) {
	Vehiculo::leer(arch);
	arch >> ejes;
	arch.get();
	arch >> llantas;
	arch.get();
}

void Camion::imprimir(ofstream &arch) {
	Vehiculo::imprimir(arch);
	arch << left << setw(25) << "#Ejes: ";
	arch << right << setw(10) << ejes << endl;
	arch << left << setw(25) << "#Llantas: ";
	arch << right << setw(10) << llantas << endl;
	Vehiculo::imprimirPedidos(arch);
}
