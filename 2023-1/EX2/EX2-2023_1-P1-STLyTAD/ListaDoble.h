/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : ListaDoble.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:55
 */

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>
#include <fstream>
#include "Nodo.h"
#include "Alumno.h"
using namespace std;

class ListaDoble {
public:
	ListaDoble();
	ListaDoble(const ListaDoble &orig);
	virtual ~ListaDoble();
	void insertar(Alumno &alumno);
	bool esListaVacia();
	bool buscarAlumno(int codAlumno);
	void leerNotasDelAlumno(ifstream &arch, int ciclo, int codAlumno);
	void imprimir(ofstream &arch);
	void actualizarNotas();
private:
	class Nodo *ini;
	class Nodo *fin;
};

#endif /* LISTADOBLE_H */
