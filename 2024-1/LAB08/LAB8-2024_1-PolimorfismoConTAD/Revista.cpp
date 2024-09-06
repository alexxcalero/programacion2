/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Revista.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:07
 */

#include "Revista.h"

Revista::Revista() {
	ISSN = 0;
	anho = 0;
	numero = 0;
	vigencia = 1;
}

Revista::Revista(const Revista& orig) {
}

Revista::~Revista() {
}

void Revista::SetVigencia(int vigencia) {
	this->vigencia = vigencia;
}

int Revista::GetVigencia() const {
	return vigencia;
}

void Revista::SetNumero(int numero) {
	this->numero = numero;
}

int Revista::GetNumero() const {
	return numero;
}

void Revista::SetAnho(int anho) {
	this->anho = anho;
}

int Revista::GetAnho() const {
	return anho;
}

void Revista::SetISSN(int ISSN) {
	this->ISSN = ISSN;
}

int Revista::GetISSN() const {
	return ISSN;
}

void Revista::lee(ifstream &arch) {
	Libro::lee(arch);
	char c;
	arch >> ISSN >> c >> anho >> c >> numero;
	arch.get();
	vigencia = 1;
}

void Revista::actualiza() {
	if(anho <= 2020)
		vigencia = 0;
}

void Revista::imprime(ofstream &arch) {
	Libro::imprime(arch);
	arch << "ISSN: " << left << setw(10) << ISSN << right << "Año: " << left << setw(10) << anho;
	arch << right << "Vigencia: " << vigencia << endl << endl;
}
