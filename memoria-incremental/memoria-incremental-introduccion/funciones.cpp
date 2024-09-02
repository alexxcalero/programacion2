/*
 * Proyecto : memoria-incremental-introduccion
 * Archivo  : funciones.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de abril de 2024, 22:53
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

void cargarDatos(int *&datos, const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	datos = nullptr;
	int dato, numDat = 0, cap = 0;
	while(true) {
		arch >> dato;
		if(arch.eof()) break;
		if(numDat == cap) incrementarMemoria(datos, numDat, cap);
		datos[numDat - 1] = dato;
		numDat++;
	}
}

void incrementarMemoria(int *&datos, int &numDat, int &cap) {
	int *auxDatos;
	cap += INCREMENTO;
	if(datos == nullptr) {
		datos = new int[cap]{};
		numDat = 1;
	} else {
		auxDatos = new int[cap]{};
		for(int i = 0; i < numDat; i++)
			auxDatos[i] = datos[i];
		delete datos;
		datos = auxDatos;
	}
}

void imprimirDatos(int *datos) {
	for(int i = 0; datos[i]; i++)
		cout << setw(8) << datos[i] << endl;
}
