/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Nodo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:20
 */

#ifndef NODO_H
#define NODO_H

#include "Lista.h"
#include "Pedido.h"

class Nodo {
public:
	Nodo();
	Nodo(const Nodo &orig);
	virtual ~Nodo();
	friend class Lista;
private:
	class Pedido *ped;
	class Nodo *sig;
};

#endif /* NODO_H */
