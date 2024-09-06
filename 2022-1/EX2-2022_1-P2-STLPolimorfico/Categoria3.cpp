/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Categoria3.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:18
 */

#include "Categoria3.h"

Categoria3::Categoria3() {
}

Categoria3::Categoria3(const Categoria3 &orig) {
	prioridad = orig.prioridad;
	descuento = orig.descuento;
}

Categoria3::~Categoria3() {
}

void Categoria3::SetDescuento(double descuento) {
	this->descuento = descuento;
}

double Categoria3::GetDescuento() const {
	return descuento;
}

void Categoria3::SetPrioridad(int prioridad) {
	this->prioridad = prioridad;
}

int Categoria3::GetPrioridad() const {
	return prioridad;
}

void Categoria3::leer(ifstream &arch) {
	char c;
	arch >> prioridad >> c >> descuento >> c;
	Producto::leer(arch);
}

int Categoria3::obtenerPrioridad() {
	return GetPrioridad();
}

void Categoria3::imprimir(ofstream &arch) {
	Producto::imprimir(arch);
	arch << right << setw(9) << "3";
	if(prioridad != 0) arch << setw(10) << "SI";
	else arch << setw(10) << "NO";
	arch << right << setw(10) << descuento << endl;
}
