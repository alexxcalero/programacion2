/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : Registro.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 16:10
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Nota.h"
using namespace std;

class Registro {
public:
	Registro();
	Registro(const Registro &orig);
	virtual ~Registro();
	void carga();
	void procesa();
	void muestra();
private:
	vector<Nota> vregistro;
};

#endif /* REGISTRO_H */
