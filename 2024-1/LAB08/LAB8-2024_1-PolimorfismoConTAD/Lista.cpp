/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Lista.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:09
 */

#include "Lista.h"

Lista::Lista() {
	peso = 0;
	ini = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::SetPeso(double peso) {
	this->peso = peso;
}

double Lista::GetPeso() const {
	return peso;
}

void Lista::insertarLibro(Libro *libro) {
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->plibro = libro;
	nuevoNodo->sig = nullptr;  // Voy a insertar al final
	if(ini == nullptr) {
		ini = nuevoNodo;
	} else {
		Nodo *rec = ini;
		Nodo *ultimo = nullptr;
		while(rec) {
			ultimo = rec;
			rec = rec->sig;
		}
		ultimo->sig = nuevoNodo;
	}
	peso += libro->GetPeso();
}

void Lista::actualizarVigencia() {
	if(ini == nullptr)
		return;

	Nodo *rec = ini;
	while(rec) {
		rec->plibro->actualiza();
		rec = rec->sig;
	}
}

void Lista::imprimirLibros(ofstream &arch) {
	if(ini == nullptr)
		return;

	Nodo *rec = ini;
	while(rec) {
		rec->plibro->imprime(arch);
		rec = rec->sig;
	}
	arch << endl;
}
