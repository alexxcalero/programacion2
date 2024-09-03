/*
 * Proyecto : EX1-2024_1-P3-PunterosAFuncion
 * Archivo  : Registros.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 10:15
 */

#ifndef REGISTROS_H
#define REGISTROS_H

#include <fstream>
using namespace std;

void *crearegistro(ifstream &arch);
void imprimeregistro(ofstream &arch, void *dato);

#endif /* REGISTROS_H */
