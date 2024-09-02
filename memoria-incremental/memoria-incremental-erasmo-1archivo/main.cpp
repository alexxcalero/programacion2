/*
 * Proyecto : memoria-incremental-erasmo-1archivo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de abril de 2024, 22:54
 */

#include <iostream>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
	int *codigos;
	char **nombres, ***cursos;
	cargarDatosAlumnos(codigos, nombres, cursos, "Alumnos-Cursos.csv");
	reporteDeAlumnos(codigos, nombres, cursos, "ReporteDeAlumnos.txt");
	return 0;
}
