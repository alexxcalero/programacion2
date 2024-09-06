/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Presencial.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:19
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
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
	void leer(ifstream &arch);
	void mostrar(ofstream &arch);
	void actualizarTotal(double precioEscala);
private:
	double recargo;
	double total;
};

#endif /* PRESENCIAL_H */
