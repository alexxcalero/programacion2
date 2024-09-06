/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : NEstante.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:12
 */

#ifndef NESTANTE_H
#define NESTANTE_H

#include <iomanip>
#include <fstream>
#include <vector>
#include "NLibro.h"
using namespace std;

class NEstante {
public:
	NEstante();
	NEstante(const NEstante& orig);
	virtual ~NEstante();
	friend class Arbol;
	void SetDisponible(double disponible);
	double GetDisponible() const;
	void SetCapacidad(double capacidad);
	double GetCapacidad() const;
	void SetId(int id);
	int GetId() const;
	void leer(ifstream &arch);
	void insertarLibros(ifstream &arch);
	void imprimir(ofstream &arch);
	void imprimirLinea(ofstream &arch, int cant, char c);
private:
	int id;
	double capacidad;
	double disponible;
	vector<NLibro> vlibros;
	NEstante *izq;
	NEstante *der;
};

void operator >>(ifstream &arch, NEstante *estante);
void operator <<(ofstream &arch, NEstante *estante);

#endif /* NESTANTE_H */
