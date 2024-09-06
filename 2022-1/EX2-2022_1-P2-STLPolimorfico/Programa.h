/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Programa.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:22
 */

#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Lista.h"
#include "NProducto.h"
using namespace std;

class Programa {
public:
	Programa();
	Programa(const Programa &orig);
	virtual ~Programa();
	void Carga();
	void Actualiza();
	void Imprime();
private:
	Lista lpedidos;
	vector<NProducto> vproductos;
	void CargaProductos();
	void CargaLista();
	void ImprimeProductos();
	void imprimirEncabezadosDeProductos(ofstream &arch);
	void ImprimeLista();
	void imprimirEncabezadosDePedidos(ofstream &arch);
	void imprimirLinea(ofstream &arch, int cant, char c);
};

#endif /* PROGRAMA_H */
