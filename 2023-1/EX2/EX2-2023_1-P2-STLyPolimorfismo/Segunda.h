/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : Segunda.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 16:08
 */

#ifndef SEGUNDA_H
#define SEGUNDA_H

#include <iomanip>
#include <fstream>
#include "CursoAlumno.h"
using namespace std;

class Segunda : public CursoAlumno {
public:
	Segunda();
	Segunda(const Segunda &orig);
	virtual ~Segunda();
    void SetCreditos(double creditos);
    double GetCreditos() const;
	void actualiza(CursoAlumno *otro, int veces);
	void mostrar(ofstream &arch);
private:
	double creditos;
};

#endif /* SEGUNDA_H */
