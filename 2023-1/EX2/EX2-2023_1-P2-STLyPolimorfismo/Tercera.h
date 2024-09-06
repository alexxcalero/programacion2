/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : Tercera.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 16:09
 */

#ifndef TERCERA_H
#define TERCERA_H

#include <iomanip>
#include <fstream>
#include "CursoAlumno.h"
using namespace std;

class Tercera : public CursoAlumno {
public:
	Tercera();
	Tercera(const Tercera &orig);
	virtual ~Tercera();
    void SetPorcentaje(double porcentaje);
    double GetPorcentaje() const;
	void actualiza(CursoAlumno *otro, int veces);
	void mostrar(ofstream &arch);
private:
	double porcentaje;
};

#endif /* TERCERA_H */
