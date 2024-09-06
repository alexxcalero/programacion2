/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Boleta.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:24
 */

#ifndef BOLETA_H
#define BOLETA_H

#include <fstream>
#include "Alumno.h"
#include "Virtual.h"
#include "Presencial.h"
#include "Semipresencial.h"
using namespace std;

class Boleta {
public:
	Boleta();
	Boleta(const Boleta &orig);
	virtual ~Boleta();
	void asignarAlumno(ifstream &arch, char categoria);
	void asignarCategoria(char categoria);
	void imprimir(ofstream &arch);
	void actualizarTotal();
	void calcularTotal(double precioEscala);
	int GetEscala();
private:
	Alumno *pboleta;
};

#endif /* BOLETA_H */
