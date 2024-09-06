/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : NEstante.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:12
 */

#include "NEstante.h"

NEstante::NEstante() {
	izq = nullptr;
	der = nullptr;
}

NEstante::NEstante(const NEstante& orig) {
}

NEstante::~NEstante() {
}

void NEstante::SetDisponible(double disponible) {
	this->disponible = disponible;
}

double NEstante::GetDisponible() const {
	return disponible;
}

void NEstante::SetCapacidad(double capacidad) {
	this->capacidad = capacidad;
}

double NEstante::GetCapacidad() const {
	return capacidad;
}

void NEstante::SetId(int id) {
	this->id = id;
}

int NEstante::GetId() const {
	return id;
}

void NEstante::leer(ifstream &arch) {
	arch >> id;
	if(arch.eof()) return;
	arch.get();
	arch >> capacidad;
	disponible = capacidad;
	izq = nullptr;
	der = nullptr;
}

void NEstante::insertarLibros(ifstream &arch) {
	int cont = 1;
	char tipo;
	NLibro libro;
	while(cont <= 10) {
		arch >> tipo;
		if(arch.eof()) break;
		arch.get();
		libro.asignarMemoria(tipo);
		arch >> libro;
		vlibros.push_back(libro);
		disponible -= libro.getPeso();
		cont++;
	}
	if(arch.eof()) return;
}

void NEstante::imprimir(ofstream &arch) {
	arch << "Estante: " << id << endl;
	arch << "Capacidad: " << setw(5) << setprecision(2) << fixed << capacidad;
	arch << setw(8) << " " << "Disponible: " << disponible << endl;
	imprimirLinea(arch, 70, '=');
	for(NLibro &libro : vlibros)
		arch << libro;
}

void NEstante::imprimirLinea(ofstream &arch, int cant, char c) {
	for(int i = 0; i < cant; i++)
		arch << c;
	arch << endl;
}

void operator >>(ifstream &arch, NEstante *estante) {
	estante->leer(arch);
}

void operator <<(ofstream &arch, NEstante *estante) {
	estante->imprimir(arch);
}
