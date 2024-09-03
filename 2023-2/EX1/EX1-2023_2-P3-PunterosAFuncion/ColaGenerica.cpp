/*
 * Proyecto : EX1-2023_2-P3-PunterosAFuncion
 * Archivo  : ColaGenerica.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 01:17
 */

#include "ColaGenerica.h"

void generaCola(void *&c) {
	void **cola = new void*[3]{};
	cola[CABE] = nullptr;
	cola[COLA] = nullptr;
	cola[TOT] = nullptr;
	c = cola;
}

bool esColaVacia(void *c) {
	void **cola = (void**)c;
	if(cola[CABE] == nullptr && cola[COLA] == nullptr)
		return true;
	else
		return false;
}

void encolar(void *dato, void *&c) {
	void **cola = (void**)c;
	void **nuevoNodo = new void*[2]{}, **ultimo;
	int *totalPedidos;
	nuevoNodo[DATOC] = dato;
	nuevoNodo[SIGC] = nullptr;
	if(esColaVacia(c)) {
		cola[CABE] = nuevoNodo;
		totalPedidos = new int;
		*totalPedidos = 1;
		cola[TOT] = totalPedidos;
	} else {
		ultimo = (void**)cola[COLA];
		ultimo[SIGC] = nuevoNodo;
		totalPedidos = (int*)cola[TOT];
		(*totalPedidos)++;
	}
	cola[COLA] = nuevoNodo;
}

void *desencolar(void *&c) {
	if(!esColaVacia(c)) {
		void **cola = (void**)c;
		void **nodoDevolver = (void**)cola[CABE];
		cola[CABE] = nodoDevolver[SIGC];
		if(cola[CABE] == nullptr)
			cola[COLA] = nullptr;
		int *totalPedidos = (int*)cola[TOT];
		(*totalPedidos)--;
		nodoDevolver[SIGC] = nullptr;  // Le desconecto su siguiente
		return nodoDevolver[DATOC];
	}
}
