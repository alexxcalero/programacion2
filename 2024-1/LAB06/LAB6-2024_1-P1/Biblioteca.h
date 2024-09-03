/*
 * Proyecto : LAB6-2024_1-P1
 * Archivo  : Biblioteca.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de mayo de 2024, 09:29
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include "Estante.h"

class Biblioteca {
public:
	Biblioteca();
	Biblioteca(const Biblioteca &orig);
	virtual ~Biblioteca();
    void SetCantLibros(int cantLibros);
    int GetCantLibros() const;
    void SetCantEstantes(int cantEstantes);
    int GetCantEstantes() const;
private:
	Estante estantes[10];
	int cantEstantes;
	Libro libros[10];
	int cantLibros;
};

#endif /* BIBLIOTECA_H */
