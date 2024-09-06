/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Nodo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:08
 */

#ifndef NODO_H
#define NODO_H

#include "Libro.h"

class Nodo {
public:
	Nodo();
	Nodo(const Nodo& orig);
	virtual ~Nodo();
	friend class Lista;
private:
	Libro *plibro;
	Nodo *sig;
};

#endif /* NODO_H */
