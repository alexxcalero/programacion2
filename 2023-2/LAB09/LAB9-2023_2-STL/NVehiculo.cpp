/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : NVehiculo.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:57
 */

#include "NVehiculo.h"

NVehiculo::NVehiculo() {
	unidad = nullptr;
}

NVehiculo::NVehiculo(const NVehiculo &orig) {
	unidad = nullptr;
	*this = orig;
}

NVehiculo::~NVehiculo() {
//	if(unidad != nullptr) delete unidad;
}

void NVehiculo::asignarMemoria(char tipo) {
	if(tipo == 'F') unidad = new Furgon;
	else unidad = new Camion;
}

bool NVehiculo::operator <(NVehiculo &v) {
	return unidad->GetCliente() < v.unidad->GetCliente();
}

bool NVehiculo::operator ==(int dni) {
	return unidad->GetCliente() == dni;
}

void NVehiculo::leer(ifstream &arch) {
	unidad->leer(arch);
}

void NVehiculo::imprimir(ofstream &arch) {
	unidad->imprimir(arch);
}

void NVehiculo::agregarPedido(NPedido &pedido) {
	double pesoActual = unidad->GetActcarga();
	double pesoMaximo = unidad->GetMaxcarga();
	double pesoPedido = pedido.GetPeso();
	if(pesoActual + pesoPedido <= pesoMaximo) {
		if(unidad->verificarCantidadDeCarros()) {  // Solo para el caso de camiones
			unidad->cargarDeposito(pedido);
			pesoActual += pesoPedido;
			unidad->SetActcarga(pesoActual);
		}
	}
}

void operator >>(ifstream &arch, NVehiculo &vehiculo) {
	vehiculo.leer(arch);
}

void operator <<(ofstream &arch, NVehiculo &vehiculo) {
	vehiculo.imprimir(arch);
}
