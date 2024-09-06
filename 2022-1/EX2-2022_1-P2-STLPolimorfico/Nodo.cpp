/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Nodo.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:20
 */

#include "Nodo.h"

Nodo::Nodo() {
	ped = nullptr;
	sig = nullptr;
}

Nodo::Nodo(const Nodo &orig) {
	ped = nullptr;
	sig = nullptr;
	*this = orig;
}

Nodo::~Nodo() {
}
