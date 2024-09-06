/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : NPedido.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:46
 */

#include "NPedido.h"

NPedido::NPedido() {
	codigo = nullptr;
	cantidad = 0;
	peso = 0,0;
}

NPedido::NPedido(const NPedido &orig) {
	codigo = nullptr;
	cantidad = orig.cantidad;
	peso = orig.peso;
	char cod[100];
	orig.GetCodigo(cod);
	SetCodigo(cod);
}

NPedido::~NPedido() {
	//if(codigo != nullptr) delete codigo;
}

void NPedido::SetPeso(double peso) {
	this->peso = peso;
}

double NPedido::GetPeso() const {
	return peso;
}

void NPedido::SetCantidad(int cantidad) {
	this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
	return cantidad;
}

void NPedido::SetCodigo(const char *codigo) {
	if(this->codigo != nullptr) delete this->codigo;
	this->codigo = new char[strlen(codigo) + 1];
	strcpy(this->codigo, codigo);
}

void NPedido::GetCodigo(char *codigo) const {
	if(this->codigo == nullptr) codigo[0] = 0;
	else strcpy(codigo, this->codigo);
}

void NPedido::leer(ifstream &arch) {
	char codigo[100], c;
	arch.getline(codigo, 100, ',');
	SetCodigo(codigo);
	arch >> cantidad >> c >> peso;
	arch.get();
}

void NPedido::imprimir(ofstream &arch) {
	arch << left << setw(8) << codigo << right << setw(6) << cantidad;
	arch << setw(8) << setprecision(2) << fixed << peso << endl;
}

void operator >>(ifstream &arch, NPedido &ped) {
	ped.leer(arch);
}

void operator <<(ofstream &arch, NPedido &ped) {
	ped.imprimir(arch);
}
