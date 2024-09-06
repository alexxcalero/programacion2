/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Categoria2.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:17
 */

#include "Categoria2.h"

Categoria2::Categoria2() {
}

Categoria2::Categoria2(const Categoria2 &orig) {
	prioridad = orig.prioridad;
	descuento = orig.descuento;
}

Categoria2::~Categoria2() {
}

void Categoria2::SetDescuento(double descuento) {
	this->descuento = descuento;
}

double Categoria2::GetDescuento() const {
	return descuento;
}

void Categoria2::SetPrioridad(int prioridad) {
	this->prioridad = prioridad;
}

int Categoria2::GetPrioridad() const {
	return prioridad;
}

void Categoria2::leer(ifstream &arch) {
	char c;
	arch >> prioridad >> c >> descuento >> c;
	Producto::leer(arch);
}

int Categoria2::obtenerPrioridad() {
	return GetPrioridad();
}

void Categoria2::imprimir(ofstream &arch) {
	Producto::imprimir(arch);
	arch << right << setw(9) << "2";
	if(prioridad != 0) arch << setw(10) << "SI";
	else arch << setw(10) << "NO";
	arch << right << setw(10) << descuento << endl;
}
