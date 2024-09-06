/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : Flota.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:58
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "NPedido.h"
#include "NVehiculo.h"
using namespace std;

class Flota {
public:
	Flota();
	Flota(const Flota &orig);
	virtual ~Flota();
	void cargaFlota();
	void cargaPedidos();
	int buscarDni(int dni);
	void muestraCarga();
	void imprimirLinea(ofstream &arch, int cant, char c);
private:
	vector<NVehiculo> vflota;
};

#endif /* FLOTA_H */
