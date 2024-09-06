/*
 * Proyecto : EX2-2023_2-P2-STL
 * Archivo  : Flota.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de julio de 2024, 21:36
 */

#include "Flota.h"

Flota::Flota() {
}

Flota::Flota(const Flota &orig) {
}

Flota::~Flota() {
}

void Flota::cargarVehiculos() {
	ifstream arch("Vehiculos.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Vehiculos.csv\n";
		exit(1);
	}
	Vehiculo *vehiculo;
	char tipo;
	while(1) {
		arch >> tipo;
		if(arch.eof()) break;
		arch.get();  // Leo la coma
		if(tipo == 'F') vehiculo = new Furgon;
		else vehiculo = new Camion;
		vehiculo->leer(arch);
		vehiculos[vehiculo->GetPlaca()] = vehiculo;
	}
}

void Flota::cargarPedidos() {
	ifstream arch("Pedidos4.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Pedidos4.csv\n";
		exit(1);
	}
	Pedido pedido;
	char plaquita[100];
	string placa;
	while(1) {
		arch.getline(plaquita, 100, ',');
		if(arch.eof()) break;
		placa = plaquita;
		arch >> pedido;
		vehiculos[placa]->insertar(pedido);
	}
}

void Flota::mostrarVehiculos() {
	ofstream arch("ReporteDeVehiculos.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDeVehiculos.txt\n";
		exit(1);
	}
	arch << right << setw(25) << "REPORTE DE FLOTA" << endl;
	imprimirLinea(arch, 37, '=');
	for(const auto &vehiculo : vehiculos) {
		// Piden mostrar solo ciertos vehiculos.
		// Si queremos mostrar todos, quitamos la condicional
		if(vehiculo.first == "A1Q-612" || vehiculo.first == "D9A-711" || vehiculo.first == "O8J-848"
		   || vehiculo.first == "Q5S-871" || vehiculo.first == "Z4L-514") {
			vehiculo.second->mostrar(arch);
			imprimirLinea(arch, 37, '=');
		}
	}
}

void Flota::imprimirLinea(ofstream &arch, int cant, char c) {
	for(int i = 0; i < cant; i++)
		arch << c;
	arch << endl;
}
