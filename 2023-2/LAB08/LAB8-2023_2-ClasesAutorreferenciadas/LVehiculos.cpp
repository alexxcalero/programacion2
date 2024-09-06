/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : LVehiculos.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:27
 */

#include "LVehiculos.h"

LVehiculos::LVehiculos() {
	lini = nullptr;
	lfin = nullptr;
}

LVehiculos::LVehiculos(const LVehiculos &orig) {
}

LVehiculos::~LVehiculos() {
}

void LVehiculos::crear() {
	ifstream arch("Vehiculos.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de Vehiculos.csv\n";
		exit(1);
	}
	Vehiculo *v;
	char categoria;
	while(1) {
		arch >> categoria;
		if(arch.eof()) break;
		arch.get();  // Leo la coma

		if(categoria == 'F') v = new Furgon;
		else v = new Camion;

		v->leer(arch);

		insertar(v);
	}
}

void LVehiculos::insertar(Vehiculo *v) {
	NodoLista *nuevoNodo = new NodoLista;
	nuevoNodo->unidad = v;

	if(lini == nullptr)
		lini = nuevoNodo;
	else
		lfin->sig = nuevoNodo;

	lfin = nuevoNodo;
}

void LVehiculos::mostrar() {
	ofstream arch("ReporteDeVehiculos.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDeVehiculos.txt\n";
		exit(1);
	}
	NodoLista *rec = lini;
	arch << setw(26) << "REPORTE DE FLOTA" << endl;
	for(int i = 0; i < 35; i++)
		arch << '=';
	arch << endl << endl;
	while(rec) {
		rec->unidad->imprimir(arch);
		rec = rec->sig;
	}
}

void LVehiculos::cargarPedidos() {
	ifstream arch("Pedidos3.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Pedidos3.csv\n";
		exit(1);
	}
	int cliente, cantidad;
	char codigo[100], c;
	double peso;
	while(1) {
		arch >> cliente;
		if(arch.eof()) break;
		arch.get();
		NodoLista *nodo = buscarCliente(cliente);
		if(nodo != nullptr) {
			arch.getline(codigo, 100, ',');
			arch >> cantidad >> c >> peso;
			nodo->unidad->push(codigo, cantidad, peso);
		} else while(arch.get() != '\n');
	}
}

NodoLista *LVehiculos::buscarCliente(int cliente) {
	if(lini == nullptr)  // Lista vacia
		return nullptr;

	NodoLista *rec = lini;
	while(rec) {
		if(rec->unidad->GetCliente() == cliente)
			return rec;  // Se encontro
		rec = rec->sig;
	}
	return nullptr;  // No se encontro
}
