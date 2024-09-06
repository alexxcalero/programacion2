/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Semipresencial.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:20
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
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
	void leer(ifstream &arch);
	void mostrar(ofstream &arch);
	void actualizarTotal(double precioEscala);
private:
	double descuento;
	double total;
};

#endif /* SEMIPRESENCIAL_H */
