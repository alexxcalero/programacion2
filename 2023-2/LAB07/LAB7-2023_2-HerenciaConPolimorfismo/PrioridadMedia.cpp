/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : PrioridadMedia.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:22
 */

#include "PrioridadMedia.h"

PrioridadMedia::PrioridadMedia() {
	descripcion = nullptr;
	nueva_fecha_entrega = 0;
}

PrioridadMedia::PrioridadMedia(const PrioridadMedia &orig) {
}

PrioridadMedia::~PrioridadMedia() {
	if(descripcion != nullptr) delete descripcion;
}

void PrioridadMedia::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
	this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadMedia::GetNueva_fecha_entrega() const {
	return nueva_fecha_entrega;
}

void PrioridadMedia::SetDescripcion(const char *descripcion) {
	if(this->descripcion != nullptr) delete this->descripcion;
	this->descripcion = new char[strlen(descripcion) + 1];
	strcpy(this->descripcion, descripcion);
}

void PrioridadMedia::GetDescripcion(char *descripcion) const {
	if(this->descripcion == nullptr) descripcion[0] = 0;
	else strcpy(descripcion, this->descripcion);
}

void PrioridadMedia::leer(ifstream &arch) {
	Pedido::leer(arch);
	int estado;
	arch >> estado;
	if(estado == 1) SetEstado("ACTIVO");
	else SetEstado("INACTIVO");
	arch.get();
}

void PrioridadMedia::actualizar() {
	char estado[100];
	GetEstado(estado);
	if(strcmp(estado, "ACTIVO") == 0)
		SetDescripcion("ACTIVO");
	else if(strcmp(estado, "INACTIVO") == 0)
		SetDescripcion("INACTIVO");
	SetNueva_fecha_entrega(GetFecha() + 1);
	Pedido::SetTotal(GetSubtotal());
}

void PrioridadMedia::imprimir(ofstream &arch) {
	int dia, mes, anho;
	char estado[100];
	GetEstado(estado);
	arch << left << setw(12) << "MEDIA";
	Pedido::imprimir(arch);
	convertirNuevaFecha(dia, mes, anho);
	arch << right << setw(2) << setfill('0') << dia << '/' << setw(2) << mes << '/';
	arch << setw(4) << anho << setfill(' ') << setw(4) << " ";
	arch << left << setw(12) << estado;
	convertirFecha(dia, mes, anho);
	arch << right << setw(2) << setfill('0') << dia << '/' << setw(2) << mes << '/';
	arch << setw(4) << anho << setfill(' ') << setw(4) << " ";
	arch << right << setw(8) << setprecision(2) << fixed << Pedido::GetTotal() << endl;
}

void PrioridadMedia::convertirNuevaFecha(int &dia, int &mes, int &anho) {
	anho = nueva_fecha_entrega / 10000;
	nueva_fecha_entrega %= 10000;
	mes = nueva_fecha_entrega / 100;
	dia = nueva_fecha_entrega % 100;
}
