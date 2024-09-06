/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Semipresencial.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:43
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include <iomanip>
#include <fstream>
#include "Alumno.h"
using namespace std;

class Semipresencial : public Alumno {
public:
	Semipresencial();
	Semipresencial(const Semipresencial &orig);
	virtual ~Semipresencial();
    void SetDescuento(double descuento);
    double GetDescuento() const;
	void SetTotal(double total);
    double GetTotal() const;
	void leer(ifstream &arch);
	void mostrar(ofstream &arch);
	void modificarTotalAbs(double total);
private:
	double descuento;
	double total;
};

#endif /* SEMIPRESENCIAL_H */
