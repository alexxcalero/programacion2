/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : NPedido.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:16
 */

#include "NPedido.h"

NPedido::NPedido() {
	codigo = nullptr;
	cantidad = 0;
	peso = 0.0;
	sig = nullptr;
}

NPedido::NPedido(const NPedido &orig) {
}

NPedido::~NPedido() {
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
