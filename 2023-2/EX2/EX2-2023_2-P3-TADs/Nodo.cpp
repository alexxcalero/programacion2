/*
 * Proyecto : EX2-2023_2-P3-TADs
 * Archivo  : Nodo.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:19
 */

#include "Nodo.h"

Nodo::Nodo() {
	izq = nullptr;
	der = nullptr;
}

Nodo::Nodo(const Nodo &orig) {
}

Nodo::~Nodo() {
	delete unidad;
}
