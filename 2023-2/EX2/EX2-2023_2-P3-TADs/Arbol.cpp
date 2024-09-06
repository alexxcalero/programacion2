/*
 * Proyecto : EX2-2023_2-P3-TADs
 * Archivo  : Arbol.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 23:23
 */

#include "Arbol.h"

Arbol::Arbol() {
	raiz = nullptr;
}

Arbol::Arbol(const Arbol &orig) {
}

Arbol::~Arbol() {
}

void Arbol::insertar(Vehiculo *vehiculo) {
	insertarRecursivo(raiz, vehiculo);
}

void Arbol::insertarRecursivo(Nodo *&raiz, Vehiculo *vehiculo) {
	if(raiz == nullptr) {
		Nodo *nuevoNodo = new Nodo;
		nuevoNodo->unidad = vehiculo;
		nuevoNodo->der = nullptr;
		nuevoNodo->izq = nullptr;
		raiz = nuevoNodo;
	}
	else if(raiz->unidad->GetDni() > vehiculo->GetDni())
		insertarRecursivo(raiz->izq, vehiculo);
	else
		insertarRecursivo(raiz->der, vehiculo);
}

void Arbol::eliminarNodos(int cantidad) {
	raiz = eliminarNodosRecursivo(raiz, cantidad);
}

Nodo *Arbol::eliminarNodosRecursivo(Nodo *raiz, int &cantidad) {
	if(raiz == nullptr || cantidad <= 0)
		return raiz;

	raiz->izq = eliminarNodosRecursivo(raiz->izq, cantidad);
	raiz->der = eliminarNodosRecursivo(raiz->der, cantidad);

	if(raiz->izq == nullptr && raiz->der == nullptr && cantidad > 0) {
		delete raiz;
		cantidad--;
		return nullptr;
	}

	return raiz;
}

void Arbol::imprimirEnOrden() {
	ofstream arch("ReporteDeVehiculos.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDeVehiculos.txt\n";
		exit(1);
	}
	imprimirEnOrdenRecursivo(raiz, arch);
}

void Arbol::imprimirEnOrdenRecursivo(Nodo *raiz, ofstream &arch) {
	if(raiz != nullptr) {
		imprimirEnOrdenRecursivo(raiz->izq, arch);
		raiz->unidad->mostrar(arch);
		imprimirEnOrdenRecursivo(raiz->der, arch);
	}
}
