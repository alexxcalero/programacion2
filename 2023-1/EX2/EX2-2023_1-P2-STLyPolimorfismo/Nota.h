/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : Nota.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 16:10
 */

#ifndef NOTA_H
#define NOTA_H

#include <fstream>
#include "Primera.h"
#include "Segunda.h"
#include "Tercera.h"
#include "CursoAlumno.h"
using namespace std;

class Nota {
public:
	Nota();
	Nota(const Nota &orig);
	virtual ~Nota();
	void leer(ifstream &arch);
	void mostrar(ofstream &arch);
	bool operator <(Nota &nota);
	int GetCodigo();
	string GetCodcur();
	void actualiza(int veces);
private:
	CursoAlumno *pnota;
};

void operator >>(ifstream &arch, Nota &nota);

#endif /* NOTA_H */
