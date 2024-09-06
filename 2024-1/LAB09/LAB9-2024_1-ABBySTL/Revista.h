/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Revista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:10
 */

#ifndef REVISTA_H
#define REVISTA_H

#include <iomanip>
#include <fstream>
#include "Libro.h"
using namespace std;

class Revista : public Libro {
public:
	Revista();
	Revista(const Revista& orig);
	virtual ~Revista();
	void SetNumero(int numero);
	int GetNumero() const;
	void SetAnho(int anho);
	int GetAnho() const;
	void SetIssn(int issn);
	int GetIssn() const;
	void leer(ifstream &arch);
	void imprimir(ofstream &arch);
private:
	int issn;
	int anho;
	int numero;
};

#endif /* REVISTA_H */
