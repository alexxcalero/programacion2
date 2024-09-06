/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Novela.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:04
 */

#include "Novela.h"

Novela::Novela() {
	autor = nullptr;
}

Novela::Novela(const Novela& orig) {
}

Novela::~Novela() {
	if(autor != nullptr) delete autor;
}

void Novela::SetAutor(const char *autor) {
	if(this->autor != nullptr) delete this->autor;
	this->autor = new char[strlen(autor) + 1];
	strcpy(this->autor, autor);
}

void Novela::GetAutor(char *autor) const {
	if(this->autor == nullptr) autor[0] = 0;
	else strcpy(autor, this->autor);
}

void Novela::lee(ifstream &arch) {
	Libro::lee(arch);
	char autor[100];
	arch.getline(autor, 100, '\n');
	SetAutor(autor);
}

// No hace nada esta funcion xq novela no tiene atributo vigencia
void Novela::actualiza() {
}

void Novela::imprime(ofstream &arch) {
	Libro::imprime(arch);
	char autor[100];
	GetAutor(autor);
	arch << "Autor: " << autor << endl << endl;
}
