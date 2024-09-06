/*
 * Proyecto : EX2-2023_2-P3-TADs
 * Archivo  : Arbol.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 23:23
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <fstream>
#include "Nodo.h"
#include "Vehiculo.h"
using namespace std;

class Arbol {
public:
	Arbol();
	Arbol(const Arbol &orig);
	virtual ~Arbol();
	void insertar(Vehiculo *vehiculo);
	void imprimirEnOrden();
	void eliminarNodos(int cantidad);
private:
	class Nodo *raiz;  // Ordenado por el dni
	void insertarRecursivo(Nodo *&raiz, Vehiculo *vehiculo);
	class Nodo *eliminarNodosRecursivo(Nodo *raiz, int &cantidad);
	void imprimirEnOrdenRecursivo(Nodo *raiz, ofstream &arch);
};

#endif /* ARBOL_H */
