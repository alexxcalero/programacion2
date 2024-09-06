/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Libro.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:04
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <iomanip>
#include <cstring>
#include <fstream>
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
	virtual void leer(ifstream &arch);
	virtual void imprimir(ofstream &arch);
private:
	char *nombre;
	int paginas;
	double peso;
};

#endif /* LIBRO_H */
