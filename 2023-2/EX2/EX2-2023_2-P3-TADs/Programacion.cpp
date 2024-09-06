/*
 * Proyecto : EX2-2023_2-P3-TADs
 * Archivo  : Programacion.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 23:24
 */

#include "Programacion.h"

Programacion::Programacion() {
}

Programacion::Programacion(const Programacion &orig) {
}

Programacion::~Programacion() {
}

void Programacion::cargarVehiculos() {
	fVehiculos.cargarVehiculos();
	fVehiculos.cargarPedidos();
}

void Programacion::cargarProgramacion() {
	for(auto vehiculo : fVehiculos.vehiculos)
		ADespachos.insertar(vehiculo.second);
}

void Programacion::reducirVehiculos(int cantidad) {
	ADespachos.eliminarNodos(cantidad);
}

void Programacion::mostrarProgramacion() {
	ADespachos.imprimirEnOrden();
}
