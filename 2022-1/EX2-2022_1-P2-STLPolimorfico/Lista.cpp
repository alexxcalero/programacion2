/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Lista.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:21
 */

#include "Lista.h"

Lista::Lista() {
	lini = nullptr;
	lfin = nullptr;
}

Lista::Lista(const Lista &orig) {
}

Lista::~Lista() {
}

void Lista::crear(ifstream &arch) {
	Pedido *ped;
	while(1) {
		ped = new Pedido;
		arch >> ped;
		if(arch.eof()) break;
		insertarOrdenado(ped);
	}
}

void Lista::insertarOrdenado(Pedido *ped) {
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->ped = ped;

	if(esListaVacia()) {
		nuevoNodo->sig = nullptr;
		lini = nuevoNodo;
		lfin = nuevoNodo;
	} else {
		Nodo *rec = lini;
		Nodo *ant = nullptr;
		while(rec) {
			if(rec->ped->GetFecha() > ped->GetFecha()) break;
			ant = rec;
			rec = rec->sig;
		}
		nuevoNodo->sig = rec;

		if(rec == nullptr) lfin = nuevoNodo;

		if(ant != nullptr) ant->sig = nuevoNodo;
		else lini = nuevoNodo;
	}
}

bool Lista::esListaVacia() {
	return lini == nullptr && lfin == nullptr;
}

void Lista::reordenar(int codigo) {
	// Es la primera posicion
	if(lini->ped->GetCodigo() == codigo)
		return;

	Nodo *rec = lini;
	Nodo *ant = nullptr;

	while(rec) {
		if(rec->ped->GetCodigo() == codigo) break;
		ant = rec;
		rec = rec->sig;
	}

	// No encontre el codigo buscado
	if(rec == nullptr) return;

	// Asigno el orden a 1
	rec->ped->SetOrden(1);
	ant->sig = rec->sig;
	rec->sig = lini;
	lini = rec;
}

void Lista::imprimir(ofstream &arch) {
	Nodo *rec = lini;
	while(rec) {
		Pedido *ped = rec->ped;
		arch << ped;
		rec = rec->sig;
	}
}
