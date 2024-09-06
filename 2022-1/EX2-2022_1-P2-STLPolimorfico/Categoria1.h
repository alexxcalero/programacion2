/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Categoria1.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:16
 */

#ifndef CATEGORIA1_H
#define CATEGORIA1_H

#include <iomanip>
#include <fstream>
#include "Producto.h"
using namespace std;

class Categoria1 : public Producto {
public:
	Categoria1();
	Categoria1(const Categoria1 &orig);
	virtual ~Categoria1();
    void SetMinimo(int minimo);
    int GetMinimo() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
	void leer(ifstream &arch);
	int obtenerPrioridad();
	void imprimir(ofstream &arch);
private:
	int prioridad;
	int minimo;
};

#endif /* CATEGORIA1_H */
