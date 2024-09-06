/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Alumno.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:38
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Alumno {
public:
	Alumno();
	Alumno(const Alumno &orig);
	virtual ~Alumno();
	void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char *nombre);
    void GetNombre(char *nombre) const;
	void leer(ifstream &arch);
	void mostrar(ofstream &arch);
private:
	int codigo;
	char *nombre;
	int escala;
	double total;
};

#endif /* ALUMNO_H */
