/*
 * Proyecto : sobrecarga-con-estructuras
 * Archivo  : main.cpp
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

int main(int argc, char** argv) {
	Persona p;
	p.dni = 12345678;
	strcpy(p.nombre, "Alex Calero");
	p.peso = 82.5;
	p.talla = 1.76;

	//imprimirDatosPersona(p); // Esta funcion no sobrecarga el operador <<

	// Vamos a sobrecargar el operador <<
	//cout << p << endl;

	// Si yo quiero imprimir varias personas, con la sobrecarga actual no se puede
	// cout << p1 << p2  <- Esto no se puede... de momento

	Persona p2;
	p2.dni = 87654321;
	strcpy(p2.nombre, "Valeria Calero");
	p2.peso = 80.5;
	p2.talla = 1.65;

	//cout << p << p2 << endl;


	// Ahora haremos los mismos procesos para el operador de lectura >>
	//Persona p3, p4;
	//lecturaDatosPersona(p3); // Estas funcion no sobrecarga el operador >>
	//lecturaDatosPersona(p4); // Y esta tampoco sobrecarga el operador >>
	//cout << p << p2 << p3 << p4;

	// Sobrecargo el operador >>
	// Con la primera sobrecarga no puedo leer varias estructuras a la vez
	//cin >> p3;
	//cout << p3;

	//cin >> p3 >> p4;
	//cout << p3 << p4;

	// Recordar que si queremos sobrecargar la lectura al leer de un documento de
	// texto, es lo mismo solo que tenemos que cambiar los siguientes parametros:
	// istream& -> ifstream&
	// ostream& -> ofstream&
	//Persona p5;

	ifstream archIn("data.txt", ios::in);
	if(!archIn.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo data.txt\n";
		exit(1);
	}
	ofstream archOut("reporte.txt", ios::out);
	if(!archOut.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo reporte.txt\n";
		exit(1);
	}

	//archIn >> p5;
	//archOut << p5;

	// Voy a leer todo el archivo de texto
	Persona personas[20];
	llenarArregloPersonas(archIn, personas);
	mostrarArregloPersonas(archOut, personas);

	personas += p;
	personas += p2;
	archOut << endl;
	mostrarArregloPersonas(archOut, personas);

	Persona p6;
	p6.dni = 23456789;
	strcpy(p.nombre, "Perez_Maria");
	p.peso = 58.77;
	p.talla = 1.51;

	personas -= p6;
	archOut << endl;
	mostrarArregloPersonas(archOut, personas);

	return 0;
}
