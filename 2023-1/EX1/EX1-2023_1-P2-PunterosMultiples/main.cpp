/*
 * Proyecto : EX1-2023_1-P2-PunterosMultiples
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 19:00
 */

#include "Pregunta1.h"
#include "Pregunta2.h"

int main(int argc, char** argv) {
	char ***cursos, ***alumnos_nom_mod;
	double *cursos_cred, escalas[5];
	int *alumnos_cod, **alumnos;

	cargarCursosYEscalas(cursos, cursos_cred, escalas, "Cursos.csv", "Escalas.csv");
	pruebaDeCargaDeCursos(cursos, cursos_cred, "PruebaCursos.txt");

	cargarAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, "Alumnos.csv");
	pruebaDeCargaDeAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, "PruebaAlumnos.txt");

	int ***cursos_nota_sem_veces;
	double **costos;
	char ***cursos_cod;
	cargarNotas(cursos_cod, cursos_nota_sem_veces, costos, alumnos, alumnos_nom_mod,
				escalas, cursos, cursos_cred, "HistoriaDeNotas.csv");
	pruebaDeCargaDeNotas(cursos_cod, cursos_nota_sem_veces, costos, alumnos,
						 alumnos_nom_mod, "PruebaDeNotas.txt");

	return 0;
}
