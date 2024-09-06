/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Enciclopedia.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:01
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include <iomanip>
#include <fstream>
#include "Libro.h"
using namespace std;

class Enciclopedia : public Libro {
public:
	Enciclopedia();
	Enciclopedia(const Enciclopedia& orig);
	virtual ~Enciclopedia();
	void SetVigencia(int vigencia);
	int GetVigencia() const;
	void SetAnho(int anho);
	int GetAnho() const;
	void SetSku(int sku);
	int GetSku() const;
	void lee(ifstream &arch);
	void actualiza();
	void imprime(ofstream &arch);
private:
	int sku;
	int anho;
	int vigencia;
};

#endif /* ENCICLOPEDIA_H */
