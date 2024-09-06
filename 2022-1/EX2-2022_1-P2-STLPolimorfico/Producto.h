/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Producto.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:12
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Producto {
public:
	Producto();
	Producto(const Producto &orig);
	virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(const char *nombre);
    void GetNombre(char *nombre) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
	virtual void leer(ifstream &arch);
	virtual int obtenerPrioridad() = 0;
	virtual void imprimir(ofstream &arch);
private:
	int codprod;
	char *nombre;
	int stock;
};

#endif /* PRODUCTO_H */
