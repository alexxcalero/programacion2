/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : Alumno.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:41
 */

#include "Alumno.h"

Alumno::Alumno() {
	promedio = 0.0;
}

Alumno::Alumno(const Alumno &orig) {
	*this = orig;
}

Alumno::~Alumno() {
}

void Alumno::SetPromedio(double promedio) {
	this->promedio = promedio;
}

double Alumno::GetPromedio() const {
	return promedio;
}

void Alumno::SetNombre(string nombre) {
	this->nombre = nombre;
}

string Alumno::GetNombre() const {
	return nombre;
}

void Alumno::SetCodigo(int codigo) {
	this->codigo = codigo;
}

int Alumno::GetCodigo() const {
	return codigo;
}

void Alumno::leer(ifstream &arch) {
	arch >> codigo;
	if(arch.eof()) return;
	arch.get();  // Leo el salto de linea
	getline(arch, nombre, '\n');
	promedio = 0.0;
}

void Alumno::imprimir(ofstream &arch) {
	arch << left << setw(15) << "CODIGO: ";
	arch << codigo << endl;
	arch << setw(15) << "NOMBRE: ";
	arch << nombre << endl;
	arch << setw(15) << "PROMEDIO: ";
	arch << right << setw(8) << setprecision(2) << fixed << promedio << endl;
	arch << "NOTAS POR CURSO:\n";
}

void operator >>(ifstream &arch, Alumno &alumno) {
	alumno.leer(arch);
}
