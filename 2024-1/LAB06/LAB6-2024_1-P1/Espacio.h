/*
 * Proyecto : LAB6-2024_1-P1
 * Archivo  : Espacio.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de mayo de 2024, 09:23
 */

#ifndef ESPACIO_H
#define ESPACIO_H

#include <fstream>
using namespace std;

class Espacio {
public:
	Espacio();
	Espacio(const Espacio &orig);
	virtual ~Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
	void mostrar(ofstream &arch);
private:
	char contenido;
	int posx;
	int posy;
};

ofstream &operator <<(ofstream &arch, Espacio &espacio);

#endif /* ESPACIO_H */
