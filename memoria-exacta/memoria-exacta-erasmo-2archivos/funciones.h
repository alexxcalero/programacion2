/*
 * Proyecto : memoria-exacta-erasmo-2archivos
 * Archivo  : funciones.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 9 de abril de 2024, 15:58
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
using namespace std;

void leerTweets(int *&, char **&, const char *);
char *leerCadena(ifstream &);
void leerHashtags(int *, char ***&, const char *);
int buscarTweet(int, int *);
void colocarHashtag(ifstream &, char **, int &);
void memoriaExactaDeHashtags(char **&, int);
void imprimirReporte(int *, char **, char ***, const char *);
void mostrarHashtags(char **, ofstream &);

#endif /* FUNCIONES_H */
