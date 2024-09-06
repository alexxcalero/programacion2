/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Libro.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:04
 */

#include "Libro.h"

Libro::Libro() {
	nombre = nullptr;
}

Libro::Libro(const Libro& orig) {
	nombre = nullptr;
	paginas = orig.paginas;
	peso = orig.peso;
	char nomb[100];
	orig.GetNombre(nomb);
	SetNombre(nomb);
}

Libro::~Libro() {
}

void Libro::SetPeso(double peso) {
	this->peso = peso;
}

double Libro::GetPeso() const {
	return peso;
}

void Libro::SetPaginas(int paginas) {
	this->paginas = paginas;
}

int Libro::GetPaginas() const {
	return paginas;
}

void Libro::SetNombre(const char *nombre) {
	if(this->nombre != nullptr) delete nombre;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
}

void Libro::GetNombre(char *nombre) const {
	if(this->nombre == nullptr) nombre[0] = 0;
	else strcpy(nombre, this->nombre);
}

void Libro::leer(ifstream &arch) {
	char nombre[100], c;
	arch.getline(nombre, 100, ',');
	SetNombre(nombre);
	arch >> paginas >> c >> peso >> c;
}

void Libro::imprimir(ofstream &arch) {
	arch << "Titulo: " << nombre << endl;
	arch << "Peso: " << setw(5) << setprecision(2) << fixed << peso << endl;
}
