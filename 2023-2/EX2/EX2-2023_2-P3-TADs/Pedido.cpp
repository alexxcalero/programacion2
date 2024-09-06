/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : Pedido.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:27
 */

#include "Pedido.h"

Pedido::Pedido() {
	int cantidad = 0;
}

Pedido::Pedido(const Pedido &orig) {
	*this = orig;
}

Pedido::~Pedido() {
}

void Pedido::SetPeso(double peso) {
	this->peso = peso;
}

double Pedido::GetPeso() const {
	return peso;
}

void Pedido::SetCantidad(int cantidad) {
	this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
	return cantidad;
}

void Pedido::SetCodigo(string codigo) {
	this->codigo = codigo;
}

string Pedido::GetCodigo() const {
	return codigo;
}

void Pedido::mostrar(ofstream &arch) {
	arch << left << setw(10) << codigo << right << setw(8) << peso << setw(8) << cantidad << endl;
}

void operator >>(ifstream &arch, Pedido &pedido) {
	int cant;
	double peso;
	char cod[100], c;
	string codigo;
	arch.getline(cod, 100, ',');
	if(arch.eof()) return;
	arch >> cant >> c >> peso;
	arch.get();  // Leo el salto de linea
	codigo = cod;
	pedido.SetCodigo(codigo);
	pedido.SetCantidad(cant);
	pedido.SetPeso(peso);
}
