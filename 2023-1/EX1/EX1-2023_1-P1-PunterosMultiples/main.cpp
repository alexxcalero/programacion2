/*
 * Proyecto : EX1-2023_1-P1-PunterosMultiples
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 18:24
 */

#include "Pregunta1.h"

int main(int argc, char** argv) {
	char ***cursos, ***alumnos_nom_mod;
	double *cursos_cred, escalas[5];
	int *alumnos_cod, **alumnos;

	cargarCursosYEscalas(cursos, cursos_cred, escalas, "Cursos.csv", "Escalas.csv");
	pruebaDeCargaDeCursos(cursos, cursos_cred, "PruebaCursos.txt");

	cargarAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, "Alumnos.csv");
	pruebaDeCargaDeAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, "PruebaAlumnos.txt");

	return 0;
}
