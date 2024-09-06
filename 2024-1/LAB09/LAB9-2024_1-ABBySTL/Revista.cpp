/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Revista.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:10
 */

#include "Revista.h"

Revista::Revista() {
}

Revista::Revista(const Revista& orig) {
	issn = orig.issn;
	anho = orig.anho;
	numero = orig.numero;
}

Revista::~Revista() {
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

void Revista::SetIssn(int issn) {
	this->issn = issn;
}

int Revista::GetIssn() const {
	return issn;
}

void Revista::leer(ifstream &arch) {
	Libro::leer(arch);
	char c;
	arch >> issn >> c >> anho >> c >> numero;
	arch.get();
}

void Revista::imprimir(ofstream &arch) {
	Libro::imprimir(arch);
	arch << "ISSN: " << issn;
	arch << setw(8) << "Año: " << anho << endl << endl;
}
