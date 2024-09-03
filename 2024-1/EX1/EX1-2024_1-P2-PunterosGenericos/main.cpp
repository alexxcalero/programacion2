/*
 * Proyecto : EX1-2024_1-P2-PunterosGenericos
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 09:19
 */

#include "Pregunta1.h"
#include "PunteroVoid.h"
#include "MuestraVoid.h"

int main(int argc, char** argv) {
	char **ventasLibroCodigo, ***libro;
	int **ventasDniFechaPuntaje;
	void *ventas;

	cargarVentas(ventasLibroCodigo, ventasDniFechaPuntaje, "Ventas.csv");
	cargaLibros(libro, "Libros.csv");

	cargaventas(libro, ventas);
	actualizaventas(ventasDniFechaPuntaje, ventasLibroCodigo, ventas);
	muestraventas(ventas);

	return 0;
}
