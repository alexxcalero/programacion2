/*
 * Proyecto : LAB5-2024_1-ListaGenerica
 * Archivo  : FuncionesEnteras.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 3 de mayo de 2024, 08:06
 */

#include <fstream>
#include "FuncionesEnteras.h"
using namespace std;

void *leenum(ifstream &arch) {
	void *dato;
	int _num, *num;
	arch >> _num;
	if(arch.eof()) return nullptr;
	num = new int;
	*num = _num;
	dato = num;
	return dato;
}

void imprimenum(ofstream &arch, void *dato) {
	int *num = (int*)dato;
	arch << *num << endl;
}

int cmpnum(const void *a, const void *b) {
	int *valA = (int*)a;
	int *valB = (int*)b;
	return *valA - *valB;
}
