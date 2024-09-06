/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Virtual.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:21
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
	void actualizarTotal(double precioEscala);
private:
	char *licencia;
	double total;
};

#endif /* VIRTUAL_H */
