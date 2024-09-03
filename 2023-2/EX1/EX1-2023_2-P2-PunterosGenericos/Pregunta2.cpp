/*
 * Proyecto : EX1-2023_2-P2-PunterosGenericos
 * Archivo  : Pregunta2.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de mayo de 2024, 23:30
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Pregunta2.h"
using namespace std;

void cargarProductos(void *&productos, const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	int numDat = 0, capacidad = 0;
	void **auxProductos = nullptr, *dato;
	while(1) {
		dato = leerDato(arch);
		if(arch.eof()) break;
		if(numDat == capacidad) incrementarMemoria(auxProductos, numDat, capacidad);
		auxProductos[numDat - 1] = dato;
		numDat++;
	}
	productos = auxProductos;
	ordenarProductos(productos);
}

void *leerDato(ifstream &arch) {
	void **dato;
	char *codigo, *descripcion, c;
	double prec, *precio;
	int stk, *stock;

	codigo = leerCadena(arch, 8, ',');
	if(arch.eof()) return nullptr;
	descripcion = leerCadena(arch, 60, ',');
	arch >> prec >> c >> stk;
	arch.get();  // Leo el salto de linea

	precio = new double; *precio = prec;
	stock = new int; *stock = stk;

	dato = new void*[4]{};
	dato[COD] = codigo;
	dato[DESC] = descripcion;
	dato[PREC] = precio;
	dato[STK] = stock;

	// Ahora creo el nodito externo
	void **nodo = new void*[2]{};
	nodo[DATO] = dato;
	nodo[SIG] = nullptr;

	return nodo;
}

char *leerCadena(ifstream &arch, int size, char delim) {
	char *cadena, buffCad[size];
	arch.getline(buffCad, size, delim);
	if(arch.eof()) return nullptr;
	cadena = new char[strlen(buffCad) + 1];
	strcpy(cadena, buffCad);
	return cadena;
}

void incrementarMemoria(void **&productos, int &num, int &cap) {
	void **auxProductos;
	cap += INCREMENTO;
	if(productos == nullptr) {
		productos = new void*[cap]{};
		num = 1;
	} else {
		auxProductos = new void*[cap]{};
		for(int i = 0; i < num; i++)
			auxProductos[i] = productos[i];
		delete productos;
		productos = auxProductos;
	}
}

void ordenarProductos(void *&productos) {
	int n = 0;
	void **rec = (void**)productos;
	while(rec[n]) n++;
	qsort(productos, n, sizeof(void*), comp_cods);
}

int comp_cods(const void *a, const void *b) {
	void **valorA = (void**)a, **valorB = (void**)b;
	void **nodoA = (void**)(*valorA), **nodoB = (void**)(*valorB);
	void **regA = (void**)nodoA[DATO], **regB = (void**)nodoB[DATO];
	//char *codA = (char*)nodoA[COD], *codB = (char*)nodoA[COD];
	char *codA = (char*)regA[COD], *codB = (char*)regB[COD];
	return strcmp(codA, codB);
}

void pruebaDeCargaDeProductos(void *productos) {
	ofstream arch("PruebaProductos.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo PruebaProductos.txt\n";
		exit(1);
	}
	void **recProductos = (void**)productos, **nodo;
	imprimirEncabezados(arch);
	for(int i = 0; recProductos[i]; i++) {
		nodo = (void**)recProductos[i];
		imprimirDatos(arch, nodo[DATO]);
	}
}

void imprimirEncabezados(ofstream &arch) {
	arch << left << setw(10) << "CODIGO";
	arch << setw(68) << "DESCRIPCION";
	arch << setw(10) << "PRECIO";
	arch << setw(10) << "STOCK";
	arch << endl;
	imprimirLinea(arch, '-');
}

void imprimirDatos(ofstream &arch, void *dato) {
	void **auxDato = (void**)dato;
	char *codigo, *descripcion;
	double *precio;
	int *stock;
	codigo = (char*)auxDato[COD];
	descripcion = (char*)auxDato[DESC];
	precio = (double*)auxDato[PREC];
	stock = (int*)auxDato[STK];
	arch << left << setw(10) << codigo << setw(65) << descripcion;
	arch << right << setw(10) << *precio << "    " << setw(2) << *stock << endl;
}

void imprimirLinea(ofstream &arch, char car) {
	for(int i = 0; i < MAXLIN; i++)
		arch << car;
	arch << endl;
}
