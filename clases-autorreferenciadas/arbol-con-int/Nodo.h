/*
 * Proyecto : arbol-con-int
 * Archivo  : Nodo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 01:19
 */

#ifndef NODO_H
#define NODO_H

#include "Arbol.h"

class Nodo {
public:
	Nodo();
	friend class Arbol;
private:
	int dato;
	Nodo *izq;
	Nodo *der;
};

#endif /* NODO_H */
