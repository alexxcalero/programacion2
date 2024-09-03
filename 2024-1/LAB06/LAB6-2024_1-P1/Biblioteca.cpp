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
