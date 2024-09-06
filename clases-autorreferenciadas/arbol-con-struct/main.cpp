/*
 * Proyecto : arbol-con-struct
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 01:45
 */

#include <iostream>
#include "Arbol.h"
#include "Persona.h"
using namespace std;

int main(int argc, char** argv) {
	Arbol arbol;

	arbol.crear();
	arbol.mostrarEnOrden();

	Persona p;
	p = arbol.buscar(250612);
	if(p.GetDni() != -1)
		cout << "Dato buscado: " << p.GetDni();
	else
		cout << "No se pudo encontrar el dato buscado\n";

	return 0;
}
