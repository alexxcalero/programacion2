/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : Camion.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:33
 */

#include "Camion.h"

Camion::Camion() {
}

Camion::Camion(const Camion &orig) {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
	this->llantas = llantas;
}

int Camion::GetLlantas() const {
	return llantas;
}

void Camion::SetEjes(int ejes) {
	this->ejes = ejes;
}

int Camion::GetEjes() const {
	return ejes;
}

void Camion::leer(ifstream &arch) {
	Vehiculo::leer(arch);
	char c;
	arch >> ejes >> c >> llantas;
	arch.get();  // Leo el salto de linea
}

void Camion::mostrar(ofstream &arch) {
	Vehiculo::mostrar(arch);
	arch << left << setw(25) << "#Llantas: ";
	arch << llantas << endl;
	arch << left << setw(25) << "#Ejes: ";
	arch << ejes << endl;
	if(depositos.size() == 0)
		arch << "    No hay pedidos para el cliente\n";
	else {
		arch << "Lista de pedidos:\n";
		for(Pedido &pedido : depositos)
			pedido.mostrar(arch);
	}
	arch << endl;
}

void Camion::insertar(Pedido &pedido) {
	if(depositos.size() < 5 && (pedido.GetPeso() + GetCargaActual() <= GetCargaMaxima())) {
		depositos.push_back(pedido);
		SetCargaActual(GetCargaActual() + pedido.GetPeso());
	}
}
