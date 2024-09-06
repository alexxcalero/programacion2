/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : Camion.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:52
 */

#include "Camion.h"

Camion::Camion() {
	ejes = 0;
	llantas = 0;
}

Camion::Camion(const Camion &orig) {
	ejes = orig.ejes;
	llantas = orig.llantas;
	mdeposito = orig.mdeposito;
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
	arch.get();
}

void Camion::imprimir(ofstream &arch) {
	Vehiculo::imprimir(arch);
	arch << left << setw(18) << "#Ejes: " << ejes << endl;
	arch << left << setw(18) << "#Llantas: " << llantas << endl;
	if(mdeposito.empty())
		arch << "No hay pedidos para el cliente\n";
	else {
		arch << "Lista de Pedidos:" << endl;
		for(auto i : mdeposito) {
			arch << "    " << i.first << "  ";
			arch << i.second;
		}
	}
	arch << endl;
}

bool Camion::verificarCantidadDeCarros() {
	return mdeposito.size() < 5;  // Verifica que hayan menos de cinco carros
}

void Camion::cargarDeposito(NPedido &pedido) {
	mdeposito[mdeposito.size() + 1] = pedido;
}
