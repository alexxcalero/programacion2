/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : Primera.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 16:05
 */

#include "Primera.h"

Primera::Primera() {
}

Primera::Primera(const Primera &orig) {
}

Primera::~Primera() {
}

void Primera::SetCodacceso(string codacceso) {
	this->codacceso = codacceso;
}

string Primera::GetCodacceso() const {
	return codacceso;
}

void Primera::leer(ifstream &arch) {
	CursoAlumno::leer(arch);
	codacceso += to_string(GetCodigo());
	codacceso += GetCodcur();
//	codacceso.append(to_string(GetCodigo()));
//	codacceso.append(GetCodcur());
}

void Primera::mostrar(ofstream &arch) {
	CursoAlumno::mostrar(arch);
	arch << "   " << left << setw(20) << codacceso << endl;
}
