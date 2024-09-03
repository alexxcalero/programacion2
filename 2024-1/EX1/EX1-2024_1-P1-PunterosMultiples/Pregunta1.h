/*
 * Proyecto : EX1-2024_1-P1-PunterosMultiples
 * Archivo  : Pregunta1.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 08:07
 */

#ifndef PREGUNTA1_H
#define PREGUNTA1_H

#include <fstream>
#define INCREMENTO 5
#define MAXLINREPVENT 40
#define MAXLINREPLIB 110
using namespace std;

void cargarVentas(char **&ventasLibroCodigo, int **&ventasDniFechaPuntaje, const char *nombArch);
char *leerCadena(ifstream &arch, int size, char delim);
void incrementarMemoria(char **&ventasLibroCodigo, int **&ventasDniFechaPuntaje, int &num, int &cap);
int *insertarDatosFecha(int dni, int fecha, int puntaje);
void pruebaDeCargaDeVentas(char **ventasLibroCodigo, int **ventasDniFechaPuntaje, const char *nombArch);
void imprimirTitulo(ofstream &arch);
void imprimirEncabezados(ofstream &arch);
void convertirFecha(int fecha, int &dia, int &mes, int &anho);
void imprimirLinea(ofstream &arch, int cant, char car);
void cargaLibros(char ***&libro, const char *nombArch);
void incrementarMemoria(char ***&libro, int &num, int &cap);
char **insertarDatosLibro(char *codigo, char *nombre, char *autor);
void ordenarLibros(char ***libro);
int cmp_cod(const void *a, const void *b);
void pruebaDeCargaDeLibros(char ***libro, const char *nombArch);
void imprimirTitRepLibros(ofstream &arch);
void imprimirEncabRepLibros(ofstream &arch);

#endif /* PREGUNTA1_H */
