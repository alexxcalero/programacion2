/*
 * Proyecto : LAB5-2023_2-PtroFuncionConTads
 * Archivo  : ListaConRegistros.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 2 de mayo de 2024, 19:20
 */

#include <iomanip>
#include <fstream>
#include <cstring>
#include "Enums.h"
#include "ListaConRegistros.h"
using namespace std;

void *leeregistro(ifstream &arch) {
	void **registro;
	char *codigo, c;
	int dni, cant, *ptrCant;
	double peso, *ptrPeso;

	codigo = leerCadena(arch, 8, ',');
	if(arch.eof()) return nullptr;
	arch >> dni >> c >> cant >> c >> peso;
	arch.get();  // Leo el salto de linea

	ptrCant = new int; *ptrCant = cant;
	ptrPeso = new double; *ptrPeso = peso;

	registro = new void*[3]{};
	registro[COD] = codigo;
	registro[CANT] = ptrCant;
	registro[PESO] = ptrPeso;

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

double calcularegistro(void *dato) {
	void **registro = (void**)dato;
	double *num = (double*)registro[PESO];
	return *num;
}

int cmpregistro(const void *valor1, const void *valor2) {
	void **auxValor1 = (void**)valor1, **auxValor2 = (void**)valor2;
	void **lista1 = (void**)(*auxValor1), **lista2 = (void**)(*auxValor2);
	double *peso1 = (double*)lista1[PESOCAMION], *peso2 = (double*)lista2[PESOCAMION];
	return *peso2 - *peso1;
}

void imprimeregistro(void *lista, ofstream &arch) {
	void **recorrido = (void**)lista;
	while(recorrido) {
		void **camion = (void**)recorrido[DATO];
		char *codigo = (char*)camion[COD];
		int *cant = (int*)camion[CANT];
		double *peso = (double*)camion[PESO];
		arch << setw(15) << codigo << setw(15) << *cant << fixed << setprecision(2) << setw(15) << *peso << endl;
		recorrido = (void**)recorrido[SIG];
	}
	arch << endl;
}
