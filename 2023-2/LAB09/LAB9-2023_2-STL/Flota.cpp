/*
 * Proyecto : LAB9-2023_2-STL
 * Archivo  : Flota.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 19 de junio de 2024, 17:58
 */

#include "Flota.h"

Flota::Flota() {
}

Flota::Flota(const Flota &orig) {
}

Flota::~Flota() {
}

void Flota::cargaFlota() {
	ifstream arch("Vehiculos.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Vehiculos.csv\n";
		exit(1);
	}
	NVehiculo vehiculo;
	char tipo;
	while(1) {
		arch >> tipo;
		if(arch.eof()) break;
		arch.get();
		vehiculo.asignarMemoria(tipo);
		arch >> vehiculo;
		vflota.push_back(vehiculo);
	}
	sort(vflota.begin(), vflota.end());
}

void Flota::cargaPedidos() {
	ifstream arch("Pedidos3.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Pedidos3.csv\n";
		exit(1);
	}
	int dni;
	while(1) {
		arch >> dni;
		if(arch.eof()) break;
		arch.get();
		int posCliente = buscarDni(dni);
		if(posCliente != -1) {
			NPedido pedido;
			arch >> pedido;
			vflota[posCliente].agregarPedido(pedido);
		} else while(arch.get() != '\n');
	}

}

int Flota::buscarDni(int dni) {
	for(int i = 0; vflota.size(); i++)
		if(vflota[i] == dni)
			return i;
	return -1;
}

void Flota::muestraCarga() {
	ofstream arch("ReporteDeVehiculos.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDeVehiculos.txt\n";
		exit(1);
	}
	arch << setw(26) << "REPORTE DE FLOTA" << endl;
	imprimirLinea(arch, 35, '=');
	arch << endl;
	for(int i = 0; i < vflota.size(); i++)
		arch << vflota[i];
}

void Flota::imprimirLinea(ofstream &arch, int cant, char c) {
	for(int i = 0; i < cant; i++)
		arch << c;
	arch << endl;
}
