/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Enciclopedia.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:07
 */

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig) {
	sku = orig.sku;
	anho = orig.anho;
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetAnho(int anho) {
	this->anho = anho;
}

int Enciclopedia::GetAnho() const {
	return anho;
}

void Enciclopedia::SetSku(int sku) {
	this->sku = sku;
}

int Enciclopedia::GetSku() const {
	return sku;
}

void Enciclopedia::leer(ifstream &arch) {
	Libro::leer(arch);
	char c;
	arch >> sku >> c >> anho;
	arch.get();
}

void Enciclopedia::imprimir(ofstream &arch) {
	Libro::imprimir(arch);
	arch << "SKU: " << sku;
	arch << setw(8) << "Año: " << anho << endl << endl;
}
