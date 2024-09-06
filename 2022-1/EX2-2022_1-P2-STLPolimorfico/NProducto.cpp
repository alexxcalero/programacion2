/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : NProducto.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:19
 */

#include "NProducto.h"

NProducto::NProducto() {
	prod = nullptr;
}

NProducto::NProducto(const NProducto &orig) {
	prod = nullptr;
	*this = orig;
}

NProducto::~NProducto() {
}

void NProducto::asignarMemoria(int categoria) {
	if(categoria == 1) prod = new Categoria1;
	else if(categoria == 2) prod = new Categoria2;
	else prod = new Categoria3;
}

void NProducto::leer(ifstream &arch) {
	prod->leer(arch);
}

int NProducto::obtenerPrioridad() {
	return prod->obtenerPrioridad();
}

int NProducto::obtenerCodigo() {
	return prod->GetCodprod();
}

void NProducto::imprimir(ofstream &arch) {
	prod->imprimir(arch);
}

void operator >>(ifstream &arch, NProducto &prod) {
	prod.leer(arch);
}

void operator <<(ofstream &arch, NProducto &prod) {
	prod.imprimir(arch);
}
