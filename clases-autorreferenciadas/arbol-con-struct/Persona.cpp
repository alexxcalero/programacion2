/*
 * Proyecto : arbol-con-struct
 * Archivo  : Persona.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 01:46
 */

#include <iomanip>
#include <fstream>
#include <cstring>
#include "Persona.h"
using namespace std;

Persona::Persona() {
	dni = 0;
	nombre = nullptr;
	sueldo = 0.0;
}

Persona::Persona(const Persona &orig) {
	nombre = nullptr;
	*this = orig;
}

Persona::~Persona() {
	if(nombre != nullptr) delete nombre;
}

void Persona::SetSueldo(double sueldo) {
	this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
	return sueldo;
}

void Persona::SetNombre(const char *nombre) {
	if(this->nombre != nullptr) delete this->nombre;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
}

void Persona::GetNombre(char *nombre) const {
	if(this->nombre == nullptr) nombre[0] = 0;
	else strcpy(nombre, this->nombre);
}

void Persona::SetDni(int dni) {
	this->dni = dni;
}

int Persona::GetDni() const {
	return dni;
}

void Persona::operator =(const Persona &p) {
	char nombre[100];
	p.GetNombre(nombre);
	dni = p.dni;
	SetNombre(nombre);
	sueldo = p.sueldo;
}

bool Persona::operator >(const Persona &p) {
	return dni > p.dni;  // Ordeno por DNI
	// return strcmp(nombre, p.nombre) > 0;  // Ordeno por nombre
}

bool Persona::operator ==(int dni) {
	return this->dni == dni;
}

bool Persona::operator >(int dni) {
	return this->dni > dni;
}

void operator >>(ifstream &arch, Persona &p) {
	int dni;
	char nombre[100];
	double sueldo;
	arch >> dni;
	if(arch.eof()) return;
	arch.get();
	arch.getline(nombre, 100, ',');
	arch >> sueldo;
	p.SetDni(dni);
	p.SetNombre(nombre);
	p.SetSueldo(sueldo);
}

void operator <<(ofstream &arch, const Persona &p) {
	char nombre[100];
	p.GetNombre(nombre);
	arch << left << setw(12) << p.GetDni() << left << setw(40) << nombre;
	arch << right << setw(8) << setprecision(2) << fixed << p.GetSueldo() << endl;
}
