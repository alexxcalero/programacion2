/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : NProducto.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:19
 */

#ifndef NPRODUCTO_H
#define NPRODUCTO_H

#include <fstream>
#include "Producto.h"
#include "Categoria1.h"
#include "Categoria2.h"
#include "Categoria3.h"
using namespace std;

class NProducto {
public:
	NProducto();
	NProducto(const NProducto &orig);
	virtual ~NProducto();
	void asignarMemoria(int categoria);
	void leer(ifstream &arch);
	int obtenerPrioridad();
	int obtenerCodigo();
	void imprimir(ofstream &arch);
private:
	Producto *prod;
};

void operator >>(ifstream &arch, NProducto &prod);
void operator <<(ofstream &arch, NProducto &prod);

#endif /* NPRODUCTO_H */
