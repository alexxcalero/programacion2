/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : PrioridadBaja.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:24
 */

#include "PrioridadBaja.h"

PrioridadBaja::PrioridadBaja() {
	dias_espera = 0;
	nueva_fecha_entrega = 0;
}

PrioridadBaja::PrioridadBaja(const PrioridadBaja &orig) {
}

PrioridadBaja::~PrioridadBaja() {
}

void PrioridadBaja::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
	this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadBaja::GetNueva_fecha_entrega() const {
	return nueva_fecha_entrega;
}

void PrioridadBaja::SetDias_espera(int dias_espera) {
	this->dias_espera = dias_espera;
}

int PrioridadBaja::GetDias_espera() const {
	return dias_espera;
}

void PrioridadBaja::leer(ifstream &arch) {
	Pedido::leer(arch);
	arch >> dias_espera;
	arch.get();
}

void PrioridadBaja::actualizar() {
	SetNueva_fecha_entrega(GetFecha() + dias_espera);
	Pedido::SetTotal(GetSubtotal());
}

void PrioridadBaja::imprimir(ofstream &arch) {
	int dia, mes, anho;
	arch << left << setw(12) << "BAJA";
	Pedido::imprimir(arch);
	convertirNuevaFecha(dia, mes, anho);
	arch << right << setw(2) << setfill('0') << dia << '/' << setw(2) << mes << '/';
	arch << setw(4) << anho << setfill(' ') << setw(16) << " ";
	convertirFecha(dia, mes, anho);
	arch << right << setw(2) << setfill('0') << dia << '/' << setw(2) << mes << '/';
	arch << setw(4) << anho << setfill(' ') << setw(4) << " ";
	arch << right << setw(8) << setprecision(2) << fixed << Pedido::GetTotal() << endl;
}

void PrioridadBaja::convertirNuevaFecha(int &dia, int &mes, int &anho) {
	anho = nueva_fecha_entrega / 10000;
	nueva_fecha_entrega %= 10000;
	mes = nueva_fecha_entrega / 100;
	dia = nueva_fecha_entrega % 100;
}
