/*
 * Proyecto : lista-con-struct
 * Archivo  : Lista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 00:28
 */

#ifndef LISTA_H
#define LISTA_H

#include <fstream>
#include "Nodo.h"
#include "Persona.h"
using namespace std;

class Lista {
public:
	Lista();
	Lista(const Lista &orig);
	virtual ~Lista();
	void crear();
	void insertar(const Persona &dato);
	void imprimirIterativo();
	void imprimirRecursivo();
private:
	class Nodo *lista;
	void imprimirRecursivoo(ofstream &arch, Nodo *rec);
};

#endif /* LISTA_H */
