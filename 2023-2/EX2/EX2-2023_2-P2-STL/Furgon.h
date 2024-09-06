/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : Furgon.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:35
 */

#ifndef FURGON_H
#define FURGON_H

#include <iomanip>
#include <fstream>
#include <list>
#include <iterator>
#include "Pedido.h"
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
	void mostrar(ofstream &arch);
	void insertar(Pedido &pedido);
private:
	int filas;
	int puertas;
	list<Pedido> depositos;  // Insertados de manera ordenada
};

#endif /* FURGON_H */
