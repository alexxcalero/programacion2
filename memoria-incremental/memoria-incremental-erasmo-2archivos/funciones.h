/*
 * Proyecto : memoria-incremental-erasmo-2archivos
 * Archivo  : funciones.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de abril de 2024, 23:25
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#define INCREMENTO 5
using namespace std;

void leerTweets(int *&, char **&, const char *);
char *leerCadena(ifstream &, int, char);
void incrementarMemoria(int *&, char **&, int &, int &);
void leerHashtags(int *, char ***&, const char *);
int buscarTweet(int, int *);
void agregarHashtags(ifstream &, char **&, int &, int &);
void incrementarMemoria(char **&, int &, int &);
void mostrarTweets(int *, char **, char ***, const char *);
void mostrarHashtags(ofstream &, char **);
void ordenarTweets(int *, char **, char ***);
void quickSort(int *, char **, char ***, int , int);
void swap2(int &, int &, char *&, char*&, char**&, char**&);

#endif /* FUNCIONES_H */
