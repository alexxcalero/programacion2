/*
 * Proyecto : memoria-incremental-erasmo-1archivo
 * Archivo  : funciones.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de abril de 2024, 22:55
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#define INCREMENTO 5
using namespace std;

void cargarDatosAlumnos(int *&, char **&, char ***&, const char *);
void incrementarMemoria(int *&, char **&, char ***&, int &, int &);
char *leerCadena(ifstream &, int, char);
char **leerCursos(ifstream &);
void incrementarMemoria(char **&, int &, int &);
void reporteDeAlumnos(int *, char **, char ***, const char *);
void reporteDeCursos(ofstream &, char **);

#endif /* FUNCIONES_H */
