/*
 * Proyecto : sobrecarga-con-estructuras
 * Archivo  : funciones.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 23 de marzo de 2024, 13:20
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Persona.h"
#include "funciones.h"
#include "sobrecargas.h"
using namespace std;

void imprimirDatosPersona(const Persona& p) {
	cout.precision(2);
	cout << fixed;
	cout << setw(10) << p.dni << "  " << left << setw(20) << p.nombre;
	cout << right << setw(5) << p.peso << "  " << setw(5) << p.talla << endl;
}

void lecturaDatosPersona(Persona& p) {
	char nombre[20];
	cout << "Ingresa un DNI: "; cin >> p.dni;
	cin.get(); // Para comerme el enter
	cout << "Ingresa un nombre: "; cin.getline(nombre, 20, '\n');
	strcpy(p.nombre, nombre);
	cout << "Ingresa un peso: "; cin >> p.peso;
	cout << "Ingresa una talla: "; cin >> p.talla;
}

void llenarArregloPersonas(ifstream& arch, Persona* p) {
	int n = 0;
	while(true) {
		arch >> p[n];
		if(arch.eof()) break;
		n++;
	}
	Persona p_aux;
	p_aux.dni = 0;
	p[n] = p_aux;
}

void mostrarArregloPersonas(ofstream& arch, Persona* p) {
	imprimirCabeceras(arch);
	int n = 0;
	while(true) {
		if(p[n].dni == 0) break;
		arch << p[n];
		n++;
	}
}

void imprimirCabeceras(ofstream& arch) {
	arch << left << setw(14) << "DNI" << setw(30) << "NOMBRE Y APELLIDO";
	arch << setw(13) << "PESO" << "TALLA" << endl;
}
