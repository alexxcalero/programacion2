/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Arbol.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:16
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "NEstante.h"
using namespace std;

class Arbol {
public:
	Arbol();
	Arbol(const Arbol& orig);
	virtual ~Arbol();
	void insertar(NEstante *estante);
	void mostrarEnOrden();
	void asignarNuevoLibro(double peso);
private:
	class NEstante *raiz;
	void insertarRecursivo(NEstante *&raiz, NEstante *estante);
	void mostrarEnOrdenRecursivo(NEstante *raiz, ofstream &arch);
	void asignarRecursivo(NEstante *raiz, double peso, ofstream &arch);
};

#endif /* ARBOL_H */
