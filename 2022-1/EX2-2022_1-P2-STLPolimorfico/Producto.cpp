/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Producto.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:12
 */

#include "Producto.h"

Producto::Producto() {
	nombre = nullptr;
}

Producto::Producto(const Producto &orig) {
	nombre = nullptr;
	codprod = orig.codprod;
	char nomb[100];
	orig.GetNombre(nomb);
	SetNombre(nomb);
	stock = orig.stock;
}

Producto::~Producto() {
}

void Producto::SetStock(int stock) {
	this->stock = stock;
}

int Producto::GetStock() const {
	return stock;
}

void Producto::SetNombre(const char *nombre) {
	if(this->nombre != nullptr) delete this->nombre;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
}

void Producto::GetNombre(char *nombre) const {
	if(this->nombre == nullptr) nombre[0] = 0;
	else strcpy(nombre, this->nombre);
}

void Producto::SetCodprod(int codprod) {
	this->codprod = codprod;
}

int Producto::GetCodprod() const {
	return codprod;
}

void Producto::leer(ifstream &arch) {
	char nombre[100], c;
	arch >> codprod >> c;
	arch.getline(nombre, 100, ',');
	SetNombre(nombre);
	arch >> stock;
}

void Producto::imprimir(ofstream &arch) {
	arch << left << setw(10) << codprod << setw(45) << nombre;
	arch << right << setw(5) << stock;
}
