/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : NPedido.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:16
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

#include <cstring>
#include "Vehiculo.h"

class NPedido {
public:
	NPedido();
	NPedido(const NPedido &orig);
	virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char *codigo);
    void GetCodigo(char *codigo) const;
	friend class Vehiculo;
private:
	char *codigo;
	int cantidad;
	double peso;
	NPedido *sig;
};

#endif /* NPEDIDO_H */
