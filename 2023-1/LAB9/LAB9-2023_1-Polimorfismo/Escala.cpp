/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Escala.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:17
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

void Escala::SetPrecio(double precio) {
	this->precio = precio;
}

double Escala::GetPrecio() const {
	return precio;
}

void Escala::SetCodigo(int codigo) {
	this->codigo = codigo;
}

int Escala::GetCodigo() const {
	return codigo;
}

void Escala::leer(ifstream &arch) {
	arch >> codigo;
	if(arch.eof()) return;
	arch.get();  // Leo la coma
	arch >> precio;
}

void Escala::mostrar() {
	cout << codigo << " - " << precio << endl;
}

void Escala::operator =(Escala &e) {
	codigo = e.codigo;
	precio = e.precio;
}
