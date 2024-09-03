/*
 * Proyecto : EX1-2023_2-P1-PunterosMultiples
 * Archivo  : Pregunta1.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de mayo de 2024, 20:45
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Pregunta1.h"
#define INCREMENTO 5
#define MAXLIN 50
using namespace std;

void cargarPedidos(int **&fechaClienteCantidad, char **&codigoDelProducto, const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	fechaClienteCantidad = nullptr;
	codigoDelProducto = nullptr;
	int numDat = 0, capacidad = 0;
	char *codigo, c;
	int dni, cantidad, dd, mm, aa, fecha;
	while(1) {
		codigo = leerCadena1(arch, 8, ',');
		if(arch.eof()) break;
		arch >> dni >> c >> cantidad >> c >> dd >> c >> mm >> c >> aa;
		arch.get();  // Leo el salto de linea
		fecha = aa * 10000 + mm * 100 + dd;
		if(numDat == capacidad) incrementarMemoria(fechaClienteCantidad, codigoDelProducto, numDat, capacidad);
		codigoDelProducto[numDat - 1] = codigo;
		fechaClienteCantidad[numDat - 1] = insertarFechaClienteCantidad(fecha, dni, cantidad);
		numDat++;
	}
	ordenarArreglos(fechaClienteCantidad, codigoDelProducto);
}

char *leerCadena1(ifstream &arch, int size, char delim) {
	char *cadena, buffCad[size];
	arch.getline(buffCad, size, delim);
	if(arch.eof()) return nullptr;
	cadena = new char[strlen(buffCad) + 1];
	strcpy(cadena, buffCad);
	return cadena;
}

void incrementarMemoria(int **&fechaClienteCantidad, char **&codigoDelProducto, int &num, int &cap) {
	int **auxFecha;
	char **auxCodigo;
	cap += INCREMENTO;
	if(fechaClienteCantidad == nullptr) {
		fechaClienteCantidad = new int*[cap]{};
		codigoDelProducto = new char*[cap]{};
		num = 1;
	} else {
		auxFecha = new int*[cap]{};
		auxCodigo = new char*[cap]{};
		for(int i = 0; i < num; i++) {
			auxFecha[i] = fechaClienteCantidad[i];
			auxCodigo[i] = codigoDelProducto[i];
		}
		delete fechaClienteCantidad;
		delete codigoDelProducto;
		fechaClienteCantidad = auxFecha;
		codigoDelProducto = auxCodigo;
	}
}

int *insertarFechaClienteCantidad(int fecha, int dni, int cantidad) {
	int *arreglo = new int[3]{};
	arreglo[FECH] = fecha;
	arreglo[DNI] = dni;
	arreglo[CANT] = cantidad;
	return arreglo;
}

void ordenarArreglos(int **&fechaClienteCantidad, char **&codigoDelProducto) {
	int numDat = 0;
	while(fechaClienteCantidad[numDat]) numDat++;
	mergeSort(fechaClienteCantidad, codigoDelProducto, numDat, 0, numDat - 1);
}

void mergeSort(int **&fechaClienteCantidad, char **&codigoDelProducto, int cant, int ini, int fin) {
	if(ini == fin)
		return;

	int med = (ini + fin) / 2;
	mergeSort(fechaClienteCantidad, codigoDelProducto, cant, ini, med);
	mergeSort(fechaClienteCantidad, codigoDelProducto, cant, med + 1, fin);
	merge(fechaClienteCantidad, codigoDelProducto, cant, ini, med, fin);
}

void merge(int **&fechaClienteCantidad, char **&codigoDelProducto, int cant, int ini, int med, int fin) {
	int *auxFecha[cant]{}, *arrP, *arrQ;
	char *auxCodigo[cant]{};
	int p, q, m;
	for(p = ini, q = med + 1, m = ini; p <= med && q <= fin; m++) {
		arrP = fechaClienteCantidad[p];
		arrQ = fechaClienteCantidad[q];
		if(arrP[FECH] < arrQ[FECH]) {
			auxFecha[m] = fechaClienteCantidad[p];
			auxCodigo[m] = codigoDelProducto[p];
			p++;
		} else {
			auxFecha[m] = fechaClienteCantidad[q];
			auxCodigo[m] = codigoDelProducto[q];
			q++;
		}
	}

	while(p <= med) {
		auxFecha[m] = fechaClienteCantidad[p];
		auxCodigo[m] = codigoDelProducto[p];
		p++;
		m++;
	}

	while(q <= fin) {
		auxFecha[m] = fechaClienteCantidad[q];
		auxCodigo[m] = codigoDelProducto[q];
		q++;
		m++;
	}

	for(int i = ini; i <= fin; i++) {
		fechaClienteCantidad[i] = auxFecha[i];
		codigoDelProducto[i] = auxCodigo[i];
	}
}

void pruebaDeCargaDePedidos(int **fechaClienteCantidad, char **codigoDelProducto, const char *nombArch) {
	ofstream arch(nombArch, ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	int *auxFecha, dd, mm, aa;
	imprimirEncabezados1(arch);
	for(int i = 0; fechaClienteCantidad[i]; i++) {
		arch << left << setw(10) << codigoDelProducto[i];
		auxFecha = fechaClienteCantidad[i];
		arch << setw(13) << auxFecha[DNI] << setw(8) << auxFecha[CANT];
		separarFecha(auxFecha[FECH], dd, mm, aa);
		arch << setfill('0') << right << setw(2) << dd << '/' << setw(2) << mm;
		arch << '/' << setw(2) << aa << endl << setfill(' ');
	}
}

void separarFecha(int fecha, int &dia, int &mes, int &anho) {
	anho = fecha / 10000;
	fecha %= 10000;
	mes = fecha / 100;
	dia = fecha % 100;
}

void imprimirEncabezados1(ofstream &arch) {
	arch << "  " << left << setw(10) << "CODIGO";
	arch << setw(10) << "DNI";
	arch << setw(10) << "CANT";
	arch << setw(10) << "FECHA";
	arch << endl;
	imprimirLinea1(arch, '-');
}

void imprimirLinea1(ofstream &arch, char car) {
	for(int i = 0; i < MAXLIN; i++)
		arch << car;
	arch << endl;
}
