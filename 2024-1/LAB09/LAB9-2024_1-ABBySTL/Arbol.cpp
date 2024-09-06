/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Arbol.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:16
 */

#include "Arbol.h"

Arbol::Arbol() {
	raiz = nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}

void Arbol::insertar(NEstante *estante) {
	insertarRecursivo(raiz, estante);
}

void Arbol::insertarRecursivo(NEstante *&raiz, NEstante *estante) {
	if(raiz == nullptr) {
		raiz = estante;
	} else {
		if(estante->disponible < raiz->disponible)
			insertarRecursivo(raiz->izq, estante);
		else
			insertarRecursivo(raiz->der, estante);
	}
}

void Arbol::mostrarEnOrden() {
	ofstream arch("ReporteDeEstantes.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDeEstantes.txt\n";
		exit(1);
	}
	mostrarEnOrdenRecursivo(raiz, arch);

}

void Arbol::mostrarEnOrdenRecursivo(NEstante *raiz, ofstream &arch) {
	if(raiz != nullptr) {
		mostrarEnOrdenRecursivo(raiz->izq, arch);
		arch << raiz;
		mostrarEnOrdenRecursivo(raiz->der, arch);
	}
}

void Arbol::asignarNuevoLibro(double peso) {
	ofstream archPrueba("ReporteEstanteAgregado.txt", ios::out);
	asignarRecursivo(raiz, peso, archPrueba);
}

void Arbol::asignarRecursivo(NEstante *raiz, double peso, ofstream &arch) {
	if(raiz != nullptr) {
		if(raiz->disponible >= peso) {
			arch << raiz;
			return;
		}
		asignarRecursivo(raiz->izq, peso, arch);
		asignarRecursivo(raiz->der, peso, arch);
	}
}
