/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : NVehiculo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:57
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H

#include <iomanip>
#include <fstream>
#include "Furgon.h"
#include "Camion.h"
#include "NPedido.h"
#include "Vehiculo.h"
using namespace std;

class NVehiculo {
public:
	NVehiculo();
	NVehiculo(const NVehiculo &orig);
	virtual ~NVehiculo();
	void asignarMemoria(char tipo);
	bool operator <(NVehiculo &v);
	bool operator ==(int dni);
	void leer(ifstream &arch);
	void imprimir(ofstream &arch);
	void agregarPedido(NPedido &pedido);
private:
	Vehiculo *unidad;
};

void operator >>(ifstream &arch, NVehiculo &vehiculo);
void operator <<(ofstream &arch, NVehiculo &vehiculo);

#endif /* NVEHICULO_H */
