/*
 * Proyecto : EX2-2023_2-P3-TADs
 * Archivo  : Programacion.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 23:24
 */

#ifndef PROGRAMACION_H
#define PROGRAMACION_H

#include "Arbol.h"
#include "Flota.h"

class Programacion {
public:
	Programacion();
	Programacion(const Programacion &orig);
	virtual ~Programacion();
	void cargarVehiculos();
	void cargarProgramacion();
	void reducirVehiculos(int cantidad);
	void mostrarProgramacion();
private:
	Arbol ADespachos;
	Flota fVehiculos;
};

#endif /* PROGRAMACION_H */
