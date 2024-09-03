/*
 * Proyecto : EX1-2023_2-P1-PunterosMultiples
 * Archivo  : Pregunta1.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de mayo de 2024, 20:45
 */

#ifndef PREGUNTA1_H
#define PREGUNTA1_H

#include <fstream>
using namespace std;

enum Arreglo {FECH, DNI, CANT};

void cargarPedidos(int **&fechaClienteCantidad, char **&codigoDelProducto, const char *nombArch);
char *leerCadena1(ifstream &arch, int size, char delim);
void incrementarMemoria(int **&fechaClienteCantidad, char **&codigoDelProducto, int &num, int &cap);
int *insertarFechaClienteCantidad(int fecha, int dni, int cantidad);
void ordenarArreglos(int **&fechaClienteCantidad, char **&codigoDelProducto);
void mergeSort(int **&fechaClienteCantidad, char **&codigoDelProducto, int cant, int ini, int fin);
void merge(int **&fechaClienteCantidad, char **&codigoDelProducto, int cant, int ini, int med, int fin);
void pruebaDeCargaDePedidos(int **fechaClienteCantidad, char **codigoDelProducto, const char *nombArch);
void separarFecha(int fecha, int &dia, int &mes, int &anho);
void imprimirEncabezados1(ofstream &arch);
void imprimirLinea1(ofstream &arch, char car);

#endif /* PREGUNTA1_H */
