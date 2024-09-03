/*
 * Proyecto : LAB5-2024_1-ListaGenerica
 * Archivo  : FuncionesRegistros.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 3 de mayo de 2024, 08:45
 */

#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

#include <fstream>
using namespace std;

enum Registro {NUM, DNI, COD};

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch, int size, char delim);
void imprimeregistro(ofstream &arch, void *dato);
int cmpregistro(const void *a, const void *b);

#endif /* FUNCIONESREGISTROS_H */
