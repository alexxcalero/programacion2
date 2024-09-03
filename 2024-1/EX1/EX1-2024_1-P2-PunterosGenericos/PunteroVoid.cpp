/*
 * Proyecto : EX1-2024_1-P2-PunterosGenericos
 * Archivo  : PunteroVoid.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 09:19
 */

#include <cstring>
#include "Enums.h"
#include "PunteroVoid.h"

void cargaventas(char ***libro, void *&ventas) {
	// Tengo la cantidad exacta de libros
	int numDat = 0;
	while(libro[numDat]) numDat++;

	// Creo de manera exacta el arreglo de ventas
	void **auxVentas = new void*[numDat + 1]{};

	char **auxLibro, *codigo, *nombre, *autor;
	for(int i = 0; libro[i]; i++) {
		auxLibro = libro[i];
		codigo = auxLibro[COD];
		nombre = auxLibro[NOMB];
		autor = auxLibro[AUT];
		auxVentas[i] = insertarDatosVentas(codigo, nombre, autor);
	}

	ventas = auxVentas;
}

// CODLIB, NOMBLIB, AUTLIB, LIBVEN, SUMA, PROM, RANK
void *insertarDatosVentas(char *codigo, char *nombre, char *autor) {
	void **registro = new void*[7]{};
	registro[CODLIB] = codigo;
	registro[NOMBLIB] = nombre;
	registro[AUTLIB] = autor;
	int *libVen = new int;
	*libVen = 0;
	registro[LIBVEN] = libVen;
	int *suma = new int;
	*suma = 0;
	registro[SUMA] = suma;
	double *prom = new double;
	*prom = 0.0;
	registro[PROM] = prom;
	int *rank = new int;
	*rank = 1;
	registro[RANK] = rank;
	return registro;
}

void actualizaventas(int **ventasDniFechaPuntaje, char **ventasLibroCodigo, void *&ventas) {
	void **auxVentas = (void**)ventas, **registro;
	char *codLib;
	int *auxVentaDni, posLib;
	int *libVend, *sumPunt, *rank;
	double *prom;
	for(int i = 0; auxVentas[i]; i++) {
		registro = (void**)auxVentas[i];
		codLib = (char*)registro[CODLIB];
		posLib = buscarLibro(codLib, ventasLibroCodigo);
		if(posLib != NO_ENCONTRADO) {
			auxVentaDni = ventasDniFechaPuntaje[posLib];
			libVend = (int*)registro[LIBVEN];
			sumPunt = (int*)registro[SUMA];
			(*libVend)++;
			(*sumPunt) += auxVentaDni[PUNT];
		}
	}

	// Me falta actualizar los campos de Promedio de puntaje y Ranking
	for(int i = 0; auxVentas[i]; i++) {
		registro = (void**)auxVentas[i];
		libVend = (int*)registro[LIBVEN];
		if(*libVend > 0) {
			sumPunt = (int*)registro[SUMA];
			prom = (double*)registro[PROM];
			rank = (int*)registro[RANK];
			*prom = (double)(*sumPunt) / (*libVend);
			if(*prom < 30) {
				*rank = 1;
			} else if(*prom >= 30 && *prom < 70) {
				*rank = 2;
			} else {
				*rank = 3;
			}
		}
	}
}

int buscarLibro(char *codLib, char **libros) {
	for(int i = 0; libros[i]; i++)
		if(strcmp(codLib, libros[i]) == 0)
			return i;
	return NO_ENCONTRADO;
}
