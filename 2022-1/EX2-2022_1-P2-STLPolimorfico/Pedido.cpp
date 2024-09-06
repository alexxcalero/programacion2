/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Pedido.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:11
 */

#include "Pedido.h"

Pedido::Pedido() {
}

Pedido::Pedido(const Pedido &orig) {
	*this = orig;
}

Pedido::~Pedido() {
}

void Pedido::SetOrden(int orden) {
	this->orden = orden;
}

int Pedido::GetOrden() const {
	return orden;
}

void Pedido::SetTotal(double total) {
	this->total = total;
}

double Pedido::GetTotal() const {
	return total;
}

void Pedido::SetFecha(int fecha) {
	this->fecha = fecha;
}

int Pedido::GetFecha() const {
	return fecha;
}

void Pedido::SetDni(int dni) {
	this->dni = dni;
}

int Pedido::GetDni() const {
	return dni;
}

void Pedido::SetCantidad(int cantidad) {
	this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
	return cantidad;
}

void Pedido::SetCodigo(int codigo) {
	this->codigo = codigo;
}

int Pedido::GetCodigo() const {
	return codigo;
}

void Pedido::leer(ifstream &arch) {
	int dia, mes, anho;
	char c;
	arch >> codigo;
	if(arch.eof()) return;
	arch.get();
	arch >> cantidad >> c >> total >> c >> dni >> c;
	arch >> dia >> c >> mes >> c >> anho;
	fecha = anho * 10000 + mes * 100 + dia;
}

void Pedido::imprimir(ofstream &arch) {
	int dia, mes, anho;
	convertirFecha(dia, mes, anho);
	arch << right << setw(2) << setfill('0') << dia << '/' << setw(2) << setfill('0') << mes << '/';
	arch << right << setw(4) << setfill('0') << anho << setfill(' ');
	arch << right << setw(20) << codigo << setw(20) << cantidad;
	arch << setw(20) << setprecision(2) << fixed << total;
	if(orden != 0) arch << setw(10) << "SI";
	else arch << setw(10) << "NO";
	arch << endl;
}

void Pedido::convertirFecha(int &dia, int &mes, int &anho) {
	anho = fecha / 10000;
	fecha %= 10000;
	mes = fecha / 100;
	dia = fecha % 100;
}

void operator >>(ifstream &arch, Pedido *ped) {
	ped->leer(arch);
}

void operator <<(ofstream &arch, Pedido *ped) {
	ped->imprimir(arch);
}
