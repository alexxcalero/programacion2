/*
 * Proyecto : EX1-2023_2-P3-PunterosAFuncion
 * Archivo  : ColaConEnteros.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 01:13
 */

#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H

#include <fstream>
using namespace std;

void cargaEnteros(void *&cola, void *(*leenumero)(ifstream &arch), const char *nombArch);
void *leenumero(ifstream &arch);
void mostrarEnteros(void *cola, void (*imprimenumero)(ofstream &arch, void *), const char *nombArch);
void imprimenumero(ofstream &arch, void *dato);

#endif /* COLACONENTEROS_H */
