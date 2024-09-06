/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : PrioridadAlta.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:20
 */

#include "PrioridadAlta.h"

PrioridadAlta::PrioridadAlta() {
	recargo = 0.0;
	total = 0.0;
}

PrioridadAlta::PrioridadAlta(const PrioridadAlta &orig) {
}

PrioridadAlta::~PrioridadAlta() {
}

void PrioridadAlta::SetTotal(double total) {
	this->total = total;
}

double PrioridadAlta::GetTotal() const {
	return total;
}

void PrioridadAlta::SetRecargo(double recargo) {
	this->recargo = recargo;
}

double PrioridadAlta::GetRecargo() const {
	return recargo;
}

void PrioridadAlta::leer(ifstream &arch) {
	Pedido::leer(arch);
	arch >> recargo;
	recargo /= 100.0;
	arch.get();
}

void PrioridadAlta::actualizar() {
	double montoRecargo = recargo * GetSubtotal();
	total = montoRecargo;
	Pedido::SetTotal(GetSubtotal() + montoRecargo);
}

void PrioridadAlta::imprimir(ofstream &arch) {
	int dia, mes, anho;
	arch << left << setw(12) << "ALTA";
	Pedido::imprimir(arch);
	convertirFecha(dia, mes, anho);
	arch << right << setw(2) << setfill('0') << dia << '/' << setw(2) << mes << '/';
	arch << setw(4) << anho << setfill(' ') << setw(30) << " ";
	arch << right << setw(8) << setprecision(2) << fixed << Pedido::GetTotal() << endl;
}
