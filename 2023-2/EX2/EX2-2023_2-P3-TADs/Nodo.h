/*
 * Proyecto : EX2-2023_2-P3-TADs
 * Archivo  : Nodo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:19
 */

#ifndef NODO_H
#define NODO_H

#include "Arbol.h"
#include "Vehiculo.h"

class Nodo {
public:
	Nodo();
	Nodo(const Nodo &orig);
	virtual ~Nodo();
	friend class Arbol;
private:
	Vehiculo *unidad;
	Nodo *izq;
	Nodo *der;
};

#endif /* NODO_H */
