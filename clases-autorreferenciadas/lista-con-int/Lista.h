/*
 * Proyecto : lista-con-int
 * Archivo  : Lista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 00:07
 */

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Nodo.h"
using namespace std;

class Lista {
public:
	Lista();
	Lista(const Lista &orig);
	virtual ~Lista();
	void crear();
	void insertar(int dato);
	void imprimirIterativo();
	void imprimirRecursivo();
private:
	class Nodo *lista;
	void imprimirRecursivoo(ofstream &arch, class Nodo *rec);
};

#endif /* LISTA_H */
