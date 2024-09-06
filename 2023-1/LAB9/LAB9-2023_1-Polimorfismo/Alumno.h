/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Alumno.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:13
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
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
	void SetNombre(const char *nombre);
    void GetNombre(char *nombre) const;
	virtual void leer(ifstream &arch);
	virtual void mostrar(ofstream &arch);
	virtual void actualizarTotal(double precioEscala);
private:
	int codigo;
	char *nombre;
	int escala;
	double creditos;
	double total;
};

#endif /* ALUMNO_H */
