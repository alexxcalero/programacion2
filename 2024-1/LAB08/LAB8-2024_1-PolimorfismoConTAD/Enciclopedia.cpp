/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Enciclopedia.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:01
 */

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
	sku = 0;
	anho = 0;
	vigencia = 1;
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig) {
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetVigencia(int vigencia) {
	this->vigencia = vigencia;
}

int Enciclopedia::GetVigencia() const {
	return vigencia;
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

void Enciclopedia::lee(ifstream &arch) {
	Libro::lee(arch);
	char c;
	arch >> sku >> c >> anho;
	arch.get();
	vigencia = 1;
}

void Enciclopedia::actualiza() {
	if(anho <= 2020)
		vigencia = 0;
}

void Enciclopedia::imprime(ofstream &arch) {
	Libro::imprime(arch);
	arch << "SKU: " << left << setw(10) << sku << right << "Año: " << left << setw(10) << anho;
	arch << right << "Vigencia: " << vigencia << endl << endl;
}
