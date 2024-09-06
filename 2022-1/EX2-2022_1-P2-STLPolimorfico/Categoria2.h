/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Categoria2.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:17
 */

#ifndef CATEGORIA2_H
#define CATEGORIA2_H

#include <iomanip>
#include <fstream>
#include "Producto.h"
using namespace std;

class Categoria2 : public Producto {
public:
	Categoria2();
	Categoria2(const Categoria2 &orig);
	virtual ~Categoria2();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
	void leer(ifstream &arch);
	int obtenerPrioridad();
	void imprimir(ofstream &arch);
private:
	int prioridad;
	double descuento;
};

#endif /* CATEGORIA2_H */
