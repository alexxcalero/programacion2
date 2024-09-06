/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : Vehiculo.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:20
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
	cliente = 0;
	placa = nullptr;
	maxcarga = 0.0;
	actcarga = 0.0;
	ped = nullptr;
}

Vehiculo::Vehiculo(const Vehiculo &orig) {
}

Vehiculo::~Vehiculo() {
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
	arch >> cliente;
	arch.get();  // Leo la coma
	char placa[100];
	arch.getline(placa, 100, ',');
	SetPlaca(placa);
	arch >> maxcarga;
	arch.get();  // Leo la coma
}

void Vehiculo::imprimir(ofstream &arch) {
	char placa[100];
	GetPlaca(placa);
	arch << left << setw(25) << "Codigo Cliente: ";
	arch << right << setw(10) << cliente << endl;
	arch << left << setw(25) << "Placa: ";
	arch << right << setw(10) << placa << endl;
	arch << left << setw(25) << "Carga Maxima: ";
	arch << right << setw(10) << setprecision(2) << fixed << maxcarga << endl;
	arch << left << setw(25) << "Carga Actual: ";
	arch << right << setw(10) << setprecision(2) << fixed << actcarga << endl;
}

void Vehiculo::imprimirPedidos(ofstream &arch) {
	arch << left << setw(25) << "Pedidos: " << endl;
	if(ped == nullptr) {
		arch << "No hay pedidos para el cliente\n\n";
		return;
	}

	NPedido *rec = ped;
	char codigo[100];
	while(rec) {
		rec->GetCodigo(codigo);
		arch << "    ";
		arch << left << setw(10) << codigo << right << setw(5) << rec->cantidad;
		arch << right << setw(8) << setprecision(2) << fixed << rec->peso << endl;
		rec = rec->sig;
	}
	arch << endl;
}

bool Vehiculo::esPilaVacia() {
	return ped == nullptr;
}

void Vehiculo::push(char *codigo, int cantidad, double peso) {
	NPedido *nuevoNodo = new NPedido;
	nuevoNodo->SetCodigo(codigo);
	nuevoNodo->SetCantidad(cantidad);
	nuevoNodo->SetPeso(peso);

	if(actcarga + peso <= maxcarga) {
		nuevoNodo->sig = ped;
		ped = nuevoNodo;
		actcarga += peso;
	}
}
