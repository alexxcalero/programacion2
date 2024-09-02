/*
 * Proyecto : memoria-exacta-introduccion
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 9 de abril de 2024, 14:34
 */

#include <iostream>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
	int *datos, cantDatos;

	// Primer metodo: con variable auxiliar para llevar la cantidad de datos
//	leerDatos(datos, cantDatos, "data.txt");
//	imprimirDatos(datos, cantDatos);

	// Segundo metodo: sin usar la variable auxiliar para llevar la cantidad de datos
	leerDatos(datos, "data.txt");
	imprimirDatos(datos);
	return 0;
}
