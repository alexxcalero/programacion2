/*
 * Proyecto : EX1-2023_2-P2-PunterosGenericos
 * Archivo  : Pregunta2.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de mayo de 2024, 23:30
 */

#ifndef PREGUNTA2_H
#define PREGUNTA2_H

#include <fstream>
#define INCREMENTO 5
#define MAXLIN 100
using namespace std;

enum Dato {COD, DESC, PREC, STK};
enum Nodo {DATO, SIG};

void cargarProductos(void *&productos, const char *nombArch);
void *leerDato(ifstream &arch);
char *leerCadena(ifstream &arch, int size, char delim);
void incrementarMemoria(void **&productos, int &num, int &cap);
void ordenarProductos(void *&productos);
int comp_cods(const void *a, const void *b);
void pruebaDeCargaDeProductos(void *productos);
void imprimirEncabezados(ofstream &arch);
void imprimirDatos(ofstream &arch, void *dato);
void imprimirLinea(ofstream &arch, char car);

#endif /* PREGUNTA2_H */
