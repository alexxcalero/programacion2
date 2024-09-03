/*
 * Proyecto : EX1-2024_1-P3-PunterosAFuncion
 * Archivo  : Pregunta3.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 10:15
 */

#ifndef PREGUNTA3_H
#define PREGUNTA3_H

#include <fstream>
using namespace std;

void cargaranking(void *&ranking, void *(*crearegistro)(ifstream &arch), void *ventas);
void muestraranking(void *ranking, void (*imprimeregistro)(ofstream &arch, void *), const char *nombArch, void *ventas);

#endif /* PREGUNTA3_H */
