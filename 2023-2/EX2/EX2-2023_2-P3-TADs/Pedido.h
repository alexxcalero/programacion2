/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : Pedido.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:27
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Pedido {
public:
	Pedido();
	Pedido(const Pedido &orig);
	virtual ~Pedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
	void mostrar(ofstream &arch);
private:
	string codigo;
	int cantidad;
	double peso;
};

void operator >>(ifstream &arch, Pedido &pedido);

#endif /* PEDIDO_H */
