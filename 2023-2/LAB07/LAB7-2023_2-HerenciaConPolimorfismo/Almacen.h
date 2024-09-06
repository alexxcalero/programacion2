/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : Almacen.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:25
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "OrdenVenta.h"
using namespace std;

class Almacen {
public:
	Almacen();
	Almacen(const Almacen &orig);
	virtual ~Almacen();
    void SetCantidad_ordenes(int cantidad_ordenes);
    int GetCantidad_ordenes() const;
	void cargar_pedidos();
	void actualizar_pedidos();
	void imprimir_ordenes_ventas();
	void imprimirEncabezados(ofstream &arch);
	void imprimirLinea(ofstream &arch, char c);
private:
	OrdenVenta ordenes[600];
	int cantidad_ordenes;
};

#endif /* ALMACEN_H */
