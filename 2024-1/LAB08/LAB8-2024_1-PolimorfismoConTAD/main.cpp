/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:00
 */

#include "Biblioteca.h"

int main(int argc, char** argv) {
	Biblioteca bli;

	bli.carga();
	bli.llena();
	bli.baja();
	bli.muestra();

	return 0;
}
