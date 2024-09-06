/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Presencial.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:40
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include <iomanip>
#include <fstream>
#include "Alumno.h"
using namespace std;

class Presencial : public Alumno {
public:
	Presencial();
	Presencial(const Presencial &orig);
	virtual ~Presencial();
	void SetRecargo(double recargo);
    double GetRecargo() const;
    void SetTotal(double total);
    double GetTotal() const;
	void leer(ifstream &arch);
	void mostrar(ofstream &arch);
	void modificarTotalAbs(double total);
private:
	double recargo;
	double total;
};

#endif /* PRESENCIAL_H */
