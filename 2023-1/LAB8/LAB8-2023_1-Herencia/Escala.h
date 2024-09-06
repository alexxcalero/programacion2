/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Escala.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:39
 */

#ifndef ESCALA_H
#define ESCALA_H

#include <fstream>
using namespace std;

class Escala {
public:
	Escala();
	Escala(const Escala &orig);
	virtual ~Escala();
	void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
	void leer(ifstream &arch);
private:
	int codigo;
	double precio;
};

#endif /* ESCALA_H */
