/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:46
 */

#include "Flota.h"

int main(int argc, char** argv) {
	Flota Unidades;

	Unidades.cargaFlota();
	Unidades.cargaPedidos();
	Unidades.muestraCarga();

	return 0;
}
