/*
 * Proyecto : EX1-2023_2-P1-PunterosMultiples
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de mayo de 2024, 20:43
 */

#include "Pregunta1.h"

int main(int argc, char** argv) {
	char **codigoDelProducto;
	int **fechaClienteCantidad;

	cargarPedidos(fechaClienteCantidad, codigoDelProducto, "Pedidos.csv");
	pruebaDeCargaDePedidos(fechaClienteCantidad, codigoDelProducto, "PruebaPedidos.txt");

	return 0;
}
