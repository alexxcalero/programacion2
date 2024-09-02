/*
 * Proyecto : memoria-incremental-introduccion
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de abril de 2024, 22:52
 */

#include <iostream>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
	int *datos;
	cargarDatos(datos, "data.txt");
	imprimirDatos(datos);
	return 0;
}
