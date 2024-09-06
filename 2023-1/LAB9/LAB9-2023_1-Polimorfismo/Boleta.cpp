/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Boleta.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:24
 */

#include "Boleta.h"

Boleta::Boleta() {
	pboleta = nullptr;
}

Boleta::Boleta(const Boleta &orig) {
}

Boleta::~Boleta() {
	if(pboleta != nullptr) delete pboleta;
}

void Boleta::asignarAlumno(ifstream &arch, char categoria) {
	asignarCategoria(categoria);
	pboleta->leer(arch);
}

void Boleta::asignarCategoria(char categoria) {
	if(categoria == 'P') pboleta = new Presencial;
	else if(categoria == 'S') pboleta = new Semipresencial;
	else pboleta = new Virtual;
}

void Boleta::imprimir(ofstream &arch) {
	pboleta->mostrar(arch);
}

int Boleta::GetEscala() {
	return pboleta->GetEscala();
}

void Boleta::calcularTotal(double precioEscala) {
	pboleta->actualizarTotal(precioEscala);
}
