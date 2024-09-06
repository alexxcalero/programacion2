/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Alumno.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:13
 */

#include "Alumno.h"

Alumno::Alumno() {
	codigo = 0;
	nombre = nullptr;
	escala = 0;
	creditos = 0.0;
	total = 0.0;
}

Alumno::Alumno(const Alumno &orig) {
}

Alumno::~Alumno() {
	if(nombre != nullptr) delete nombre;
}

void Alumno::SetTotal(double total) {
	this->total = total;
}

double Alumno::GetTotal() const {
	return total;
}

void Alumno::SetCreditos(double creditos) {
	this->creditos = creditos;
}

double Alumno::GetCreditos() const {
	return creditos;
}

void Alumno::SetEscala(int escala) {
	this->escala = escala;
}

int Alumno::GetEscala() const {
	return escala;
}

void Alumno::SetCodigo(int codigo) {
	this->codigo = codigo;
}

int Alumno::GetCodigo() const {
	return codigo;
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
	char nombre[100], c;
	arch >> codigo >> c;
	arch.getline(nombre, 100, ',');
	arch >> escala >> c >> creditos >> c;
	SetNombre(nombre);
	total = 0.0;
}

void Alumno::mostrar(ofstream &arch) {
	char nombre[100];
	GetNombre(nombre);
	arch << left << setw(15) << codigo << setw(45) << nombre;
	arch << right << setw(5) << escala << setw(15) << setprecision(2) << fixed << creditos;
}

void Alumno::actualizarTotal(double precioEscala) {}
