/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Lista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:09
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include "Libro.h"

class Lista {
public:
	Lista();
	Lista(const Lista& orig);
	virtual ~Lista();
	void SetPeso(double peso);
	double GetPeso() const;
	void insertarLibro(Libro *libro);
	void actualizarVigencia();
	void imprimirLibros(ofstream &arch);
private:
	double peso;
	Nodo *ini;
};

#endif /* LISTA_H */
