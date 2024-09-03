/*
 * Proyecto : EX1-2024_1-P3-PunterosAFuncion
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 10:15
 */

#include "Pregunta1.h"
#include "Pregunta3.h"
#include "Registros.h"
#include "PunteroVoid.h"
#include "MuestraVoid.h"
#include "ColaPrioridadGenerica.h"

int main(int argc, char** argv) {
	char **ventasLibroCodigo, ***libro;
	int **ventasDniFechaPuntaje;
	void *ventas;
	void *ranking;

	cargarVentas(ventasLibroCodigo, ventasDniFechaPuntaje, "Ventas.csv");
	cargaLibros(libro, "Libros.csv");
	cargaventas(libro, ventas);
	actualizaventas(ventasDniFechaPuntaje, ventasLibroCodigo, ventas);
	muestraventas(ventas);
	cargaranking(ranking, crearegistro, ventas);
	muestraranking(ranking, imprimeregistro, "rankings.txt", ventas);

	return 0;
}
