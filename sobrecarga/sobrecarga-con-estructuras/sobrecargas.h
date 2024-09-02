/*
 * Proyecto : sobrecarga-con-estructuras
 * Archivo  : sobrecargas.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 23 de marzo de 2024, 13:20
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include <iostream>
#include "Persona.h"
using namespace std;

//void operator << (ostream&, const Persona&);
ostream& operator << (ostream&, const Persona&);
//void operator >> (istream&, Persona&);
istream& operator >> (istream&, Persona&);
void operator >> (ifstream&, Persona&);
ofstream& operator << (ofstream&, const Persona&);
Persona& operator *= (Persona&, const double);
Persona* operator += (Persona*, const Persona&);
Persona* operator -= (Persona*, const Persona&);

#endif /* SOBRECARGAS_H */
