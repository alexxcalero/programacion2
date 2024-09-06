/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : Facultad.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:56
 */

#ifndef FACULTAD_H
#define FACULTAD_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ListaDoble.h"
using namespace std;

class Facultad {
public:
	Facultad();
	Facultad(const Facultad &orig);
	virtual ~Facultad();
	void leerAlumnosNotas();
	void leerAlumnos();
	void leerNotas();
	void imprimirAlumnosNotas(const char *nombArch);
	void imprimirLinea(ofstream &arch, int cant, char c);
	void actualizarNotas();
private:
	ListaDoble alumnosxNotas;
};

#endif /* FACULTAD_H */
