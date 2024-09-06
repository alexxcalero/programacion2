/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Lista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:21
 */

#ifndef LISTA_H
#define LISTA_H

#include <fstream>
#include "Nodo.h"
#include "Pedido.h"
using namespace std;

class Lista {
public:
	Lista();
	Lista(const Lista &orig);
	virtual ~Lista();
	friend class Nodo;
	void crear(ifstream &arch);
	void insertarOrdenado(Pedido *ped);
	bool esListaVacia();
	void reordenar(int codigo);
	void imprimir(ofstream &arch);
private:
	class Nodo *lini;
	class Nodo *lfin;
};

#endif /* LISTA_H */
