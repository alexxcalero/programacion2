/*
 * Proyecto : sobrecarga-con-estructuras
 * Archivo  : funciones.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 23 de marzo de 2024, 13:20
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include "Persona.h"
using namespace std;

void imprimirDatosPersona(const Persona&);
void lecturaDatosPersona(Persona&);
void llenarArregloPersonas(ifstream&, Persona*);
void mostrarArregloPersonas(ofstream&, Persona*);
void imprimirCabeceras(ofstream&);

#endif /* FUNCIONES_H */
