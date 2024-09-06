/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : Nota.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:46
 */

#include "Nota.h"

Nota::Nota() {
	vez = 1;
}

Nota::Nota(const Nota &orig) {
	*this = orig;
}

Nota::~Nota() {
}

void Nota::SetVez(int vez) {
	this->vez = vez;
}

int Nota::GetVez() const {
	return vez;
}

void Nota::SetCalificacion(int calificacion) {
	this->calificacion = calificacion;
}

int Nota::GetCalificacion() const {
	return calificacion;
}

void Nota::SetCreditos(double creditos) {
	this->creditos = creditos;
}

double Nota::GetCreditos() const {
	return creditos;
}

void Nota::SetCodigoDelCurso(string codigoDelCurso) {
	this->codigoDelCurso = codigoDelCurso;
}

string Nota::GetCodigoDelCurso() const {
	return codigoDelCurso;
}

void Nota::SetCiclo(int ciclo) {
	this->ciclo = ciclo;
}

int Nota::GetCiclo() const {
	return ciclo;
}

void Nota::leer(ifstream &arch) {
	char c;
	getline(arch, codigoDelCurso, ',');
	if(arch.eof()) return;
	arch >> creditos >> c >> calificacion;
	vez = 1;
}

void Nota::imprimir(ofstream &arch) {
	arch << left << setw(8) << ciclo << setw(8) << codigoDelCurso;
	arch << right << setw(8) << creditos << setw(8) << calificacion << setw(8) << vez << endl;
}

void operator >>(ifstream &arch, Nota &nota) {
	nota.leer(arch);
}
