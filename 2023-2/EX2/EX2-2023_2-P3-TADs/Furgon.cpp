/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : Furgon.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:35
 */

#include "Furgon.h"

Furgon::Furgon() {
}

Furgon::Furgon(const Furgon &orig) {
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
	arch.get();  // Leo el salto de linea
}

void Furgon::mostrar(ofstream &arch) {
	Vehiculo::mostrar(arch);
	arch << left << setw(25) << "#Puertas: ";
	arch << puertas << endl;
	arch << left << setw(25) << "#Filas: ";
	arch << filas << endl;
	if(depositos.size() == 0)
		arch << "    No hay pedidos para el cliente\n";
	else {
		arch << "Lista de pedidos:\n";
		for(Pedido &pedido : depositos)
			pedido.mostrar(arch);
	}
	arch << endl;
}

void Furgon::insertar(Pedido &pedido) {
	if(pedido.GetPeso() + GetCargaActual() <= GetCargaMaxima()) {
		list<Pedido>::iterator it;
		for(it = depositos.begin(); it != depositos.end(); it++)
			if((*it).GetPeso() > pedido.GetPeso())
				break;
		depositos.insert(it, pedido);
		SetCargaActual(GetCargaActual() + pedido.GetPeso());
	}
}
