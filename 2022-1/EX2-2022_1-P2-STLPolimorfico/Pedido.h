/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Pedido.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:11
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <iomanip>
#include <fstream>
using namespace std;

class Pedido {
public:
	Pedido();
	Pedido(const Pedido &orig);
	virtual ~Pedido();
    void SetOrden(int orden);
    int GetOrden() const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
	void leer(ifstream &arch);
	void imprimir(ofstream &arch);
	void convertirFecha(int &dia, int &mes, int &anho);
private:
	int codigo;
	int cantidad;
	int dni;
	int fecha;
	double total;
	int orden;
};

void operator >>(ifstream &arch, Pedido *ped);
void operator <<(ofstream &arch, Pedido *ped);

#endif /* PEDIDO_H */
