/*
 * Proyecto : arbol-con-int
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 01:18
 */

#include <iostream>
#include "Arbol.h"
using namespace std;

int main(int argc, char** argv) {
	Arbol arbol;

	arbol.crear();
	arbol.mostrarEnOrden();
	cout << "Dato buscado: " << arbol.buscar(81) << endl;
	
	return 0;
}
