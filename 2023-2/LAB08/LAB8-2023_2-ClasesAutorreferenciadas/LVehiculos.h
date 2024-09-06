/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : LVehiculos.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:27
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H

#include <iostream>
#include <fstream>
#include "Furgon.h"
#include "Camion.h"
#include "Vehiculo.h"
#include "NodoLista.h"
using namespace std;

class LVehiculos {
public:
	LVehiculos();
	LVehiculos(const LVehiculos &orig);
	virtual ~LVehiculos();
	void crear();
	void insertar(Vehiculo *v);
	void mostrar();
	void cargarPedidos();
	class NodoLista *buscarCliente(int cliente);
private:
	class NodoLista *lini;
	class NodoLista *lfin;
};

#endif /* LVEHICULOS_H */
