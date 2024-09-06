/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:15
 */

#include "Flota.h"

int main(int argc, char** argv) {
	Flota transporte;

	transporte.cargaFlota();
	transporte.cargaPedidos();
	transporte.muestraCarga();

	return 0;
}
