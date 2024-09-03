/*
 * Proyecto : EX1-2024_1-P1-PunterosMultiples
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 08:07
 */

#include "Pregunta1.h"

int main(int argc, char** argv) {
	char **ventasLibroCodigo, ***libro;
	int **ventasDniFechaPuntaje;

	cargarVentas(ventasLibroCodigo, ventasDniFechaPuntaje, "Ventas.csv");
	pruebaDeCargaDeVentas(ventasLibroCodigo, ventasDniFechaPuntaje, "PruebaVentas.txt");
	cargaLibros(libro, "Libros.csv");
	pruebaDeCargaDeLibros(libro, "PruebaLibros.txt");

	return 0;
}
