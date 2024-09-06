/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : OrdenVenta.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:25
 */

#ifndef ORDENVENTA_H
#define ORDENVENTA_H

#include <fstream>
#include "Pedido.h"
#include "PrioridadBaja.h"
#include "PrioridadAlta.h"
#include "PrioridadMedia.h"
using namespace std;

class OrdenVenta {
public:
	OrdenVenta();
	OrdenVenta(const OrdenVenta &orig);
	virtual ~OrdenVenta();
	void asignarMemoria(char categoria);
	void leerDatos(ifstream &arch);
	void imprimirDatos(ofstream &arch);
	void actualizarDatos();
private:
	Pedido *ptr_orden;
};

#endif /* ORDENVENTA_H */
