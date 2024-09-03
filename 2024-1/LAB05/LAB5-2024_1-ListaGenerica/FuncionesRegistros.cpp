/*
 * Proyecto : LAB5-2024_1-ListaGenerica
 * Archivo  : FuncionesRegistros.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 3 de mayo de 2024, 08:45
 */

#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesRegistros.h"
using namespace std;

void *leeregistro(ifstream &arch) {
	void **registro;
	int _num, *num, _dni, *dni;
	char *codigo, c;

	arch >> _num;
	if(arch.eof()) return nullptr;
	arch >> c >> _dni;
	arch.get();
	codigo = leerCadena(arch, 8, '\n');

	num = new int; *num = _num;
	dni = new int; *dni = _dni;

	registro = new void*[3]{};
	registro[NUM] = num;
	registro[DNI] = dni;
	registro[COD] = codigo;

	return registro;
}

char *leerCadena(ifstream &arch, int size, char delim) {
	char *cadena, buffCad[size];
	arch.getline(buffCad, size, delim);
	if(arch.eof()) return nullptr;
	cadena = new char[strlen(buffCad) + 1];
	strcpy(cadena, buffCad);
	return cadena;
}

void imprimeregistro(ofstream &arch, void *dato) {
	void **registro = (void**)dato;
	int *num = (int*)registro[NUM];
	int *dni = (int*)registro[DNI];
	char *cod = (char*)registro[COD];
	arch << left << setw(10) << *num << setw(10) << *dni << cod << endl;
}

int cmpregistro(const void *a, const void *b) {
	void **regA = (void**)a, **regB = (void**)b;
	int *numA =(int*)regA[NUM], *numB = (int*)regB[NUM];
	return *numA - *numB;
}
