/*
 * Proyecto : LAB5-2023_2-PtroFuncionConTads
 * Archivo  : ListaConRegistros.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 2 de mayo de 2024, 19:20
 */

#ifndef LISTACONREGISTROS_H
#define LISTACONREGISTROS_H

#include <fstream>
using namespace std;

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch, int size, char delim);
double calcularegistro(void *dato);
int cmpregistro(const void *valor1, const void *valor2);
void imprimeregistro(void *lista, ofstream &arch);

#endif /* LISTACONREGISTROS_H */
