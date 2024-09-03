/*
 * Proyecto : LAB5-2023_2-PtroFuncionConTads
 * Archivo  : ListaConEnteros.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 2 de mayo de 2024, 18:49
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

#include <fstream>
using namespace std;

void *leenumero(ifstream &arch);
double calculanumero(void *dato);
int cmpnumero(const void *a, const void *b);
void imprimenumero(void *lista, ofstream &arch);

#endif /* LISTACONENTEROS_H */
