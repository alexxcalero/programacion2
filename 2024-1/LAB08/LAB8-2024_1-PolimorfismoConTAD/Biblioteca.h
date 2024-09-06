/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Biblioteca.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:13
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <fstream>
#include "Novela.h"
#include "Revista.h"
#include "Estante.h"
#include "Enciclopedia.h"
using namespace std;

class Biblioteca {
public:
	Biblioteca();
	Biblioteca(const Biblioteca& orig);
	virtual ~Biblioteca();
	void carga();
	void llena();
	void baja();
	void muestra();
	void imprimirLinea(ofstream &arch, int cant, char c);
private:
	Estante AEstantes[10];
};

#endif /* BIBLIOTECA_H */
