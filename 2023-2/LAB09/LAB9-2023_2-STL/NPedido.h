/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : NPedido.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:46
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

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
	void leer(ifstream &arch);
	void imprimir(ofstream &arch);
private:
	char *codigo;
	int cantidad;
	double peso;
};

void operator >>(ifstream &arch, NPedido &ped);
void operator <<(ofstream &arch, NPedido &ped);

#endif /* NPEDIDO_H */
