/*
 * Proyecto : EX1-2023_2-P3-PunterosAFuncion
 * Archivo  : ColaConProductos.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 02:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Pregunta1.h"
#include "Pregunta2.h"
#include "ColaGenerica.h"
#include "ColaConProductos.h"
using namespace std;

void procesarPedidos(int **fechaClienteCantidad, char **codigoDelProducto, void *&productos) {
	void **auxProducto = (void**)productos, **nodo, **dato;
	int posProd, *datosPed, *stock;
	char *codProd;
	for(int i = 0; fechaClienteCantidad[i]; i++) {
		codProd = codigoDelProducto[i];
		posProd = buscarProducto(codProd, productos);
		if(posProd != -1) {
			datosPed = fechaClienteCantidad[i];
			nodo = (void**)auxProducto[posProd];
			dato = (void**)nodo[DATO];
			stock = (int*)dato[STK];
			if(*stock >= datosPed[CANT]) {
				if(nodo[SIG] == nullptr) generaCola(nodo[SIG]);
				*stock -= datosPed[CANT];
				encolar(datosPed, nodo[SIG]);
			}
		}
	}
}

int buscarProducto(char *codProd, void *productos) {
	void **recProductos = (void**)productos;
	for(int i = 0; recProductos[i]; i++) {
		void **nodo = (void**)recProductos[i];
		void **dato = (void**)nodo[DATO];
		char *codigo = (char*)dato[COD];
		if(strcmp(codigo, codProd) == 0)
			return i;
	}
	return -1;
}

void reporteDePedidos(void *productos, const char *nombArch) {
	ofstream arch(nombArch, ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo PruebaProductos.txt\n";
		exit(1);
	}
	void **recProductos = (void**)productos, **nodo, *dato;
	for(int i = 0; recProductos[i]; i++) {
		arch << "Producto " << i + 1 << ":\n";
		nodo = (void**)recProductos[i];
		imprimirDatos(arch, nodo[DATO]);
		arch << "Pedidos aceptados:\n";
		arch << left << setw(10) << "Fecha" << setw(13) << "DNI" << "Cantidad\n";
		// Nos aseguramos que solo imprimamos cuando exista una cola.
		// Ya que sino estariamos pasando un nullptr, y se cae el programa.
		if(nodo[SIG] != nullptr)
			imprimirPedidos(arch, nodo[SIG]);
		arch << endl;
	}
}

void imprimirDatos(ofstream &arch, void *dato) {
	void **auxDato = (void**)dato;
	char *codigo, *descripcion;
	double *precio;
	int *stock;
	codigo = (char*)auxDato[COD];
	descripcion = (char*)auxDato[DESC];
	precio = (double*)auxDato[PREC];
	stock = (int*)auxDato[STK];
	arch << left << setw(10) << codigo << descripcion << endl;
	arch << "Precio: " << right << setw(10) << *precio << "    ";
	arch << "Stock: " << *stock << endl;
}

void imprimirPedidos(ofstream &arch, void *cola) {
	void *dato;
	while(!esColaVacia(cola)) {
		dato = desencolar(cola);
		int *auxDato = (int*)dato;
		arch << left << setw(10) << auxDato[FECH] << setw(13) << auxDato[DNI] << auxDato[CANT] << endl;
	}
}
