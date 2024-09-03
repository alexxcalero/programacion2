/*
 * Proyecto : EX1-2023_1-P3-PunterosGenericos
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 19:47
 */

#include "PunterosGenericos.h"
#include "FuncionesAuxiliares.h"
#include "Pregunta1.h"

int main(int argc, char** argv) {
	void *alumnoveces;
	char ***alumnos_nom_mod;
	int *alumnos_cod, **alumnos;

	cargarAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, "Alumnos.csv");
	CargaCurso(alumnos_cod, alumnoveces, "HistoriaDeNotas.csv");
	ActualizaVeces(alumnoveces);
	ImprimeAlumno(alumnoveces);

	return 0;
}
