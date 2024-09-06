/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:40
 */

#include "Facultad.h"

int main(int argc, char** argv) {
	Facultad facultad;

	facultad.leerAlumnosNotas();
	facultad.imprimirAlumnosNotas("PruebaAlumnosNotas.txt");
	facultad.actualizarNotas();
	facultad.imprimirAlumnosNotas("PruebaNotasActualizadas.txt");

	return 0;
}
