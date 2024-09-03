/*
 * Proyecto : LAB6-2024_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de mayo de 2024, 09:18
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Libro.h"
#include "Estante.h"
using namespace std;

int main(int argc, char** argv) {
	ifstream archLibros("Libros.csv", ios::in);
	if(!archLibros.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Libros.csv\n";
		exit(1);
	}
	ofstream repLibros("ReporteDeLibros.txt", ios::out);
	if(!repLibros.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDeLibros.txt\n";
		exit(1);
	}
	
//	Libro librito;
//	archLibros >> librito;
//	repLibros << librito;
	
	Libro libros[10];
	int cantLibros = 0;
	while(1) {
		archLibros >> libros[cantLibros];
		if(archLibros.eof()) break;
		cantLibros++;
	}
	for(int i = 0; i < cantLibros; i++)
		repLibros << libros[i];
	
	
	ifstream archEstantes("Estantes.csv", ios::in);
	if(!archEstantes.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Estantes.csv\n";
		exit(1);
	}
	ofstream repEstantes("ReporteDeEstantes.txt", ios::out);
	if(!repEstantes.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDeEstantes.txt\n";
		exit(1);
	}
	
//	Estante estantito;
//	archEstantes >> estantito;
//	repEstantes << estantito;
	
	Estante estantes[10];
	int cantEstantes = 0;
	while(1) {
		archEstantes >> estantes[cantEstantes];
		if(archEstantes.eof()) break;
		cantEstantes++;
	}
	
	estantes[0] += libros[0];
	estantes[0] += libros[1];
	estantes[0] += libros[2];
	
	repEstantes << estantes[0];
	
	return EXIT_SUCCESS;
}
