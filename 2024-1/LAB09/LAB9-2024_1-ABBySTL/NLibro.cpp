/*
 * Proyecto : LAB9-2024_1-ABBySTL
 * Archivo  : NLibro.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 21 de junio de 2024, 08:11
 */

#include "NLibro.h"

NLibro::NLibro() {
	plibro = nullptr;
}

NLibro::NLibro(const NLibro& orig) {
	plibro = orig.plibro;
}

NLibro::~NLibro() {
}

void NLibro::asignarMemoria(char tipo) {
	if(tipo == 'E') plibro = new Enciclopedia;
	else if(tipo == 'N') plibro = new Novela;
	else plibro = new Revista;
}

void NLibro::leer(ifstream &arch) {
	plibro->leer(arch);
}

double NLibro::getPeso() {
	return plibro->GetPeso();
}

void NLibro::imprimir(ofstream &arch) {
	plibro->imprimir(arch);
}

void operator >>(ifstream &arch, NLibro &libro) {
	libro.leer(arch);
}

void operator <<(ofstream &arch, NLibro &libro) {
	libro.imprimir(arch);
}
