/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : Camion.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:24
 */

#ifndef CAMION_H
#define CAMION_H

#include <iomanip>
#include <fstream>
#include "Vehiculo.h"
using namespace std;

class Camion : public Vehiculo {
public:
	Camion();
	Camion(const Camion &orig);
	virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
	void leer(ifstream &arch);
	void imprimir(ofstream &arch);
private:
	int ejes;
	int llantas;
};

#endif /* CAMION_H */
