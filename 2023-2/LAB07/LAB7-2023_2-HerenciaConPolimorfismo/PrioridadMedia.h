/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : PrioridadMedia.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:22
 */

#ifndef PRIORIDADMEDIA_H
#define PRIORIDADMEDIA_H

#include <iomanip>
#include <fstream>
#include <cstring>
#include "Pedido.h"
using namespace std;

class PrioridadMedia : public Pedido {
public:
	PrioridadMedia();
	PrioridadMedia(const PrioridadMedia &orig);
	virtual ~PrioridadMedia();
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDescripcion(const char *descripcion);
    void GetDescripcion(char *descripcion) const;
	void leer(ifstream &arch);
	void actualizar();
	void imprimir(ofstream &arch);
	void convertirNuevaFecha(int &dia, int &mes, int &anho);
private:
	char *descripcion;
	int nueva_fecha_entrega;
};

#endif /* PRIORIDADMEDIA_H */
