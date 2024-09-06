/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Escala.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:39
 */

#include "Escala.h"

Escala::Escala() {
	codigo = 0;
	precio = 0.0;
}

Escala::Escala(const Escala &orig) {
}

Escala::~Escala() {
}

void Escala::SetCodigo(int codigo) {
	this->codigo = codigo;
}

int Escala::GetCodigo() const {
	return codigo;
}

void Escala::SetPrecio(double precio) {
	this->precio = precio;
}

double Escala::GetPrecio() const {
	return precio;
}

void Escala::leer(ifstream &arch) {
	arch >> codigo;
	if(arch.eof()) return;
	arch.get();
	arch >> precio;
}
