/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : Furgon.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:55
 */

#ifndef FURGON_H
#define FURGON_H

#include <iomanip>
#include <fstream>
#include <list>
#include <iterator>
#include "NPedido.h"
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
	bool verificarCantidadDeCarros();
	void cargarDeposito(NPedido &pedido);
private:
	int filas;
	int puertas;
	list<NPedido> pdeposito;
};

#endif /* FURGON_H */
