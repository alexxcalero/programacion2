/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : Segunda.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 16:08
 */

#include "Segunda.h"

Segunda::Segunda() {
}

Segunda::Segunda(const Segunda &orig) {
}

Segunda::~Segunda() {
}

void Segunda::SetCreditos(double creditos) {
	this->creditos = creditos;
}

double Segunda::GetCreditos() const {
	return creditos;
}

void Segunda::actualiza(CursoAlumno *otro, int veces) {
	CursoAlumno::actualiza(otro, veces);
	if(otro->GetCreditos() <= 3)
		creditos = 1;
	else
		creditos = 1.5;
}

void Segunda::mostrar(ofstream &arch) {
	CursoAlumno::mostrar(arch);
	arch << right << setw(8) << creditos << endl;
}
