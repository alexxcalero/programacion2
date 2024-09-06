/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : Flota.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:36
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include "Camion.h"
#include "Furgon.h"
#include "Vehiculo.h"
using namespace std;

class Flota {
public:
	Flota();
	Flota(const Flota &orig);
	virtual ~Flota();
	void cargarVehiculos();
	void cargarPedidos();
	void mostrarVehiculos();
	void imprimirLinea(ofstream &arch, int cant, char c);
	friend class Programacion;
private:
	map<string, Vehiculo*> vehiculos;  // key: placa
};

#endif /* FLOTA_H */
