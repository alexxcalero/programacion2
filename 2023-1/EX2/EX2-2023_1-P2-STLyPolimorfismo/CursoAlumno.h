/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : CursoAlumno.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 15:54
 */

#ifndef CURSOALUMNO_H
#define CURSOALUMNO_H

#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class CursoAlumno {
public:
	CursoAlumno();
	CursoAlumno(const CursoAlumno &orig);
	virtual ~CursoAlumno();
    void SetVez(int vez);
    int GetVez() const;
    void SetNota(int nota);
    int GetNota() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCodcur(string codcur);
    string GetCodcur() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
	virtual void leer(ifstream &arch);
	virtual void mostrar(ofstream &arch);
	virtual void actualiza(CursoAlumno *otro, int veces);
private:
	int codigo;
	string codcur;
	int ciclo;
	double creditos;
	int nota;
	int vez;
};

#endif /* CURSOALUMNO_H */
