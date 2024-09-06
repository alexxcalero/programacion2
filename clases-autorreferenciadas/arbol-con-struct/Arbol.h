/*
 * Proyecto : arbol-con-struct
 * Archivo  : Arbol.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 01:45
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <fstream>
#include "Nodo.h"
#include "Persona.h"
using namespace std;

class Arbol {
public:
	Arbol();
	Arbol(const Arbol &orig);
	virtual ~Arbol();
	void crear();
	void insertar(const Persona &p);
	void mostrarEnOrden();
	Persona buscar(int dni);
private:
	class Nodo *arbol;
	void insertarRecursivo(Nodo *&raiz, const Persona &p);
	void mostrarEnOrdenRecursivo(ofstream &arch, Nodo *rec);
	Persona buscarRecursivo(Nodo *raiz, int dni);
	void eliminar(Nodo *arbol);
};

#endif /* ARBOL_H */
