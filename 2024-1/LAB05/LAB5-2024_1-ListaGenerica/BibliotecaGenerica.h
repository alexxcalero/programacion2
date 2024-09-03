/*
 * Proyecto : LAB5-2024_1-ListaGenerica
 * Archivo  : BibliotecaGenerica.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 3 de mayo de 2024, 08:05
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

enum Lista {CAB, COL};
enum Nodo {DATO, SIG};

void crealista(void *&pedido, void *(*leenum)(ifstream &), const char*nombArch);
bool listavacia(void *list);
void insertalista(void *dato, void *lista);
void imprimelista(void *pedido, void (*imprimenum)(ofstream &, void*), const char *nombArch);
void combinalista(void *lista1, void *lista2, void *&listafinal, int (*cmpnum)(const void*, const void*));
void *quitalista(void *lista);

#endif /* BIBLIOTECAGENERICA_H */
