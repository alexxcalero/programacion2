/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : NLibro.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:11
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include <fstream>
#include "Libro.h"
#include "Novela.h"
#include "Revista.h"
#include "Enciclopedia.h"
using namespace std;

class NLibro {
public:
	NLibro();
	NLibro(const NLibro& orig);
	virtual ~NLibro();
	void asignarMemoria(char tipo);
	void leer(ifstream &arch);
	double getPeso();
	void imprimir(ofstream &arch);
private:
	Libro *plibro;
};

void operator >>(ifstream &arch, NLibro &libro);
void operator <<(ofstream &arch, NLibro &libro);

#endif /* NLIBRO_H */
