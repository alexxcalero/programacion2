/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Libro.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:02
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
#include <cstring>
using namespace std;

class Libro {
public:
	Libro();
	Libro(const Libro& orig);
	virtual ~Libro();
	void SetPeso(double peso);
	double GetPeso() const;
	void SetPaginas(int paginas);
	int GetPaginas() const;
	void SetNombre(const char *nombre);
	void GetNombre(char *nombre) const;
	virtual void lee(ifstream &arch);
	virtual void actualiza() = 0;
	virtual void imprime(ofstream &arch);
private:
	char *nombre;
	int paginas;
	double peso;
};

#endif /* LIBRO_H */
