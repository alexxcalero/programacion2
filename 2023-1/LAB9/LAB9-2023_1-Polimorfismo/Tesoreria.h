/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Tesoreria.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:25
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Boleta.h"
#include "Escala.h"
using namespace std;

class Tesoreria {
public:
	Tesoreria();
	Tesoreria(const Tesoreria &orig);
	virtual ~Tesoreria();
    void setCantEscalas(int cantEscalas);
    int getCantEscalas() const;
    void setCantBoletas(int cantBoletas);
    int getCantBoletas() const;
	void cargaEscalas();
	void cargaAlumnos();
	void actualizaBoleta();
	int buscarEscala(int codigo);
	void imprimeBoleta();
	void imprimirEncabezados(ofstream &arch);
	void imprimirLinea(ofstream &arch, char c);
private:
	Boleta lboleta[100];
	int cantBoletas;
	Escala lescala[10];
	int cantEscalas;
};

#endif /* TESORERIA_H */
