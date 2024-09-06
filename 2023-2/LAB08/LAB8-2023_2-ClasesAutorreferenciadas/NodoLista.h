/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : NodoLista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:26
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Vehiculo.h"
#include "LVehiculos.h"

class NodoLista {
public:
	NodoLista();
	NodoLista(const NodoLista &orig);
	virtual ~NodoLista();
	friend class LVehiculos;
private:
	Vehiculo *unidad;
	NodoLista *sig;
};

#endif /* NODOLISTA_H */
