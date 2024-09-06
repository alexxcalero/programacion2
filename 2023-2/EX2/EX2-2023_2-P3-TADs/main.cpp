/*
 * Proyecto : EX2-2023_2-P3-TADs
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:18
 */

#include "Programacion.h"

int main(int argc, char** argv) {
	Programacion pro;

	pro.cargarVehiculos();
	pro.cargarProgramacion();
	pro.reducirVehiculos(10);
	pro.mostrarProgramacion();

	return 0;
}
