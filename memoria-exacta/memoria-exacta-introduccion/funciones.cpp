/*
 * Proyecto : memoria-exacta-introduccion
 * Archivo  : funciones.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 9 de abril de 2024, 14:35
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

void leerDatos(int *&datos, int &cantDatos, const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	int buff[500], dato;
	cantDatos = 0;
	while(true) {
		arch >> dato;
		if(arch.eof()) break;
		buff[cantDatos] = dato;
		cantDatos++;
	}

	datos = new int[cantDatos];
	for(int i = 0; i < cantDatos; i++)
		datos[i] = buff[i];
}

void imprimirDatos(int *datos, int cantDatos) {
	for(int i = 0; i < cantDatos; i++)
		cout << setw(8) << datos[i] << endl;
}

void leerDatos(int *&datos, const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	int buff[500], dato;
	int cantDatos = 0;
	while(true) {
		arch >> dato;
		if(arch.eof()) break;
		buff[cantDatos] = dato;
		cantDatos++;
	}

	// Es 'cantDatos + 1' para dejar un 0 como marca de fin al final del arreglo
	datos = new int[cantDatos + 1]{};
	for(int i = 0; i < cantDatos; i++)
		datos[i] = buff[i];
}

void imprimirDatos(int *datos) {
	for(int i = 0; datos[i]; i++)
		cout << setw(8) << datos[i] << endl;
}
