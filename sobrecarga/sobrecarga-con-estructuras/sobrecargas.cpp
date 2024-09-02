/*
 * Proyecto : sobrecarga-con-estructuras
 * Archivo  : sobrecargas.cpp
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

// Si devuelvo un tipo VOID no podemos imprimir de la siguiente manera:
// cout << p1 << p2 << endl;
//void operator << (ostream& COUT, const Persona& p) {
//	COUT.precision(2);
//	COUT << fixed;
//	COUT << setw(10) << p.dni << "  " << left << setw(20) << p.nombre;
//	COUT << right << setw(5) << p.peso << "  " << setw(5) << p.talla << endl;
//}

// En cambio, si devuelvo un tipo OSTREAM, ahora puedo imprimir de la siguiente manera:
// cout << p1 << p2 << p3 << endl;
ostream& operator << (ostream& COUT, const Persona& p) {
	COUT.precision(2);
	COUT << fixed;
	COUT << setw(10) << p.dni << "  " << left << setw(20) << p.nombre;
	COUT << right << setw(5) << p.peso << "  " << setw(5) << p.talla << endl;
	return COUT;
}

// De esta manera, al devolver un VOID, solo puedo leer una estructura a la vez
//void operator >> (istream& CIN, Persona& p) {
//	char nombre[20];
//	cout << "Ingresa un DNI: "; CIN >> p.dni;
//	CIN.get(); // Para comerme el enter
//	cout << "Ingresa un nombre: "; CIN.getline(nombre, 20, '\n');
//	strcpy(p.nombre, nombre);
//	cout << "Ingresa un peso: "; CIN >> p.peso;
//	cout << "Ingresa una talla: "; CIN >> p.talla;
//}

// En cambio, si devulevo un ISTREAM ya puedo leer varias estructuras a la vez
// cin >> p1 >> p2 >> p3;
istream& operator >> (istream& CIN, Persona& p) {
	char nombre[20];
	cout << "Ingresa un DNI: "; CIN >> p.dni;
	CIN.get(); // Para comerme el enter
	cout << "Ingresa un nombre: "; CIN.getline(nombre, 20, '\n');
	strcpy(p.nombre, nombre);
	cout << "Ingresa un peso: "; CIN >> p.peso;
	cout << "Ingresa una talla: "; CIN >> p.talla;
	return CIN;
}

// HARE LA SOBRECARGA PARA LEER DE ACHIVOS DE TEXTOS
// De esta manera solo puedo leer una linea
//ifstream& operator >> (ifstream& arch, Persona& p) {
//	char c;
//	arch >> p.dni >> c >> p.nombre >> p.peso >> p.talla;
//}

void operator >> (ifstream& arch, Persona& p) {
	char c;
	arch >> p.dni;
	if(arch.eof()) return;
	arch >> c >> p.nombre >> p.peso >> p.talla;
	if(c == 'A') {
		p *= 0.1;
	} else if(c == 'B') {
		p *= -0.1;
	}
}

ofstream& operator << (ofstream& arch, const Persona& p) {
	arch.precision(2);
	arch << fixed;
	arch << setw(10) << p.dni << "    " << left << setw(25) << p.nombre;
	arch << right << setw(10) << p.peso << "  " << setw(10) << p.talla << endl;
}

Persona& operator *= (Persona& p, const double n) {
	p.peso *= (1 + n);
	p.talla *= (1 + n);
	return p;
}

Persona* operator += (Persona* arr_p, const Persona& p) {
	int n = 0;
	while(true) {
		if(arr_p[n].dni == 0) break;
		n++;
	}
	arr_p[n] = p;
	n++;
	arr_p[n].dni = 0;
	return arr_p;
}

Persona* operator -= (Persona* arr_p, const Persona& p) {
	int n = 0, n1 = 1;
	bool encontrado = false;
	while(true) {
		if(arr_p[n].dni == p.dni) {
			encontrado = true;
			break;
		}
		n++;
		n1++;
	}
	if(encontrado) {
		while(true) {
			if(arr_p[n].dni == 0)
				break;
			arr_p[n] = arr_p[n1];
			n++;
			n1++;
		}
	}
	return arr_p;
}
