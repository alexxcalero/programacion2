/*
 * Proyecto : EX2-2023_1-P2-STLyPolimorfismo
 * Archivo  : Registro.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 16:10
 */

#include "Registro.h"

Registro::Registro() {
}

Registro::Registro(const Registro &orig) {
}

Registro::~Registro() {
}

void Registro::carga() {
	ifstream arch("registronotas.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo registronotas.csv\n";
		exit(1);
	}
	while(1) {
		Nota nota;
		arch >> nota;
		if(arch.eof()) break;
		vregistro.push_back(nota);
	}
}

void Registro::procesa() {
	// 1.- Ordeno el vector
	sort(vregistro.begin(),vregistro.end());
	// 2.- Verifico veces que se ha llevado el curso
	vector<Nota>::iterator it1 = vregistro.end() - 1;
	vector<Nota>::iterator it2;
	int veces;
	while(it1 >= vregistro.begin() + 1) {
		veces = 1;
		it2 = it1 - 1;
		while((*it2).GetCodigo() == (*it1).GetCodigo()) {
			if((*it1).GetCodcur() == (*it2).GetCodcur()) {
				vector<Nota>::iterator borrar = it2;
				it2--;
				vregistro.erase(borrar);
				it1 = vregistro.begin() + (it1 - vregistro.begin() - 1);
				veces++;
			} else it2--;
			if(it2 < vregistro.begin()) break;  // Corto si me sali del rango
		}
		(*it1).actualiza(veces);
		it1--;
	}
}

void Registro::muestra() {
	ofstream arch("RegistroDeNotas.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo RegistroDeNotas.txt\n";
		exit(1);
	}
	for(Nota nota : vregistro)
		nota.mostrar(arch);
}
