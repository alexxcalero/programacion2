/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : Almacen.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:25
 */

#include "Almacen.h"

Almacen::Almacen() {
	cantidad_ordenes = 0;
}

Almacen::Almacen(const Almacen &orig) {
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_ordenes(int cantidad_ordenes) {
	this->cantidad_ordenes = cantidad_ordenes;
}

int Almacen::GetCantidad_ordenes() const {
	return cantidad_ordenes;
}

void Almacen::cargar_pedidos() {
	ifstream arch("Pedidos.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Pedidos.csv\n";
		exit(1);
	}
	char categoria;
	while(1) {
		arch >> categoria;
		if(arch.eof()) break;
		arch.get();  // Leo la coma;
		ordenes[cantidad_ordenes].asignarMemoria(categoria);
		ordenes[cantidad_ordenes].leerDatos(arch);
		cantidad_ordenes++;
	}
}

void Almacen::actualizar_pedidos() {
	for(int i = 0; i < cantidad_ordenes; i++)
		ordenes[i].actualizarDatos();
}

void Almacen::imprimir_ordenes_ventas() {
	ofstream arch("ReporteFinal.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteFinal.txt\n";
		exit(1);
	}
	imprimirEncabezados(arch);
	for(int i = 0; i < cantidad_ordenes; i++) {
		ordenes[i].imprimirDatos(arch);
	}
}

void Almacen::imprimirEncabezados(ofstream &arch) {
	arch << left << setw(12) << "CATEGORIA" << setw(13) << "CODIGO" << setw(15) << "DNI CLIENTE";
	arch << setw(13) << "SUBTOTAL" << setw(17) << "FECHA ENTREGA" << setw(10) << "ESTADO";
	arch << setw(19) << "FECHA SOLICITADA" << "TOTAL" << endl;
	imprimirLinea(arch, '=');
}

void Almacen::imprimirLinea(ofstream &arch, char c) {
	for(int i = 0; i < 120; i++)
		arch << c;
	arch << endl;
}
