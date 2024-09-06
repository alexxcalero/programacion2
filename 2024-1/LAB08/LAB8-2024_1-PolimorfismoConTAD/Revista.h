/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Revista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:07
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
	void SetVigencia(int vigencia);
	int GetVigencia() const;
	void SetNumero(int numero);
	int GetNumero() const;
	void SetAnho(int anho);
	int GetAnho() const;
	void SetISSN(int ISSN);
	int GetISSN() const;
	void lee(ifstream &arch);
	void actualiza();
	void imprime(ofstream &arch);
private:
	int ISSN;
	int anho;
	int numero;
	int vigencia;
};

#endif /* REVISTA_H */
