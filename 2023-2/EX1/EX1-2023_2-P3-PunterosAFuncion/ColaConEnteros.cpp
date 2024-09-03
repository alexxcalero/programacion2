/*
 * Proyecto : EX1-2023_2-P3-PunterosAFuncion
 * Archivo  : ColaConEnteros.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 01:13
 */

#include <iostream>
#include <fstream>
#include "ColaGenerica.h"
#include "ColaConEnteros.h"
using namespace std;

void cargaEnteros(void *&cola, void *(*leenumero)(ifstream &arch), const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	generaCola(cola);
	void *dato;
	while(1) {
		dato = leenumero(arch);
		if(arch.eof()) break;
		encolar(dato, cola);
	}
}

void *leenumero(ifstream &arch) {
	void *dato;
	int _num, *num;

	arch >> _num;
	if(arch.eof()) return nullptr;

	num = new int;
	*num = _num;

	dato = num;

	return dato;
}

void mostrarEnteros(void *cola, void (*imprimenumero)(ofstream &arch, void *), const char *nombArch) {
	ofstream arch(nombArch, ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	void *dato;
	while(!esColaVacia(cola)) {
		dato = desencolar(cola);
		imprimenumero(arch, dato);
	}
}

void imprimenumero(ofstream &arch, void *dato) {
	int *num = (int*)dato;
	arch << *num << endl;
}
