/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : Flota.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:30
 */

#ifndef FLOTA_H
#define FLOTA_H

#include "LVehiculos.h"

class Flota {
public:
	Flota();
	Flota(const Flota &orig);
	virtual ~Flota();
	void cargaFlota();
	void cargaPedidos();
	void muestraCarga();
private:
	LVehiculos lista;
};

#endif /* FLOTA_H */
