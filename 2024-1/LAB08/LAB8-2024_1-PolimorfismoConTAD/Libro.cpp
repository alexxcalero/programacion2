/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Libro.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:02
 */

#include "Libro.h"

Libro::Libro() {
	nombre = nullptr;
	paginas = 0;
	peso = 0.0;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
	if(nombre != nullptr) delete nombre;
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
	if(this->nombre != nullptr) delete this->nombre;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
}

void Libro::GetNombre(char *nombre) const {
	if(this->nombre == nullptr) nombre[0] = 0;
	else strcpy(nombre, this->nombre);
}

void Libro::lee(ifstream &arch) {
	char nombre[100], c;
	arch.getline(nombre, 100, ',');
	SetNombre(nombre);
	arch >> paginas >> c >> peso >> c;
}

void Libro::imprime(ofstream &arch) {
	char titulo[100];
	GetNombre(titulo);
	arch << "Titulo: " << titulo << endl;
	arch << "Peso: " << peso << endl;
}
