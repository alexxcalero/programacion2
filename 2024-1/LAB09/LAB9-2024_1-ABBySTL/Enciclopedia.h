/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Enciclopedia.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:07
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
	void SetAnho(int anho);
	int GetAnho() const;
	void SetSku(int sku);
	int GetSku() const;
	void leer(ifstream &arch);
	void imprimir(ofstream &arch);
private:
	int sku;
	int anho;
};

#endif /* ENCICLOPEDIA_H */
