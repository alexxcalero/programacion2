/*
 * Proyecto : LAB4-2024_1-PunterosGenericos
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de abril de 2024, 08:06
 */

#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"

int main(int argc, char** argv) {
	void *clientes, *reserva;

	cargaclientes(clientes);
	creareserva(reserva);
	cargareservar(clientes, reserva);
	reportefinal(reserva);

	return 0;
}
