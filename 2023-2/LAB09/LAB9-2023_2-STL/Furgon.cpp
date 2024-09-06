/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : Furgon.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:55
 */

#include "Furgon.h"

Furgon::Furgon() {
	filas = 0;
	puertas = 0;
}

Furgon::Furgon(const Furgon &orig) {
	filas = orig.filas;
	puertas = orig.puertas;
	pdeposito = orig.pdeposito;
}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
	this->puertas = puertas;
}

int Furgon::GetPuertas() const {
	return puertas;
}

void Furgon::SetFilas(int filas) {
	this->filas = filas;
}

int Furgon::GetFilas() const {
	return filas;
}

void Furgon::leer(ifstream &arch) {
	Vehiculo::leer(arch);
	char c;
	arch >> filas >> c >> puertas;
	arch.get();
}

void Furgon::imprimir(ofstream &arch) {
	Vehiculo::imprimir(arch);
	arch << left << setw(18) << "#Filas: " << filas << endl;
	arch << left << setw(18) << "#Puertas: " << puertas << endl;
	if(pdeposito.empty())
		arch << "No hay pedidos para el cliente\n";
	else {
		arch << "Lista de Pedidos:\n";
		for(NPedido i : pdeposito) {
			arch << "    ";
			arch << i;
		}
	}
	arch << endl;
}

bool Furgon::verificarCantidadDeCarros() {
	return true;  // Siempre devuelve true
}

void Furgon::cargarDeposito(NPedido &pedido) {
	pdeposito.push_front(pedido);
}
