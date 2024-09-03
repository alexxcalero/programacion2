/*
 * Proyecto : LAB5-2023_2-PtroFuncionConTads
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 2 de mayo de 2024, 18:43
 */

#include "FlotaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistros.h"

int main(int argc, char** argv) {
	int numcamiones;
	double pesomaximo;
	void *flota;

	numcamiones = 5; pesomaximo = 10;
	cargacamiones(flota, numcamiones, pesomaximo, leenumero, calculanumero, "Numeros.txt");
	qsort(flota, numcamiones, sizeof(void*), cmpnumero);
	muestracamiones(flota, numcamiones, imprimenumero, "ReporteNumeros.txt");

	numcamiones = 100; pesomaximo = 400;
	cargacamiones(flota, numcamiones, pesomaximo, leeregistro, calcularegistro, "Pedidos3.csv");
	qsort(flota, numcamiones, sizeof(void*), cmpregistro);
	muestracamiones(flota, numcamiones, imprimeregistro, "ReporteRegistro.txt");

	return 0;
}
