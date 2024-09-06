/*
 * Proyecto : arbol-con-struct
 * Archivo  : Arbol.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 01:45
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbol.h"
#include "Persona.h"
using namespace std;

Arbol::Arbol() {
	arbol = nullptr;
}

Arbol::Arbol(const Arbol &orig) {
}

Arbol::~Arbol() {
	eliminar(arbol);
}

void Arbol::eliminar(Nodo *arbol) {
	if(arbol) {
		eliminar(arbol->izq);
		eliminar(arbol->der);
		delete arbol;
	}
}

void Arbol::crear() {
	ifstream arch("personalLL.csv", ios::in);
	if(not arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo personalLL.csv\n";
		exit(1);
	}
	Persona dato;
	while(true) {
		arch >> dato;
		if(arch.eof()) break;
		insertarRecursivo(arbol, dato);
	}
}

void Arbol::insertarRecursivo(Nodo *&raiz, const Persona &p) {
	if(raiz == nullptr) {
		raiz = new Nodo;
		raiz->dato = p;
		return;
	}
	if(raiz->dato > p)
		insertarRecursivo(raiz->izq, p);
	else
		insertarRecursivo(raiz->der, p);
}

void Arbol::insertar(const Persona &p) {
	insertarRecursivo(arbol, p);
}

void Arbol::mostrarEnOrdenRecursivo(ofstream &arch, Nodo *rec) {
	if(rec) {
		mostrarEnOrdenRecursivo(arch, rec->izq);
		arch << rec->dato;
		mostrarEnOrdenRecursivo(arch, rec->der);
	}
}

void Arbol::mostrarEnOrden() {
	ofstream arch("Reporte.txt", ios::out);
	if(not arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Reporte.txt\n";
		exit(1);
	}
	mostrarEnOrdenRecursivo(arch, arbol);
}

Persona Arbol::buscarRecursivo(Nodo *raiz, int dni) {
	Persona p;
	if(raiz == nullptr) return p;
	if(raiz->dato == dni) return raiz->dato;
	else if(raiz->dato > dni) return buscarRecursivo(raiz->izq, dni);
	else return buscarRecursivo(raiz->der, dni);
}

Persona Arbol::buscar(int dni) {
	buscarRecursivo(arbol, dni);
}
