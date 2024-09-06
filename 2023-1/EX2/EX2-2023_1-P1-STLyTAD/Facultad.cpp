/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : Facultad.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:56
 */

#include "Facultad.h"

Facultad::Facultad() {
}

Facultad::Facultad(const Facultad &orig) {
}

Facultad::~Facultad() {
}

void Facultad::leerAlumnosNotas() {
	leerAlumnos();
	leerNotas();
}

void Facultad::leerAlumnos() {
	ifstream arch("Alumnos-Preg01.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Alumnos-Preg01.csv\n";
		exit(1);
	}
	while(1) {
		Alumno alumno;
		arch >> alumno;
		if(arch.eof()) break;
		alumnosxNotas.insertar(alumno);
	}
}

void Facultad::leerNotas() {
	ifstream arch("Notas-Preg01.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Notas-Preg01.csv\n";
		exit(1);
	}
	int ciclo, codAlumno;
	while(1) {
		arch >> ciclo;
		if(arch.eof()) break;
		arch.get();  // Leo la coma
		arch >> codAlumno;
		if(alumnosxNotas.buscarAlumno(codAlumno))
			alumnosxNotas.leerNotasDelAlumno(arch, ciclo, codAlumno);
	}
}

void Facultad::imprimirAlumnosNotas(const char *nombArch) {
	ofstream arch(nombArch, ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	arch << setw(38) << "REPORTE DE NOTAS POR ALUMNO\n";
	imprimirLinea(arch, 50, '=');
	alumnosxNotas.imprimir(arch);
}

void Facultad::imprimirLinea(ofstream &arch, int cant, char c) {
	for(int i = 0; i < cant; i++)
		arch << c;
	arch << endl;
}

void Facultad::actualizarNotas() {
	alumnosxNotas.actualizarNotas();
}
