/*
 * Proyecto : LAB6-2024_1-P1
 * Archivo  : Estante.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de mayo de 2024, 09:24
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include <iomanip>
#include <fstream>
#include <cstring>
#include "Libro.h"
#include "Espacio.h"
#define MAX_LIN 50
using namespace std;

class Estante {
public:
	Estante();
	Estante(const Estante &orig);
	virtual ~Estante();
    void SetCantLibros(int cantLibros);
    int GetCantLibros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char *codigo);
    void GetCodigo(char *codigo) const;
	void leer(ifstream &arch);
	void mostrar(ofstream &arch);
	void imprimirEncabezados(ofstream &arch);
	void imprimirLinea(ofstream &arch, char c);
	bool operator +=(Libro &libro);
	int calcularAnchuraSobrante();
private:
	char *codigo;
	int anchura;
	int altura;
	Libro libros[10];
	Espacio *espacios;
	int cantLibros;
};

ifstream &operator >>(ifstream &arch, Estante &estante);
ofstream &operator <<(ofstream &arch, Estante &estante);

#endif /* ESTANTE_H */
