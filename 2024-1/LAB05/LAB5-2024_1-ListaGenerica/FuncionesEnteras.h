/*
 * Proyecto : LAB5-2024_1-ListaGenerica
 * Archivo  : FuncionesEnteras.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 3 de mayo de 2024, 08:06
 */

#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H

#include <fstream>
using namespace std;

void *leenum(ifstream &arch);
void imprimenum(ofstream &arch, void *dato);
int cmpnum(const void *a, const void *b);

#endif /* FUNCIONESENTERAS_H */
