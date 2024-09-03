/*
 * Proyecto : LAB6-2024_1-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de mayo de 2024, 11:56
 */

#include "Biblioteca.h"

int main(int argc, char** argv) {
	Biblioteca biblioteca;

	biblioteca.cargarLibros();
	biblioteca.cargarEstantes();
	biblioteca.posicionarLibros();
	biblioteca.mostrarDatos();

	return EXIT_SUCCESS;
}
