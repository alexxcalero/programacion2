/*
 * Proyecto : LAB9-2023_1-Polimorfismo
 * Archivo  : Tesoreria.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de junio de 2024, 22:25
 */

#include "Tesoreria.h"

Tesoreria::Tesoreria() {
	cantBoletas = 0;
	cantEscalas = 0;
}

Tesoreria::Tesoreria(const Tesoreria &orig) {
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::setCantEscalas(int cantEscalas) {
	this->cantEscalas = cantEscalas;
}

int Tesoreria::getCantEscalas() const {
	return cantEscalas;
}

void Tesoreria::setCantBoletas(int cantBoletas) {
	this->cantBoletas = cantBoletas;
}

int Tesoreria::getCantBoletas() const {
	return cantBoletas;
}

void Tesoreria::cargaEscalas() {
	ifstream arch("escalas.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo escalas.csv\n";
		exit(1);
	}
	while(1) {
		Escala e;
		e.leer(arch);
		if(arch.eof()) break;
		lescala[cantEscalas] = e;
		cantEscalas++;
	}
//	for(int i = 0; i < cantEscalas; i++)
//		lescala[i].mostrar();
}

void Tesoreria::cargaAlumnos() {
	ifstream arch("Alumnos.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Alumnos.csv\n";
		exit(1);
	}
	char categoria;
	while(1) {
		arch >> categoria;
		if(arch.eof()) break;
		arch.get();
		lboleta[cantBoletas].asignarAlumno(arch, categoria);
		cantBoletas++;
	}
//	for(int i = 0; i < cantBoletas; i++)
//		lboleta[i].imprimir();
}

void Tesoreria::actualizaBoleta() {
	for(int i = 0; i < cantBoletas; i++) {
		int escala = lboleta[i].GetEscala();
		int posEscala = buscarEscala(escala);
		if(posEscala != -1) {
			double precioEscala = lescala[posEscala].GetPrecio();
			lboleta[i].calcularTotal(precioEscala);
		}
	}
}

int Tesoreria::buscarEscala(int codigo) {
	for(int i = 0; i < cantEscalas; i++)
		if(lescala[i].GetCodigo() == codigo)
			return i;
	return -1;
}

void Tesoreria::imprimeBoleta() {
	ofstream arch("ReporteFinal.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteFinal.txt\n";
		exit(1);
	}
	imprimirEncabezados(arch);
	for(int i = 0; i < cantBoletas; i++)
		lboleta[i].imprimir(arch);
}

void Tesoreria::imprimirEncabezados(ofstream &arch) {
	arch << left << setw(15) << "CODIGO" << setw(47) << "NOMBRE";
	arch << left << setw(11) << "ESCALA" << setw(15) << "CREDITOS";
	arch << left << setw(19) << "LICENCIA" << "TOTAL" << endl;
	imprimirLinea(arch, '=');
}

void Tesoreria::imprimirLinea(ofstream &arch, char c) {
	for(int i = 0; i < 120; i++)
		arch << c;
	arch << endl;
}
