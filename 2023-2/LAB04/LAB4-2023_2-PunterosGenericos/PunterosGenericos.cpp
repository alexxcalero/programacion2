/*
 * Proyecto : LAB4-2023_2-PunterosGenericos
 * Archivo  : PunterosGenericos.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 25 de abril de 2024, 21:54
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "PunterosGenericos.h"
using namespace std;

void cargaproductos(void *&productos) {
	ifstream arch("Productos2.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Productos2.csv\n";
		exit(1);
	}
	void *buffProductos[200];
	int numDat = 0;
	while(true) {
		buffProductos[numDat] = leerProducto(arch);
		if(arch.eof()) break;
		numDat++;
	}
	memoriaExacta(productos, buffProductos, numDat);
}

// UCX-285,Galaxy Tab 3,3290.93,N
void *leerProducto(ifstream &arch) {
	void **registro;
	char *codigo, *descripcion, *tipo, c;
	double *precio;
	codigo = leerCadena(arch, 8, ',');
	if(arch.eof()) return nullptr;
	descripcion = leerCadena(arch, 70, ',');
	precio = new double;
	tipo = new char;
	arch >> *precio >> c >> *tipo;
	arch.get();  // Leo el salto de linea
	registro = new void*[4];
	registro[COD] = codigo;
	registro[DESC] = descripcion;
	registro[PREC] = precio;
	registro[TIPO] = tipo;
	return registro;
}

char *leerCadena(ifstream &arch, int size, char delim) {
	char *cadena, cad[size];
	arch.getline(cad, size, delim);
	if(arch.eof()) return nullptr;
	cadena = new char[strlen(cad) + 1];
	strcpy(cadena, cad);
	return cadena;
}

void memoriaExacta(void *&arreglo, void **buffArrEstatico, int numDat) {
	void **auxArr = new void*[numDat + 1]{};
	for(int i = 0; buffArrEstatico[i]; i++)
		auxArr[i] = buffArrEstatico[i];
	arreglo = auxArr;
}

void cargaclientes(void *&clientes) {
	ifstream arch("Clientes2.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Clientes2.csv\n";
		exit(1);
	}
	void *buffClientes[200];
	int numDat = 0;
	while(true) {
		buffClientes[numDat] = leerCliente(arch);
		if(arch.eof()) break;
		numDat++;
	}
	memoriaExacta(clientes, buffClientes, numDat);
}

// 79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000
void *leerCliente(ifstream &arch) {
	void **registro;
	int *dni, _dni, telefono;
	double *credito, _cred;
	char *nombre, c;
	arch >> _dni;
	if(arch.eof()) return nullptr;
	arch.get();  // Leo la coma
	nombre = leerCadena(arch, 70, ',');
	arch >> telefono >> c >> _cred;
	arch.get();  // Leo el salto de linea
	dni = new int;
	credito = new double;
	*dni = _dni;
	*credito = _cred;
	registro = new void*[4];
	registro[DNI] = dni;
	registro[NOMB] = nombre;
	registro[LIST_PED] = nullptr;
	registro[CRED] = credito;
	return registro;
}

void cargapedidos(void *p, void *&c) {
	ifstream arch("Pedidos2.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de Pedidos2.csv\n";
		exit(1);
	}
	void **productos = (void**)p;
	void **clientes = (void**)c;
	char *cod, car;
	int dniCli, cantSol, posCli, posProd, cantPed[200]{};
	while(true) {
		cod = leerCadena(arch, 8, ',');
		if(arch.eof()) break;
		arch >> dniCli >> car >> cantSol;
		arch.get();  // Leo el salto de linea
		posCli = buscarCliente(dniCli, c);
		if(posCli != -1) {
			posProd = buscarProducto(cod, p);
			if(posProd != -1) {
				registrarPedido(clientes[posCli], productos[posProd], cod, cantSol, cantPed[posCli]);
			}
		}
	}
	recortarEspacios(c, cantPed);
}

int buscarCliente(int dniCli, void *c) {
	void **clientes = (void**)c;
	for(int i = 0; clientes[i]; i++) {
		void **reg = (void**)clientes[i];
		int *dni = (int*)reg[DNI];
		if(*dni == dniCli)
			return i;
	}
	return -1;
}

int buscarProducto(char *codProd, void *p) {
	void **productos = (void**)p;
	for(int i = 0; productos[i]; i++) {
		void **reg = (void**)productos[i];
		char *cod = (char*)reg[COD];
		if(strcmp(cod, codProd) == 0)
			return i;
	}
	return -1;
}

void registrarPedido(void *&cliente, void *producto, char *cod, int cantSol, int &cantPed) {
	void **regCli = (void**)cliente;
	void **regProd = (void**)producto;

	if(cantPed == 0)
		regCli[LIST_PED] = new void*[500]{};

	char _tipo, *tipo = (char*)regProd[TIPO];
	_tipo = *tipo;
	double _precio, *precio = (double*)regProd[PREC], _total;
	_precio = *precio;
	_total = _precio * cantSol;
	double _credito, *credito = (double*)regCli[CRED];
	_credito = *credito;
	bool hayCredito = true;

	if(_tipo == 'S')
		if(_credito < _total)
			hayCredito = false;

	if(hayCredito) {
		void **regPed = (void**)regCli[LIST_PED];
		regPed[cantPed] = insertarPedido(cod, cantSol, _total);
		if(_tipo == 'S') {
			_credito -= _total;
			*credito = _credito;
			regCli[CRED] = credito;
		}
		cantPed++;
	}
}

void *insertarPedido(char *cod, int cantSol, double total) {
	int *cant = new int;
	double *tot = new double;
	*cant = cantSol;
	*tot = total;

	void **registro = new void*[3];

	registro[COD_PROD] = cod;
	registro[CANT] = cant;
	registro[TOTAL] = tot;

	return registro;
}

void recortarEspacios(void *&clientes, int *cantPed) {
	void **auxCli = (void**)clientes;
	void *arrPedidos;
	for(int i = 0; auxCli[i]; i++) {
		if(cantPed[i] != 0) {
			void **registro = (void**)auxCli[i];
			void **pedidos = (void**)registro[LIST_PED];
			memoriaExacta(arrPedidos, pedidos, cantPed[i]);
			registro[LIST_PED] = arrPedidos;
		}
	}
}
