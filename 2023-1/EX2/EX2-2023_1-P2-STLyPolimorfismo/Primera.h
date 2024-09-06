/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : Primera.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 16:05
 */

#ifndef PRIMERA_H
#define PRIMERA_H

#include <iomanip>
#include <fstream>
#include <string>
#include "CursoAlumno.h"
using namespace std;

class Primera : public CursoAlumno {
public:
	Primera();
	Primera(const Primera &orig);
	virtual ~Primera();
    void SetCodacceso(string codacceso);
    string GetCodacceso() const;
	void leer(ifstream &arch);
	void mostrar(ofstream &arch);
private:
	string codacceso;
};

#endif /* PRIMERA_H */
