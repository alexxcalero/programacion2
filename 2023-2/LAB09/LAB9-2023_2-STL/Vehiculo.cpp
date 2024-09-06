/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : Vehiculo.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:48
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
	cliente = 0;
	placa = nullptr;
	maxcarga = 0.0;
	actcarga = 0.0;
}

Vehiculo::Vehiculo(const Vehiculo &orig) {
	placa = nullptr;
	cliente = orig.cliente;
	maxcarga = orig.maxcarga;
	actcarga = orig.actcarga;
	char plaquita[100];
	orig.GetPlaca(plaquita);
	SetPlaca(plaquita);
}

Vehiculo::~Vehiculo() {
	//if(placa != nullptr) delete placa;
}

void Vehiculo::SetActcarga(double actcarga) {
	this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
	return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
	this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
	return maxcarga;
}

void Vehiculo::SetPlaca(const char *placa) {
	if(this->placa != nullptr) delete this->placa;
	this->placa = new char[strlen(placa) + 1];
	strcpy(this->placa, placa);
}

void Vehiculo::GetPlaca(char *placa) const {
	if(this->placa == nullptr) placa[0] = 0;
	else strcpy(placa, this->placa);
}

void Vehiculo::SetCliente(int cliente) {
	this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
	return cliente;
}

void Vehiculo::leer(ifstream &arch) {
	char placa[100], c;
	arch >> cliente >> c;
	arch.getline(placa, 100, ',');
	SetPlaca(placa);
	arch >> maxcarga >> c;
}

void Vehiculo::imprimir(ofstream &arch) {
	arch << left << setw(18) << "Codigo Cliente: " << cliente << endl;
	char plaquita[100];
	GetPlaca(plaquita);
	arch << left << setw(18) << "Placa: " << plaquita << endl;
	arch << left << setw(18) << "Carga Maxima: " << setprecision(2) << fixed << maxcarga << endl;
	arch << left << setw(18) << "Carga Actual: " << setprecision(2) << fixed << actcarga << endl;
}
