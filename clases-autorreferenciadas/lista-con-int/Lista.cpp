/*
 * Proyecto : lista-con-int
 * Archivo  : Lista.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 00:07
 */

#include "Lista.h"

Lista::Lista() {
	lista = nullptr;
}

Lista::Lista(const Lista &orig) {
}

Lista::~Lista() {
	Nodo *eliminar;
	while(lista) {
		eliminar = lista;
		lista = lista->siguiente;
		delete eliminar;
	}
	lista = nullptr;
}

void Lista::crear() {
	ifstream arch("datos.txt", ios::in);
	if(not arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo datos.txt\n";
		exit(1);
	}
	int dato;
	while(true) {
		arch >> dato;
		if(arch.eof()) break;
		insertar(dato);
	}
}

void Lista::insertar(int dato) {
	Nodo *recorrido = lista;
	Nodo *anterior = nullptr;
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->dato = dato;
	while(recorrido) {
		if(recorrido->dato > dato)
			break;
		anterior = recorrido;
		recorrido = recorrido->siguiente;
	}
	nuevoNodo->siguiente = recorrido;
	if(anterior == nullptr) lista = nuevoNodo;
	else anterior->siguiente = nuevoNodo;
}

void Lista::imprimirIterativo() {
	ofstream arch("ImpresionIterativa.txt", ios::out);
	if(not arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ImpresionIterativa.txt\n";
		exit(1);
	}
	arch << "IMPRESION DE MANERA ITERATIVA\n";
	Nodo *recorrido = lista;
	while(recorrido) {
		arch << recorrido->dato << " ";
		recorrido = recorrido->siguiente;
	}
}

void Lista::imprimirRecursivoo(ofstream &arch, Nodo *rec) {
	if(rec == nullptr)
		return;

	arch << rec->dato << " ";
	imprimirRecursivoo(arch, rec->siguiente);
}

void Lista::imprimirRecursivo() {
	ofstream arch("ImpresionRecursiva.txt", ios::out);
	if(not arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ImpresionRecursiva.txt\n";
		exit(1);
	}
	arch << "IMPRESION DE MANERA RECURSIVA\n";
	imprimirRecursivoo(arch, lista);
}
