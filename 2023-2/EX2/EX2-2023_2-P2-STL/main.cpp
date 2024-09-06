/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:27
 */

#include "Flota.h"

int main(int argc, char** argv) {
	Flota flota;

	flota.cargarVehiculos();
	flota.cargarPedidos();
	flota.mostrarVehiculos();

	return 0;
}
