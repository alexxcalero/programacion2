/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : PrioridadAlta.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:20
 */

#ifndef PRIORIDADALTA_H
#define PRIORIDADALTA_H

#include <iomanip>
#include <fstream>
#include "Pedido.h"
using namespace std;

class PrioridadAlta : public Pedido {
public:
	PrioridadAlta();
	PrioridadAlta(const PrioridadAlta &orig);
	virtual ~PrioridadAlta();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
	void leer(ifstream &arch);
	void actualizar();
	void imprimir(ofstream &arch);
private:
	double recargo;
	double total;
};

#endif /* PRIORIDADALTA_H */
