/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : Pedido.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:16
 */

#include "Pedido.h"

Pedido::Pedido() {
	codigo = nullptr;
	dni_cliente = 0;
	subtotal = 0.0;
	fecha = 0;
	estado = nullptr;
	total = 0.0;
}

Pedido::Pedido(const Pedido &orig) {
}

Pedido::~Pedido() {
	if(codigo != nullptr) delete codigo;
	if(estado != nullptr) delete estado;
}

void Pedido::SetTotal(double total) {
	this->total = total;
}

double Pedido::GetTotal() const {
	return total;
}

void Pedido::SetCodigo(const char *codigo) {
	if(this->codigo != nullptr) delete this->codigo;
	this->codigo = new char[strlen(codigo) + 1];
	strcpy(this->codigo, codigo);
}

void Pedido::GetCodigo(char *codigo) const {
	if(this->codigo == nullptr) codigo[0] = 0;
	else strcpy(codigo, this->codigo);
}

void Pedido::SetEstado(const char *estado) {
	if(this->estado != nullptr) delete this->estado;
	this->estado = new char[strlen(estado) + 1];
	strcpy(this->estado, estado);
}

void Pedido::GetEstado(char *estado) const {
	if(this->estado == nullptr) estado[0] = 0;
	else strcpy(estado, this->estado);
}

void Pedido::SetFecha(int fecha) {
	this->fecha = fecha;
}

int Pedido::GetFecha() const {
	return fecha;
}

void Pedido::SetSubtotal(double subtotal) {
	this->subtotal = subtotal;
}

double Pedido::GetSubtotal() const {
	return subtotal;
}

void Pedido::SetDni_cliente(int dni_cliente) {
	this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
	return dni_cliente;
}

void Pedido::leer(ifstream &arch) {
	char codigo[100], c;
	int dia, mes, anho;
	arch.getline(codigo, 100, ',');
	SetCodigo(codigo);
	arch >> dni_cliente >> c >> subtotal >> c >> anho >> c >> mes >> c >> dia >> c;
	fecha = anho * 10000 + mes * 100 + dia;
}

void Pedido::actualizar() {
}

void Pedido::imprimir(ofstream &arch) {
	int dia, mes, anho;
	char codigo[100];
	GetCodigo(codigo);
	arch << left << setw(10) << codigo << right << setw(12) << dni_cliente;
	arch << setw(12) << setprecision(2) << fixed << subtotal << setw(10) << " ";
}

void Pedido::convertirFecha(int &dia, int &mes, int &anho) {
	anho = fecha / 10000;
	fecha %= 10000;
	mes = fecha / 100;
	dia = fecha % 100;
}
