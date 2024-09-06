/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Virtual.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:44
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include <iomanip>
#include <fstream>
#include <cstring>
#include "Alumno.h"
using namespace std;

class Virtual : public Alumno {
public:
	Virtual();
	Virtual(const Virtual &orig);
	virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char *licencia);
    void GetLicencia(char *licencia) const;
	void leer(ifstream &arch);
	void mostrar(ofstream &arch);
	void modificarTotalAbs(double total);
private:
	char *licencia;
	double total;
};

#endif /* VIRTUAL_H */
