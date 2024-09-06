/*
 * Proyecto : LAB8-2023_1-Herencia
 * Archivo  : Tesoreria.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 29 de mayo de 2024, 00:45
 */

#include "Tesoreria.h"

Tesoreria::Tesoreria() {
	cantPresencial = 0;
	cantSemipresencial = 0;
	cantVirtual = 0;
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

void Tesoreria::setCantVirtual(int cantVirtual) {
	this->cantVirtual = cantVirtual;
}

int Tesoreria::getCantVirtual() const {
	return cantVirtual;
}

void Tesoreria::setCantSemipresencial(int cantSemipresencial) {
	this->cantSemipresencial = cantSemipresencial;
}

int Tesoreria::getCantSemipresencial() const {
	return cantSemipresencial;
}

void Tesoreria::setCantPresencial(int cantPresencial) {
	this->cantPresencial = cantPresencial;
}

int Tesoreria::getCantPresencial() const {
	return cantPresencial;
}

void Tesoreria::cargaescalas() {
	ifstream arch("Escalas.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Escalas.csv\n";
		exit(1);
	}
	cantEscalas = 0;
	while(1) {
		Escala e;
		e.leer(arch);
		if(arch.eof()) break;
		lescala[cantEscalas] = e;
		cantEscalas++;
	}
//	for(int i = 0; i < cantEscalas; i++)
//		cout << lescala[i].GetCodigo() << "-" << lescala[i].GetPrecio() << endl;
}

void Tesoreria::cargaalumnos() {
	ifstream arch("Alumnos.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Alumnos.csv\n";
		exit(1);
	}
	cantPresencial = cantSemipresencial = cantVirtual = 0;
	char categoria;
	while(1) {
		arch >> categoria;
		if(arch.eof()) break;
		arch.get();
		if(categoria == 'P') {
//			Presencial p;
//			p.leer(arch);
//			lpresencial[cantPresencial] = p;
			lpresencial[cantPresencial].leer(arch);
			cantPresencial++;
		}
		if(categoria == 'S') {
//			Semipresencial s;
//			s.leer(arch);
//			lsemipresencial[cantSemipresencial] = s;
			lsemipresencial[cantSemipresencial].leer(arch);
			cantSemipresencial++;
		}
		if(categoria == 'V') {
//			Virtual v;
//			v.leer(arch);
//			lvirtual[cantVirtual] = v;
			lvirtual[cantVirtual].leer(arch);
			cantVirtual++;
		}
	}
//	cout << cantPresencial << " " << cantSemipresencial << " " << cantVirtual << endl;
}

void Tesoreria::actualiza(double creditos) {
	double precio, total;
	for(int i = 0; i < cantPresencial; i++) {
		precio = buscarPrecioPorEscala(lpresencial[i].GetEscala());
		if(precio != 0) {
			total = creditos * precio;
			double recargo = total * lpresencial[i].GetRecargo();
			lpresencial[i].SetTotal(recargo);
			lpresencial[i].modificarTotalAbs(total + recargo);
		}
	}

	for(int i = 0; i < cantSemipresencial; i++) {
		precio = buscarPrecioPorEscala(lsemipresencial[i].GetEscala());
		if(precio != 0) {
			total = creditos * precio;
			double descuento = total * lsemipresencial[i].GetDescuento();
			lsemipresencial[i].SetTotal(descuento);
			lsemipresencial[i].modificarTotalAbs(total - descuento);
		}
	}

	for(int i = 0; i < cantVirtual; i++) {
		precio = buscarPrecioPorEscala(lvirtual[i].GetEscala());
		if(precio != 0) {
			total = creditos * precio;
			lvirtual[i].SetTotal(100.0);
			lvirtual[i].modificarTotalAbs(total + 100.0);
		}
	}
}

double Tesoreria::buscarPrecioPorEscala(int escala) {
	for(int i = 0; i < cantEscalas; i++)
		if(lescala[i].GetCodigo() == escala)
			return lescala[i].GetPrecio();
	return 0;
}

void Tesoreria::imprime() {
	ofstream arch("ReporteFinal.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteFinal.txt\n";
		exit(1);
	}

	imprimirEncabezados(arch);

	for(int i = 0; i < cantPresencial; i++)
		lpresencial[i].mostrar(arch);

	for(int i = 0; i < cantSemipresencial; i++)
		lsemipresencial[i].mostrar(arch);

	for(int i = 0; i < cantVirtual; i++)
		lvirtual[i].mostrar(arch);
}

void Tesoreria::imprimirEncabezados(ofstream &arch) {
	arch << left << setw(15) << "Codigo" << setw(47) << "Nombre";
	arch << setw(13) << "Escala" << setw(19) << "Licencia";
	arch << setw(10) << "Total" << endl;
	imprimirLinea(arch, '=');
}

void Tesoreria::imprimirLinea(ofstream &arch, char c) {
	for(int i = 0; i < MAX_LIN; i++)
		arch << c;
	arch << endl;
}
