/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Tesoreria.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:45
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Escala.h"
#include "Virtual.h"
#include "Presencial.h"
#include "Semipresencial.h"
#define MAX_LIN 100
using namespace std;

class Tesoreria {
public:
	Tesoreria();
	Tesoreria(const Tesoreria &orig);
	virtual ~Tesoreria();
    void setCantEscalas(int cantEscalas);
    int getCantEscalas() const;
    void setCantVirtual(int cantVirtual);
    int getCantVirtual() const;
    void setCantSemipresencial(int cantSemipresencial);
    int getCantSemipresencial() const;
    void setCantPresencial(int cantPresencial);
    int getCantPresencial() const;
	void cargaescalas();
	void cargaalumnos();
	void actualiza(double creditos);
	double buscarPrecioPorEscala(int escala);
	void imprime();
	void imprimirEncabezados(ofstream &arch);
	void imprimirLinea(ofstream &arch, char c);
private:
	Presencial lpresencial[100];
	int cantPresencial;
	Semipresencial lsemipresencial[100];
	int cantSemipresencial;
	Virtual lvirtual[100];
	int cantVirtual;
	Escala lescala[10];
	int cantEscalas;
};

#endif /* TESORERIA_H */
