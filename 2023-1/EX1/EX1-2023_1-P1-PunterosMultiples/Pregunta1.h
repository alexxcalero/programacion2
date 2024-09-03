/*
 * Proyecto : EX1-2023_1-P1-PunterosMultiples
 * Archivo  : Pregunta1.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 18:27
 */

#ifndef PREGUNTA1_H
#define PREGUNTA1_H

#include <fstream>
#define INCREMENTO 5;
#define MAXLIN 110
using namespace std;

void cargarCursosYEscalas(char ***&cursos, double *&cursos_cred, double *escalas, const char *nombArchCur, const char *nombArchEsc);
char *leerCadena(ifstream &arch, int size, char delim);
void incrementarMemoria(char ***&cursos, double *&cursos_cred, int &num, int &cap);
char **insertarDatosCurso(char *codigo, char *nombre, char *profesor);
void pruebaDeCargaDeCursos(char ***cursos, double *cursos_cred, const char *nombArch);
void impEncabezados(ofstream &arch);
void impLinea(ofstream &arch, char c);
void cargarAlumnos(int *&alumnos_cod, int **&alumnos, char ***&alumnos_nom_mod, const char *nombArch);
void incrementarMemoria(int *&alumnos_cod, int **&alumnos, char ***&alumnos_nom_mod, int &num, int &cap);
int *insertarDatosAlumno(int cod, int escala, char modalidad, int porcentaje);
char **insertarNombreAlumno(char *nombre, char modalidad);
void pruebaDeCargaDeAlumnos(int *alumnos_cod, int **alumnos, char ***alumnos_nom_mod, const char *nombArch);
void impEncabezadosAlumnos(ofstream &arch);

#endif /* PREGUNTA1_H */
