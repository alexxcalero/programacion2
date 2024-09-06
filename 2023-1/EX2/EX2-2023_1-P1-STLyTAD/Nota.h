/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : Nota.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:46
 */

#ifndef NOTA_H
#define NOTA_H

#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Nota {
public:
	Nota();
	Nota(const Nota &orig);
	virtual ~Nota();
    void SetVez(int vez);
    int GetVez() const;
    void SetCalificacion(int calificacion);
    int GetCalificacion() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetCodigoDelCurso(string codigoDelCurso);
    string GetCodigoDelCurso() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
	void leer(ifstream &arch);
	void imprimir(ofstream &arch);
private:
	int ciclo;
	string codigoDelCurso;
	double creditos;
	int calificacion;
	int vez;
};

void operator >>(ifstream &arch, Nota &nota);

#endif /* NOTA_H */
