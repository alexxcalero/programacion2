/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : Camion.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:33
 */

#ifndef CAMION_H
#define CAMION_H

#include <iomanip>
#include <fstream>
#include <vector>
#include "Pedido.h"
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
	void mostrar(ofstream &arch);
	void insertar(Pedido &pedido);
private:
	int ejes;
	int llantas;
	vector<Pedido> depositos;  // Maximo 5 pedidos
};

#endif /* CAMION_H */
