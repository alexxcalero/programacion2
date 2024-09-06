/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : AlumnoNotas.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:53
 */

#include "AlumnoNotas.h"

AlumnoNotas::AlumnoNotas() {
}

AlumnoNotas::AlumnoNotas(const AlumnoNotas &orig) {
}

AlumnoNotas::~AlumnoNotas() {
}

void AlumnoNotas::agregarAlumno(Alumno &alumno) {
	this->alumno = alumno;
}

int AlumnoNotas::getCodigoDelAlumno() {
	return alumno.GetCodigo();
}

void AlumnoNotas::leerNotas(ifstream &arch, int ciclo) {
	while(1) {
		if(arch.get() == '\n') break;
		Nota nota;
		arch >> nota;
		nota.SetCiclo(ciclo);
		nota.SetVez(1);
		notas.push_back(nota);
	}
}

void AlumnoNotas::imprimir(ofstream &arch) {
	alumno.imprimir(arch);
	int cant = 1;
	for(Nota &nota : notas) {
		arch << "   " << setw(2) << setfill('0') << cant << ".- " << setfill(' ');
		nota.imprimir(arch);
		cant++;
	}
	arch << endl;
}

void AlumnoNotas::actualizarYtotalizar() {
	actualizar();
	totalizar();
}

void AlumnoNotas::actualizar() {
	vector<Nota>::iterator it1 = notas.end() - 1;
	vector<Nota>::iterator it2;
	int veces;
	while(it1 >= notas.begin() + 1) {
		veces = 1;
		it2 = it1 - 1;
		while(it2 >= notas.begin()) {
			if((*it1).GetCodigoDelCurso() == (*it2).GetCodigoDelCurso()) {
				vector<Nota>::iterator borrar = it2;
				it2--;
				notas.erase(borrar);
				it1 = notas.begin() + (it1 - notas.begin() - 1);
				veces++;
			} else it2--;
		}
		(*it1).SetVez(veces);
		it1--;
	}
}

void AlumnoNotas::totalizar() {
	double num = 0;
	double den = 0;
	for(Nota nota : notas) {
		num += (nota.GetCalificacion() * nota.GetCreditos());
		den += nota.GetCreditos();
	}
	alumno.SetPromedio(num / den);
}
