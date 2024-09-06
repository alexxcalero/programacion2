/*
 * Proyecto : lista-con-struct
 * Archivo  : Nodo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 00:28
 */

#ifndef NODO_H
#define NODO_H

#include "Lista.h"
#include "Persona.h"

class Nodo {
public:
	Nodo();
	friend class Lista;
private:
	Persona dato;
	Nodo *siguiente;
};

#endif /* NODO_H */
