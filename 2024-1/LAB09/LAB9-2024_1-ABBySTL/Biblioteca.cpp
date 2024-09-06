/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Biblioteca.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:17
 */

#include "Biblioteca.h"

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::carga() {
	ifstream archEstantes("Estantes3.csv", ios::in);
	if(!archEstantes.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Estantes3.csv\n";
		exit(1);
	}
	ifstream archLibros("Libros3.csv", ios::in);
	if(!archLibros.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Libros31.csv\n";
		exit(1);
	}

	while(1) {
		NEstante *estante = new NEstante;
		archEstantes >> estante;
		estante->insertarLibros(archLibros);
		AEstante.insertar(estante);
		if(archEstantes.eof()) break;
	}
}

void Biblioteca::muestra() {
	AEstante.mostrarEnOrden();
}

void Biblioteca::prueba(double peso) {
	AEstante.asignarNuevoLibro(peso);
}
