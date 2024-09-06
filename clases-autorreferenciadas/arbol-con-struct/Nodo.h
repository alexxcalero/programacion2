/*
 * Proyecto : arbol-con-struct
 * Archivo  : Nodo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 01:45
 */

#ifndef NODO_H
#define NODO_H

#include "Arbol.h"
#include "Persona.h"

class Nodo {
public:
	Nodo();
	friend class Arbol;
private:
	Persona dato;
	Nodo *izq;
	Nodo *der;
};

#endif /* NODO_H */
