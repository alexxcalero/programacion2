/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Novela.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:08
 */

#ifndef NOVELA_H
#define NOVELA_H

#include <iomanip>
#include <fstream>
#include <cstring>
#include "Libro.h"
using namespace std;

class Novela : public Libro {
public:
	Novela();
	Novela(const Novela& orig);
	virtual ~Novela();
	void SetAutor(const char *autor);
	void GetAutor(char *autor) const;
	void leer(ifstream &arch);
	void imprimir(ofstream &arch);
private:
	char *autor;
};

#endif /* NOVELA_H */
