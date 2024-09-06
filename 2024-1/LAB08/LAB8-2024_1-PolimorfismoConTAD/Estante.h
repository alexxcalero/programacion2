/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Estante.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:10
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include <fstream>
#include "Libro.h"
#include "Lista.h"
using namespace std;

class Estante {
public:
	Estante();
	Estante(const Estante& orig);
	virtual ~Estante();
	void SetCapacidad(double capacidad);
	double GetCapacidad() const;
	void SetId(int id);
	int GetId() const;
	void SetClase(char clase);
	char GetClase() const;
	bool verificarEspacio(Libro *libro);
	void insertarLibro(Libro *libro);
	void actualizarVigencia();
	void imprimirDatosDelEstante(ofstream &arch);
	void verificarTipoEstante(ofstream &arch);
	void imprimirLibros(ofstream &arch);
	void imprimirLinea(ofstream &arch, int cant, char c);
private:
	char clase;
	int id;
	double capacidad;
	Lista Llibros;
};

#endif /* ESTANTE_H */
