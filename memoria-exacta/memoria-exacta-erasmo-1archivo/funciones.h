/*
 * Proyecto : memoria-exacta-erasmo-1archivo
 * Archivo  : funciones.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 9 de abril de 2024, 15:12
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
using namespace std;

void leerTweets(int *&, char **&, char ***&, const char *);
char *leerCadena(ifstream &);
char **leerHashtag(ifstream &);
char *leerUnSoloHashtag(ifstream &);
void mostrarTweets(int *, char **, char ***, const char *);
void mostrarHashtags(char **, ofstream &);

#endif /* FUNCIONES_H */
