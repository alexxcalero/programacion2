/*
 * Proyecto : LAB6-2024_1-P1
 * Archivo  : Biblioteca.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de mayo de 2024, 09:29
 */

#include "Biblioteca.h"

Biblioteca::Biblioteca() {
	cantEstantes = 0;
	cantLibros = 0;
}

Biblioteca::Biblioteca(const Biblioteca &orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::SetCantLibros(int cantLibros) {
	this->cantLibros = cantLibros;
}

int Biblioteca::GetCantLibros() const {
	return cantLibros;
}

void Biblioteca::SetCantEstantes(int cantEstantes) {
	this->cantEstantes = cantEstantes;
}

int Biblioteca::GetCantEstantes() const {
	return cantEstantes;
}

void Biblioteca::cargarLibros() {
	ifstream archLibros("Libros.csv", ios::in);
	if(!archLibros.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Libros.csv\n";
		exit(1);
	}
	cantLibros = 0;
	while(1) {
		archLibros >> libros[cantLibros];
		if(archLibros.eof()) break;
		cantLibros++;
	}
}

void Biblioteca::cargarEstantes() {
	ifstream archEstantes("Estantes.csv", ios::in);
	if(!archEstantes.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Estantes.csv\n";
		exit(1);
	}
	cantEstantes = 0;
	while(1) {
		archEstantes >> estantes[cantEstantes];
		if(archEstantes.eof()) break;
		cantEstantes++;
	}
}

void Biblioteca::posicionarLibros() {
//	for(int i = 0; i < cantLibros; i++) {
//		for(int j = 0; j < cantEstantes; j++) {
//			if(libros[i].IsColocado() == false) {
//				estantes[j] += libros[i];
//			}
//		}
//	}
	for(int i = 0; i < cantEstantes; i++) {
		for(int j = 0; j < cantLibros; j++) {
			if(libros[j].IsColocado() == false)
				estantes[i] += libros[j];
		}
	}
}

void Biblioteca::mostrarDatos() {
	ofstream arch("ReporteDeBiblioteca.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDeEstantes.txt\n";
		exit(1);
	}
	imprimirEncabezados(arch);
	arch << "Cantidad de Estantes: " << cantEstantes << endl;
	imprimirLinea(arch, '-');
	for(int i = 0; i < cantEstantes; i++) {
		arch << estantes[i];
		imprimirLinea(arch, '-');
	}
	imprimirLinea(arch, '=');
	arch << "Informacion de todos los libros:\n";
	arch << "Cantidad de los Libros Total: " << cantLibros << endl;
	imprimirLinea(arch, '-');
	for(int i = 0; i < cantLibros; i++)
		arch << libros[i];
	imprimirLinea(arch, '=');
}

void Biblioteca::imprimirEncabezados(ofstream &arch) {
	imprimirLinea(arch, '=');
	arch << right << setw(48) << "Informacion del posicionamiento de Libros" << endl;
	arch << right << setw(43) << "en los estantes de la Biblioteca" << endl;
	imprimirLinea(arch, '=');
}

void Biblioteca::imprimirLinea(ofstream &arch, char c) {
	for(int i = 0; i < MAX_LIN; i++)
		arch << c;
	arch << endl;
}
