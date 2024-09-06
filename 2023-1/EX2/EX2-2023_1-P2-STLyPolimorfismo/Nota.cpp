/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : Nota.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 16:10
 */

#include "Nota.h"

Nota::Nota() {
	pnota = nullptr;
}

Nota::Nota(const Nota &orig) {
	*this = orig;
}

Nota::~Nota() {
}

void Nota::leer(ifstream &arch) {
	pnota = new Primera;
	pnota->leer(arch);
}

void Nota::mostrar(ofstream &arch) {
	pnota->mostrar(arch);
}

bool Nota::operator <(Nota &nota) {
	if(pnota->GetCodigo() < nota.pnota->GetCodigo())
		return true;
	else if(pnota->GetCodigo() > nota.pnota->GetCodigo())
		return false;
	else {
		if(pnota->GetCodcur() < nota.pnota->GetCodcur()) {
			return true;
		} else if(pnota->GetCodcur() > nota.pnota->GetCodcur())
			return false;
		else {
			if(pnota->GetCiclo() < nota.pnota->GetCiclo())
				return true;
			else
				return false;
		}
	}
}

int Nota::GetCodigo() {
	return pnota->GetCodigo();
}

string Nota::GetCodcur() {
	return pnota->GetCodcur();
}

void Nota::actualiza(int veces) {
	if(veces == 1) {
		pnota->SetVez(veces);
		return;
	}

	CursoAlumno *nuevo;
	if(veces == 2)
		nuevo = new Segunda;
	else
		nuevo = new Tercera;

	nuevo->actualiza(pnota, veces);
	delete pnota;
	pnota = nuevo;
}

void operator >>(ifstream &arch, Nota &nota) {
	nota.leer(arch);
}
