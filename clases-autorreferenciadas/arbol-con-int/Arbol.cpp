/*
 * Proyecto : arbol-con-int
 * Archivo  : Arbol.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 01:20
 */

#include "Arbol.h"

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
	ifstream arch("DatosLL.txt", ios::in);
	if(not arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo DatosLL.txt\n";
		exit(1);
	}
	int dato;
	while(true) {
		arch >> dato;
		if(arch.eof()) break;
		insertarRecursivo(arbol, dato);
	}
}

void Arbol::insertarRecursivo(Nodo *&raiz, int dato) {
	if(raiz == nullptr) {
		raiz = new Nodo;
		raiz->dato = dato;
		return;
	}
	if(dato < raiz->dato)
		insertarRecursivo(raiz->izq, dato);
	else
		insertarRecursivo(raiz->der, dato);
}

void Arbol::insertar(int dato) {
	insertarRecursivo(arbol, dato);
}

void Arbol::mostrarEnOrdenRecursivo(ofstream &arch, Nodo *raiz) {
	if(raiz) {
		mostrarEnOrdenRecursivo(arch, raiz->izq);
		arch << raiz->dato << " ";
		mostrarEnOrdenRecursivo(arch, raiz->der);
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

int Arbol::buscarRecursivo(Nodo *raiz, int dato) {
	if(raiz == nullptr)
		return -1;

	if(dato == raiz->dato) return dato;
	else if(dato < raiz->dato) return buscarRecursivo(raiz->izq, dato);
	else return buscarRecursivo(raiz->der, dato);
}

int Arbol::buscar(int dato) {
	buscarRecursivo(arbol, dato);
}
