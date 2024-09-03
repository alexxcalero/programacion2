/*
 * Proyecto : LAB5-2024_1-ListaGenerica
 * Archivo  : BibliotecaGenerica.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 3 de mayo de 2024, 08:05
 */

#include <iostream>
#include <fstream>
#include "BibliotecaGenerica.h"
using namespace std;

void crealista(void *&lista, void *(*leenum)(ifstream &), const char*nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	void **auxLista = new void*[2]{};
	lista = auxLista;
	void *dato;
	while(1) {
		dato = leenum(arch);
		if(arch.eof()) break;
		insertalista(dato, lista);
	}
}

bool listavacia(void *list) {
	void **lista = (void**)list;
	if(lista[CAB] == nullptr && lista[COL] == nullptr)
		return true;
	else
		return false;
}

void insertalista(void *dato, void *lista) {
	void **auxLista = (void**)lista;
	void **nuevoNodo = new void*[2]{};
	nuevoNodo[DATO] = dato;
	nuevoNodo[SIG] = nullptr;
	if(listavacia(lista)) {
		auxLista[CAB] = nuevoNodo;
	} else {
		void **ultimo = (void**)auxLista[COL];
		ultimo[SIG] = nuevoNodo;
	}
	auxLista[COL] = nuevoNodo;
}

void imprimelista(void *lista, void (*imprimenum)(ofstream &, void*), const char *nombArch) {
	ofstream arch(nombArch, ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	void **auxLista = (void**)lista;
	void **recorrido = (void**)auxLista[CAB];
	while(recorrido) {
		imprimenum(arch, recorrido[DATO]);
		recorrido = (void**)recorrido[SIG];
	}
}

void combinalista(void *lista1, void *lista2, void *&listafinal, int (*cmpnum)(const void*, const void*)) {
	void **auxListaFinal = new void*[2]{};
	listafinal = auxListaFinal;

	void **auxLista1, **auxLista2, **rec1, **rec2, *datoL1, *datoL2;

	while(!listavacia(lista1) && !listavacia(lista2)) {
		auxLista1 = (void**)lista1;
		auxLista2 = (void**)lista2;
		rec1 = (void**)auxLista1[CAB];
		rec2 = (void**)auxLista2[CAB];
		if(cmpnum(rec1[DATO], rec2[DATO]) < 0) {
			datoL1 = quitalista(lista1);
			insertalista(datoL1, listafinal);
		} else if(cmpnum(rec1[DATO], rec2[DATO]) > 0) {
			datoL2 = quitalista(lista2);
			insertalista(datoL2, listafinal);
		} else {
			datoL1 = quitalista(lista1);
			datoL2 = quitalista(lista2);
			insertalista(datoL1, listafinal);
		}
	}

	while(!listavacia(lista1)) {
		datoL1 = quitalista(lista1);
		insertalista(datoL1, listafinal);
	}

	while(!listavacia(lista2)) {
		datoL2 = quitalista(lista2);
		insertalista(datoL2, listafinal);
	}
}

void *quitalista(void *lista) {
	void **auxLista = (void**)lista;
	void **cabeza = (void**)auxLista[CAB];
	auxLista[CAB] = cabeza[SIG];
	if(auxLista[CAB] == nullptr)
		auxLista[COL] = nullptr;
	cabeza[SIG] = nullptr;
	return cabeza[DATO];
}
