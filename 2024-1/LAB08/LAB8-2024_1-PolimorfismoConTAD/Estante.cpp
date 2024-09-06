/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Estante.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:10
 */

#include "Estante.h"

Estante::Estante() {
	clase = ' ';  // Para poder saber cuando es el final del arreglo de Estantes
	id = -1;
	capacidad = 0.0;
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
}

void Estante::SetCapacidad(double capacidad) {
	this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
	return capacidad;
}

void Estante::SetId(int id) {
	this->id = id;
}

int Estante::GetId() const {
	return id;
}

void Estante::SetClase(char clase) {
	this->clase = clase;
}

char Estante::GetClase() const {
	return clase;
}

bool Estante::verificarEspacio(Libro *libro) {
	if(Llibros.GetPeso() + libro->GetPeso() <= capacidad)
		return true;
	else
		return false;
}

void Estante::insertarLibro(Libro *libro) {
	Llibros.insertarLibro(libro);
}

void Estante::actualizarVigencia() {
	Llibros.actualizarVigencia();
}

void Estante::imprimirDatosDelEstante(ofstream &arch) {
	arch << "Id: " << id << endl;
	arch << "Tipo: ";
	verificarTipoEstante(arch);
	arch << "Capacidad: " << capacidad << endl;
	arch << "Libros Contenidos:\n";
	imprimirLinea(arch, 50, '=');
	Llibros.imprimirLibros(arch);
}

void Estante::verificarTipoEstante(ofstream &arch) {
	if(clase == 'H') arch << "Horizontal\n";
	else arch << "Vertical\n";
}

//void Estante::imprimirLibros(ofstream &arch) {
//    Llibros.imprimirLibros(arch);
//}

void Estante::imprimirLinea(ofstream &arch, int cant, char c) {
	for(int i = 0; i < cant; i++)
		arch << c;
	arch << endl;
}
