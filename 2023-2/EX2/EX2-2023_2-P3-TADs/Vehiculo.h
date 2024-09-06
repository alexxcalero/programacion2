/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : Vehiculo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:31
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <iomanip>
#include <fstream>
#include <string>
#include "Pedido.h"
using namespace std;

class Vehiculo {
public:
	Vehiculo();
	Vehiculo(const Vehiculo &orig);
	virtual ~Vehiculo();
    void SetCargaActual(double cargaActual);
    double GetCargaActual() const;
    void SetCargaMaxima(double cargaMaxima);
    double GetCargaMaxima() const;
    void SetPlaca(string placa);
    string GetPlaca() const;
    void SetDni(int dni);
    int GetDni() const;
	virtual void leer(ifstream &arch);
	virtual void mostrar(ofstream &arch);
	virtual void insertar(Pedido &pedido) = 0;
private:
	int dni;
	string placa;
	double cargaMaxima;
	double cargaActual;
};

#endif /* VEHICULO_H */
