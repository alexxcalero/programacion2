/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Escala.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:17
 */

#ifndef ESCALA_H
#define ESCALA_H

#include <iostream>
#include <fstream>
using namespace std;

class Escala {
public:
	Escala();
	Escala(const Escala &orig);
	virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
	void leer(ifstream &arch);
	void mostrar();
	void operator =(Escala &e);
private:
	int codigo;
	double precio;
};

#endif /* ESCALA_H */
