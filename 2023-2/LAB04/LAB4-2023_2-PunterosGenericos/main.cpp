/*
 * Proyecto : LAB4-2023_2-PunterosGenericos
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 25 de abril de 2024, 21:54
 */

#include "MuestraPunteros.h"
#include "PunterosGenericos.h"

int main(int argc, char** argv) {
	void *productos, *clientes;

	cargaproductos(productos);
	imprimeproductos(productos);

	cargaclientes(clientes);
	imprimeclientes(clientes);

	cargapedidos(productos,clientes);

	imprimerepfinal(clientes);

	return 0;
}
