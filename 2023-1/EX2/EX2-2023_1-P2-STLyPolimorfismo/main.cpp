/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 15:53
 */

#include "Registro.h"

int main(int argc, char** argv) {
	Registro reg;

	reg.carga();
	reg.procesa();
	reg.muestra();

	return 0;
}
