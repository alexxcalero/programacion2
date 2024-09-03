/*
 * Proyecto : EX1-2023_2-P2-PunterosGenericos
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de mayo de 2024, 23:30
 */

#include "Pregunta2.h"

int main(int argc, char** argv) {
	void *productos;

	cargarProductos(productos, "Productos.csv");
	pruebaDeCargaDeProductos(productos);

	return 0;
}
