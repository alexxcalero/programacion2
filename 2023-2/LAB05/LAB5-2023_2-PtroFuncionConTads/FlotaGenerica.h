/*
 * Proyecto : LAB5-2023_2-PtroFuncionConTads
 * Archivo  : FlotaGenerica.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 2 de mayo de 2024, 18:49
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

#include <fstream>
using namespace std;

void cargacamiones(void *&flota, int numcamiones, double pesomaximo, void *(*lee)(ifstream &), double (*calculanumero)(void *), const char *nombArch);
void inicializoCamiones(void *&camion);
double calculaPesoCamion(void *camion);
void insertarAlInicio(void *dato, void *&camion);
void aumentarPesoCamion(double pesoDato, void *&camion);
bool esListaVacia(void *lista);
void muestracamiones(void *flota, int numcamiones, void (*imprime)(void *, ofstream &), const char *nombArch);

#endif /* FLOTAGENERICA_H */
