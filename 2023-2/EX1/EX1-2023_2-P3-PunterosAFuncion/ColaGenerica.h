/*
 * Proyecto : EX1-2023_2-P3-PunterosAFuncion
 * Archivo  : ColaGenerica.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 01:17
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H

enum Cola {CABE, COLA, TOT};
enum NodoC {DATOC, SIGC};  // C de Cola, porque ya hay otro DATO y SIG

void generaCola(void *&c);
bool esColaVacia(void *c);
void encolar(void *dato, void *&c);
void *desencolar(void *&c);

#endif /* COLAGENERICA_H */
