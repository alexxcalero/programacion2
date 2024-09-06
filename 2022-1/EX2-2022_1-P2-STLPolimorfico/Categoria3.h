/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Categoria3.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:18
 */

#ifndef CATEGORIA3_H
#define CATEGORIA3_H

#include <iomanip>
#include <fstream>
#include "Producto.h"
using namespace std;

class Categoria3 : public Producto {
public:
	Categoria3();
	Categoria3(const Categoria3 &orig);
	virtual ~Categoria3();
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

#endif /* CATEGORIA3_H */
