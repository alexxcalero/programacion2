/*
 * Proyecto : LAB6-2024_1-P1
 * Archivo  : Libro.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de mayo de 2024, 09:18
 */

#include "Libro.h"

Libro::Libro() {
	nombre = nullptr;
	codigo = nullptr;
	ancho = 0;
	alto = 0;
}

Libro::Libro(const Libro &orig) {
}

Libro::~Libro() {
	if(nombre != nullptr) delete nombre;
	if(codigo != nullptr) delete codigo;
}

void Libro::SetColocado(bool colocado) {
	this->colocado = colocado;
}

bool Libro::IsColocado() const {
	return colocado;
}

void Libro::SetAlto(int alto) {
	this->alto = alto;
}

int Libro::GetAlto() const {
	return alto;
}

void Libro::SetAncho(int ancho) {
	this->ancho = ancho;
}

int Libro::GetAncho() const {
	return ancho;
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

void Libro::SetCodigo(const char *codigo) {
	if(this->codigo != nullptr) delete this->codigo;
	this->codigo = new char[strlen(codigo) + 1];
	strcpy(this->codigo, codigo);
}

void Libro::GetCodigo(char *codigo) const {
	if(this->codigo == nullptr) codigo[0] = 0;
	else strcpy(codigo, this->codigo);
}

void Libro::leer(ifstream &arch) {
	char cadena[100];
	arch.getline(cadena, 100, ',');
	if(arch.eof()) return;
	SetCodigo(cadena);
	arch.getline(cadena, 100, ',');
	SetNombre(cadena);
	arch >> ancho;
	arch.get();
	arch >> alto;
	arch.get();
	colocado = false;
}

void Libro::mostrar(ofstream &arch) {
	char codigo[100], nombre[100];
	GetCodigo(codigo); GetNombre(nombre);
	arch << left << setw(10) << codigo << setw(25) << nombre;
	arch << right << setw(4) << ancho << setw(6) << " " << alto << endl;
}

ifstream &operator >>(ifstream &arch, Libro &libro) {
	libro.leer(arch);
}

ofstream &operator <<(ofstream &arch, Libro &libro) {
	libro.mostrar(arch);
}
