/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : Alumno.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:41
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Alumno {
public:
	Alumno();
	Alumno(const Alumno &orig);
	virtual ~Alumno();
    void SetPromedio(double promedio);
    double GetPromedio() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
	void leer(ifstream &arch);
	void imprimir(ofstream &arch);
private:
	int codigo;
	string nombre;
	double promedio;
};

void operator >>(ifstream &arch, Alumno &alumno);

#endif /* ALUMNO_H */
