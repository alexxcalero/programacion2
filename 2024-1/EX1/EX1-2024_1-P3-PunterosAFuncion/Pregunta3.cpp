/*
 * Proyecto : EX1-2024_1-P3-PunterosAFuncion
 * Archivo  : Pregunta3.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 10:15
 */

#include <fstream>
#include "Pregunta3.h"
#include "ColaPrioridadGenerica.h"
using namespace std;

void cargaranking(void *&ranking, void *(*crearegistro)(ifstream &arch), void *ventas) {
	generacola(ranking);
	void **auxRanking = (void**)ranking;
	void *dato;
	while(1) {
	
	}
}

void muestraranking(void *ranking, void (*imprimeregistro)(ofstream &arch, void *), const char *nombArch, void *ventas) {

}
