/*
 * Proyecto : sobrecarga-con-objetos
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 22 de mayo de 2024, 23:50
 */

#include <iostream>
#include "Heroe.h"
using namespace std;

int main(int argc, char** argv) {
	Heroe zed("Zed"), yasuo;
//	zed.crear();
//	zed.mostrar();
//	zed.curar(25);
//	zed.mover(10, -3, 5.5);
	zed.mostrar();
	yasuo.mostrar();

	zed.curar(35);
	char nombre[60];
	zed.GetNombre(nombre);
	cout << "El nuevo HP de " << nombre << " es: " << zed.GetHp() << endl;

	yasuo.SetNombre("Yasuo");
	yasuo.SetPosx(220);
	yasuo.SetPosy(170);
	yasuo.mostrar();

	// Prueba de las sobrecargas:
	zed -= yasuo;
	zed += yasuo;
	zed.mostrar();
	
	return 0;
}
