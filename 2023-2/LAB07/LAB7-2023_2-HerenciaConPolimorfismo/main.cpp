/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:15
 */

#include "Almacen.h"

int main(int argc, char** argv) {
	Almacen almacen;

	almacen.cargar_pedidos();
	almacen.actualizar_pedidos();
	almacen.imprimir_ordenes_ventas();

	return 0;
}
