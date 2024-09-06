/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : CursoAlumno.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 15:54
 */

#include "CursoAlumno.h"

CursoAlumno::CursoAlumno() {
}

CursoAlumno::CursoAlumno(const CursoAlumno &orig) {
}

CursoAlumno::~CursoAlumno() {
}

void CursoAlumno::SetVez(int vez) {
	this->vez = vez;
}

int CursoAlumno::GetVez() const {
	return vez;
}

void CursoAlumno::SetNota(int nota) {
	this->nota = nota;
}

int CursoAlumno::GetNota() const {
	return nota;
}

void CursoAlumno::SetCreditos(double creditos) {
	this->creditos = creditos;
}

double CursoAlumno::GetCreditos() const {
	return creditos;
}

void CursoAlumno::SetCiclo(int ciclo) {
	this->ciclo = ciclo;
}

int CursoAlumno::GetCiclo() const {
	return ciclo;
}

void CursoAlumno::SetCodcur(string codcur) {
	this->codcur = codcur;
}

string CursoAlumno::GetCodcur() const {
	return codcur;
}

void CursoAlumno::SetCodigo(int codigo) {
	this->codigo = codigo;
}

int CursoAlumno::GetCodigo() const {
	return codigo;
}

void CursoAlumno::leer(ifstream &arch) {
	char c;
	arch >> codigo;
	if(arch.eof()) return;
	arch.get();
	getline(arch, codcur, ',');
	arch >> creditos >> c >> ciclo >> c >> nota;
	arch.get();
	vez = 1;
}

void CursoAlumno::actualiza(CursoAlumno *otro, int veces) {
	codigo = otro->codigo;
	codcur = otro->codcur;
	ciclo = otro->ciclo;
	creditos = otro->creditos;
	nota = otro->nota;
	vez = veces;
}

void CursoAlumno::mostrar(ofstream &arch) {
	arch << left << setw(15) << codigo << setw(10) << codcur;
	arch << right << setw(6) << creditos << setw(12) << ciclo;
	arch << setw(8) << nota << setw(8) << vez;
}
