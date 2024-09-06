/*
 * Proyecto : LAB8-2023_2-ClasesAutorreferenciadas
 * Archivo  : Flota.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 20:30
 */

#include "Flota.h"

Flota::Flota() {
}

Flota::Flota(const Flota &orig) {
}

Flota::~Flota() {
}

void Flota::cargaFlota() {
	lista.crear();
}

void Flota::cargaPedidos() {
	lista.cargarPedidos();
}

void Flota::muestraCarga() {
	lista.mostrar();
}
