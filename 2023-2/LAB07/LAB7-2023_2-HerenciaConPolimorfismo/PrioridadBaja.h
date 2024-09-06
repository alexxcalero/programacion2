/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : PrioridadBaja.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:24
 */

#ifndef PRIORIDADBAJA_H
#define PRIORIDADBAJA_H

#include <iomanip>
#include <fstream>
#include "Pedido.h"
using namespace std;

class PrioridadBaja : public Pedido {
public:
	PrioridadBaja();
	PrioridadBaja(const PrioridadBaja &orig);
	virtual ~PrioridadBaja();
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDias_espera(int dias_espera);
    int GetDias_espera() const;
	void leer(ifstream &arch);
	void actualizar();
	void imprimir(ofstream &arch);
	void convertirNuevaFecha(int &dia, int &mes, int &anho);
private:
	int dias_espera;
	int nueva_fecha_entrega;
};

#endif /* PRIORIDADBAJA_H */
