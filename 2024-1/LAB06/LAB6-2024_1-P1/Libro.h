/*
 * Proyecto : LAB6-2024_1-P1
 * Archivo  : Libro.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de mayo de 2024, 09:18
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Libro {
public:
	Libro();
	Libro(const Libro &orig);
	virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char *nombre);
    void GetNombre(char* nombre) const;
    void SetCodigo(const char *codigo);
    void GetCodigo(char* codigo) const;
	void leer(ifstream &arch);
	void mostrar(ofstream &arch);
private:
	char *codigo;
	char *nombre;
	int ancho;
	int alto;
	bool colocado;
};

ifstream &operator >>(ifstream &arch, Libro &libro);
ofstream &operator <<(ofstream &arch, Libro &libro);

#endif /* LIBRO_H */
