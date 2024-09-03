/*
 * Proyecto : LAB6-2024_1-P1
 * Archivo  : Espacio.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de mayo de 2024, 09:23
 */

#include "Espacio.h"

Espacio::Espacio() {
	contenido = ' ';
	posx = 0;
	posy = 0;
}

Espacio::Espacio(const Espacio &orig) {
}

Espacio::~Espacio() {
}

void Espacio::SetPosy(int posy) {
	this->posy = posy;
}

int Espacio::GetPosy() const {
	return posy;
}

void Espacio::SetPosx(int posx) {
	this->posx = posx;
}

int Espacio::GetPosx() const {
	return posx;
}

void Espacio::SetContenido(char contenido) {
	this->contenido = contenido;
}

char Espacio::GetContenido() const {
	return contenido;
}

void Espacio::mostrar(ofstream &arch) {
	arch << '[' << contenido << ']';
}

ofstream &operator <<(ofstream &arch, Espacio &espacio) {
	espacio.mostrar(arch);
}
