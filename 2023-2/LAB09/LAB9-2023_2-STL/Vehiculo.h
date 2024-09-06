/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : Vehiculo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:48
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <iomanip>
#include <fstream>
#include <cstring>
#include "NPedido.h"
using namespace std;

class Vehiculo {
public:
	Vehiculo();
	Vehiculo(const Vehiculo &orig);
	virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char *placa);
    void GetPlaca(char *placa) const;
    void SetCliente(int cliente);
    int GetCliente() const;
	virtual void leer(ifstream &arch);
	virtual void imprimir(ofstream &arch);
	virtual bool verificarCantidadDeCarros() = 0;
	virtual void cargarDeposito(NPedido &pedido) = 0;
private:
	int cliente;
	char *placa;
	double maxcarga;
	double actcarga;
};

#endif /* VEHICULO_H */
