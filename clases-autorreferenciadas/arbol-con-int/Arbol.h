/*
 * Proyecto : arbol-con-int
 * Archivo  : Arbol.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 01:20
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Nodo.h"
using namespace std;

class Arbol {
public:
	Arbol();
	Arbol(const Arbol &orig);
	virtual ~Arbol();
	void crear();
	void insertar(int dato);
	void mostrarEnOrden();
	int buscar(int dato);
private:
	class Nodo *arbol;
	void insertarRecursivo(Nodo *&raiz, int dato);
	void mostrarEnOrdenRecursivo(ofstream &arch, Nodo *raiz);
	int buscarRecursivo(Nodo *raiz, int dato);
	void eliminar(Nodo *arbol);
};

#endif /* ARBOL_H */
