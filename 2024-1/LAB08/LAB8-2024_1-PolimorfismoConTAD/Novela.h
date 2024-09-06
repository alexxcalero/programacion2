/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Novela.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:04
 */

#ifndef NOVELA_H
#define NOVELA_H

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
	void lee(ifstream &arch);
	void actualiza();
	void imprime(ofstream &arch);
private:
	char *autor;
};

#endif /* NOVELA_H */
