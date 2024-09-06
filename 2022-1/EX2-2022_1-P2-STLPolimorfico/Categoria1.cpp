/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Categoria1.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:16
 */

#include "Categoria1.h"

Categoria1::Categoria1() {
}

Categoria1::Categoria1(const Categoria1 &orig) {
	prioridad = orig.prioridad;
	minimo = orig.minimo;
}

Categoria1::~Categoria1() {
}

void Categoria1::SetMinimo(int minimo) {
	this->minimo = minimo;
}

int Categoria1::GetMinimo() const {
	return minimo;
}

void Categoria1::SetPrioridad(int prioridad) {
	this->prioridad = prioridad;
}

int Categoria1::GetPrioridad() const {
	return prioridad;
}

void Categoria1::leer(ifstream &arch) {
	char c;
	arch >> prioridad >> c >> minimo >> c;
	Producto::leer(arch);
}

int Categoria1::obtenerPrioridad() {
	return GetPrioridad();
}

void Categoria1::imprimir(ofstream &arch) {
	Producto::imprimir(arch);
	arch << right << setw(9) << "1";
	if(prioridad != 0) arch << setw(10) << "SI";
	else arch << setw(10) << "NO";
	arch << right << setw(10) << minimo << endl;
}
