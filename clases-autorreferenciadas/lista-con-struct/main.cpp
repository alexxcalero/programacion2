/*
 * Proyecto : lista-con-struct
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 00:28
 */

#include <iostream>
#include "Lista.h"
using namespace std;

int main(int argc, char** argv) {
	Lista lista;

	lista.crear();
	lista.imprimirIterativo();
	lista.imprimirRecursivo();

	return 0;
}
