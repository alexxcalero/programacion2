/*
 * Proyecto : memoria-incremental-erasmo-1archivo
 * Archivo  : funciones.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de abril de 2024, 22:54
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.h"
using namespace std;

void cargarDatosAlumnos(int *&codigos, char **&nombres, char ***&cursos, const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	codigos = nullptr;
	nombres = nullptr;
	cursos = nullptr;
	int cod, numDat = 0, cap = 0;
	while(true) {
		arch >> cod;
		if(arch.eof()) break;
		arch.get();  // Leo la coma
		if(numDat == cap) incrementarMemoria(codigos, nombres, cursos, numDat, cap);
		codigos[numDat - 1] = cod;
		nombres[numDat - 1] = leerCadena(arch, 100, ',');
		cursos[numDat - 1] = leerCursos(arch);
		numDat++;
	}
}

void incrementarMemoria(int *&codigos, char **&nombres, char ***&cursos, int &numDat, int &cap) {
	int *auxCod;
	char **auxNomb, ***auxCur;
	cap += INCREMENTO;
	if(codigos == nullptr) {
		codigos = new int[cap]{};
		nombres = new char*[cap]{};
		cursos = new char**[cap]{};
		numDat = 1;
	} else {
		auxCod = new int[cap]{};
		auxNomb = new char*[cap]{};
		auxCur = new char**[cap]{};
		for(int i = 0; i < numDat; i++) {
			auxCod[i] = codigos[i];
			auxNomb[i] = nombres[i];
			auxCur[i] = cursos[i];
		}
		delete codigos; delete nombres; delete cursos;
		codigos = auxCod; nombres = auxNomb; cursos = auxCur;
	}
}

char *leerCadena(ifstream &arch, int size, char delim) {
	char cadena[size], *cad;
	arch.getline(cadena, size, delim);
	cad = new char[strlen(cadena) + 1];
	strcpy(cad, cadena);
	return cad;
}

char **leerCursos(ifstream &arch) {
	char **cursos = nullptr;
	int numCur = 0, capCur = 0;
	while(true) {
		char *cur = new char[7];
		arch.get(cur, 7);
		if(numCur == capCur) incrementarMemoria(cursos, numCur, capCur);
		cursos[numCur - 1] = cur;
		numCur++;
		if(arch.get() == '\n') break;
	}
	return cursos;
}

void incrementarMemoria(char **&cursos, int &numCur, int &capCur) {
	char **auxCur;
	capCur += INCREMENTO;
	if(cursos == nullptr) {
		cursos = new char*[capCur]{};
		numCur = 1;
	} else {
		auxCur = new char*[capCur]{};
		for(int i = 0; i < numCur; i++)
			auxCur[i] = cursos[i];
		delete cursos;
		cursos = auxCur;
	}
}

void reporteDeAlumnos(int *codigos, char **nombres, char ***cursos, const char *nombArch) {
	ofstream arch(nombArch, ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	for(int i = 0; codigos[i]; i++) {
		arch << left << setw(10) << codigos[i] << setw(25) << nombres[i] << endl;
		arch << "Cursos llevados:\n";
		reporteDeCursos(arch, cursos[i]);
	}
}

void reporteDeCursos(ofstream &arch, char **cursos) {
	for(int i = 0; cursos[i]; i++)
		arch << right << setw(22) << cursos[i] << endl;
}
