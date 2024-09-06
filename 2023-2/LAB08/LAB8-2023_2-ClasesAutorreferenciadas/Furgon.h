/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : Furgon.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:25
 */

#ifndef FURGON_H
#define FURGON_H

#include <iomanip>
#include <fstream>
#include "Vehiculo.h"
using namespace std;

class Furgon : public Vehiculo {
public:
	Furgon();
	Furgon(const Furgon &orig);
	virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
	void leer(ifstream &arch);
	void imprimir(ofstream &arch);
private:
	int filas;
	int puertas;
};

#endif /* FURGON_H */
