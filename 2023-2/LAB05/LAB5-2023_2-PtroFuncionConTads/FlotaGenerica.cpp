/*
 * Proyecto : LAB5-2023_2-PtroFuncionConTads
 * Archivo  : FlotaGenerica.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 2 de mayo de 2024, 18:49
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Enums.h"
#include "FlotaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistros.h"
using namespace std;

void cargacamiones(void *&flota, int numcamiones, double pesomaximo, void *(*lee)(ifstream &), double (*calculanumero)(void *), const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}

	flota = nullptr;
	void **camiones = new void*[numcamiones]{};
	for(int i = 0; i < numcamiones; i++)
		inicializoCamiones(camiones[i]);

	void *dato;
	double pesoDato, pesoCamion;
	int indCamion = 0;
	while(1) {
		dato = lee(arch);
		if(arch.eof()) break;
		pesoDato = calculanumero(dato);
		pesoCamion = calculaPesoCamion(camiones[indCamion]);
		if(pesoCamion + pesoDato > pesomaximo) {
			indCamion++;
			if(indCamion >= numcamiones)
				break;
		}
		insertarAlInicio(dato, camiones[indCamion]);
		aumentarPesoCamion(pesoDato, camiones[indCamion]);
	}

	flota = camiones;
}

void inicializoCamiones(void *&camion) {
	double *ptrPeso = new double;
	*ptrPeso = 0.0;

	void **auxCamion = new void*[2]{};
	auxCamion[INI] = nullptr;
	auxCamion[PESOCAMION] = ptrPeso;

	camion = auxCamion;
}

double calculaPesoCamion(void *camion) {
	void **auxCamion = (void**)camion;
	double *peso = (double*)auxCamion[PESOCAMION];
	return *peso;
}

void insertarAlInicio(void *dato, void *&camion) {
	void **lista = (void**)camion;
	void **nuevo = new void*[2]{};
	nuevo[DATO] = dato;
	if(esListaVacia(lista[INI])) {
		nuevo[SIG] = nullptr;
		lista[INI] = nuevo;
	} else {
		nuevo[SIG] = lista[INI];
		lista[INI] = nuevo;
	}
}

void aumentarPesoCamion(double pesoDato, void *&camion) {
	void **auxCamion = (void**)camion;
	double *peso = (double*)auxCamion[PESOCAMION];
	*peso += pesoDato;
}

bool esListaVacia(void *lista) {
	return lista == nullptr;
}

void muestracamiones(void *flota, int numcamiones, void (*imprime)(void *, ofstream &), const char *nombArch) {
	ofstream arch(nombArch, ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	void **camiones = (void**)flota;
	for(int i = 0; i < numcamiones; i++) {
		void **camion = (void**)camiones[i];
		double *peso = (double*)camion[PESOCAMION];
		arch << "Camion " << i + 1 << ": Peso: " << fixed << setprecision(2) << setw(10) << *peso << endl;
		imprime(camion[INI], arch);
	}
}
