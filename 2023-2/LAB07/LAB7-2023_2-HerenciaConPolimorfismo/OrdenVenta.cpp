/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : OrdenVenta.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:25
 */

#include "OrdenVenta.h"

OrdenVenta::OrdenVenta() {
	ptr_orden = nullptr;
}

OrdenVenta::OrdenVenta(const OrdenVenta &orig) {
}

OrdenVenta::~OrdenVenta() {
	if(ptr_orden != nullptr) delete ptr_orden;
}

void OrdenVenta::asignarMemoria(char categoria) {
	if(categoria == 'A') {
		ptr_orden = new PrioridadAlta;
	} else if(categoria == 'M') {
		ptr_orden = new PrioridadMedia;
	} else {  // categoria == 'B'
		ptr_orden = new PrioridadBaja;
	}
}

void OrdenVenta::leerDatos(ifstream &arch) {
	ptr_orden->leer(arch);
}

void OrdenVenta::imprimirDatos(ofstream &arch) {
	ptr_orden->imprimir(arch);
}

void OrdenVenta::actualizarDatos() {
	ptr_orden->actualizar();
}
