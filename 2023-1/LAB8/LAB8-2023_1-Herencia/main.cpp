/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:38
 */

#include "Tesoreria.h"

int main(int argc, char** argv) {
	Tesoreria caja;

	caja.cargaescalas();
	caja.cargaalumnos();
	caja.actualiza(20);
	caja.imprime();

	return 0;
}
