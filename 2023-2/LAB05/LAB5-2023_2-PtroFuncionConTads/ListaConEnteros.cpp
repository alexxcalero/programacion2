/*
 * Proyecto : LAB5-2023_2-PtroFuncionConTads
 * Archivo  : ListaConEnteros.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 2 de mayo de 2024, 18:49
 */

#include <fstream>
#include "Enums.h"
#include "ListaConEnteros.h"
using namespace std;

void *leenumero(ifstream &arch) {
	void *dato;
	double num, *ptrNum;

	arch >> num;
	if(arch.eof()) return nullptr;
	ptrNum = new double;
	*ptrNum = num;

	dato = ptrNum;

	return dato;
}

double calculanumero(void *dato) {
	double *num = (double*)dato;
	return *num;
}

int cmpnumero(const void *valor1, const void *valor2) {
	void **auxValor1 = (void**)valor1, **auxValor2 = (void**)valor2;
	void **lista1 = (void**)(*auxValor1), **lista2 = (void**)(*auxValor2);
	double *peso1 = (double*)lista1[PESOCAMION], *peso2 = (double*)lista2[PESOCAMION];
	return *peso2 - *peso1;
}

void imprimenumero(void *lista, ofstream &arch) {
	void **recorrido = (void**)lista;
	while(recorrido) {
		void **registro = (void**)recorrido;
		double *num = (double*)recorrido[DATO];
		arch << *num << endl;
		recorrido = (void**)recorrido[SIG];
	}
}
