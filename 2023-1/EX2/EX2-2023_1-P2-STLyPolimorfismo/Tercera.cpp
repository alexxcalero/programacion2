/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : Tercera.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 16:09
 */

#include "Tercera.h"

Tercera::Tercera() {
}

Tercera::Tercera(const Tercera &orig) {
}

Tercera::~Tercera() {
}

void Tercera::SetPorcentaje(double porcentaje) {
	this->porcentaje = porcentaje;
}

double Tercera::GetPorcentaje() const {
	return porcentaje;
}

void Tercera::actualiza(CursoAlumno *otro, int veces) {
	CursoAlumno::actualiza(otro, veces);
	if(otro->GetCreditos() <= 3)
		porcentaje = 0.5;
	else
		porcentaje = 1.0;
}

void Tercera::mostrar(ofstream &arch) {
	CursoAlumno::mostrar(arch);
	arch << right << setw(8) << porcentaje << endl;
}
