/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Alumno.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:38
 */

#include "Alumno.h"

Alumno::Alumno() {
	codigo = 0;
	nombre = nullptr;
	escala = 0;
	total = 0.0;
}

Alumno::Alumno(const Alumno &orig) {
}

Alumno::~Alumno() {
	if(nombre != nullptr) delete nombre;
}

void Alumno::SetCodigo(int codigo) {
	this->codigo = codigo;
}

int Alumno::GetCodigo() const {
	return codigo;
}

void Alumno::SetTotal(double total) {
	this->total = total;
}

double Alumno::GetTotal() const {
	return total;
}

void Alumno::SetEscala(int escala) {
	this->escala = escala;
}

int Alumno::GetEscala() const {
	return escala;
}

void Alumno::SetNombre(const char *nombre) {
	if(this->nombre != nullptr) delete this->nombre;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
}

void Alumno::GetNombre(char *nombre) const {
	if(this->nombre == nullptr) nombre[0] = 0;
	else strcpy(nombre, this->nombre);
}

void Alumno::leer(ifstream &arch) {
	char cad[100];
	arch >> codigo;
	arch.get();
	arch.getline(cad, 100, ',');
	SetNombre(cad);
	arch >> escala;
	arch.get();
	total = 0.0;
}

void Alumno::mostrar(ofstream &arch) {
	char nombre[100];
	GetNombre(nombre);
	arch << left << setw(15) << GetCodigo() << setw(40) << nombre;
	arch << right << setw(10) << GetEscala();
}
