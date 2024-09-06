/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : Nodo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:53
 */

#ifndef NODO_H
#define NODO_H

#include "ListaDoble.h"
#include "AlumnoNotas.h"

class Nodo {
public:
	Nodo();
	Nodo(const Nodo &orig);
	virtual ~Nodo();
	friend class ListaDoble;
private:
	AlumnoNotas dato;
	Nodo *ant;
	Nodo *sig;
};

#endif /* NODO_H */
