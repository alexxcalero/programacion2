/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : Novela.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:08
 */

#include "Novela.h"

Novela::Novela() {
	autor = nullptr;
}

Novela::Novela(const Novela& orig) {
	autor = nullptr;
	char aut[100];
	orig.GetAutor(aut);
	SetAutor(aut);
}

Novela::~Novela() {
}

void Novela::SetAutor(const char *autor) {
	if(this->autor != nullptr) delete autor;
	this->autor = new char[strlen(autor) + 1];
	strcpy(this->autor, autor);
}

void Novela::GetAutor(char *autor) const {
	if(this->autor == nullptr) autor[0] = 0;
	else strcpy(autor, this->autor);
}

void Novela::leer(ifstream &arch) {
	Libro::leer(arch);
	char autor[100];
	arch.getline(autor, 100, '\n');
	SetAutor(autor);
}

void Novela::imprimir(ofstream &arch) {
	Libro::imprimir(arch);
	arch << "Autor: " << autor << endl << endl;
}
