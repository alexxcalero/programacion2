/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Biblioteca.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:17
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbol.h"
#include "NEstante.h"
using namespace std;

class Biblioteca {
public:
	Biblioteca();
	Biblioteca(const Biblioteca& orig);
	virtual ~Biblioteca();
	void carga();
	void muestra();
	void prueba(double peso);
private:
	Arbol AEstante;
};

#endif /* BIBLIOTECA_H */
