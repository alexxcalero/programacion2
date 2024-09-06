/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:10
 */

#include "Tesoreria.h"

int main(int argc, char** argv) {
	Tesoreria Oteso;

	Oteso.cargaEscalas();
	Oteso.cargaAlumnos();
	Oteso.actualizaBoleta();
	Oteso.imprimeBoleta();

	return 0;
}
