/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : Camion.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:52
 */

#ifndef CAMION_H
#define CAMION_H

#include <iomanip>
#include <fstream>
#include <map>
#include <iterator>
#include "NPedido.h"
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
	bool verificarCantidadDeCarros();
	void cargarDeposito(NPedido &pedido);
private:
	int ejes;
	int llantas;
	map<int, NPedido> mdeposito;
};

#endif /* CAMION_H */
