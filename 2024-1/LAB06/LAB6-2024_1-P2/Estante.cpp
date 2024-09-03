/*
 * Proyecto : LAB6-2024_1-P1
 * Archivo  : Estante.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de mayo de 2024, 09:24
 */

#include "Estante.h"

Estante::Estante() {
	codigo = nullptr;
	anchura = 0;
	altura = 0;
	espacios = nullptr;
	cantLibros = 0;
}

Estante::Estante(const Estante &orig) {
}

Estante::~Estante() {
	if(codigo != nullptr) delete codigo;
	if(espacios != nullptr) delete espacios;
}

void Estante::SetCantLibros(int cantLibros) {
	this->cantLibros = cantLibros;
}

int Estante::GetCantLibros() const {
	return cantLibros;
}

void Estante::SetAltura(int altura) {
	this->altura = altura;
}

int Estante::GetAltura() const {
	return altura;
}

void Estante::SetAnchura(int anchura) {
	this->anchura = anchura;
}

int Estante::GetAnchura() const {
	return anchura;
}

void Estante::SetCodigo(const char *codigo) {
	if(this->codigo != nullptr) delete this->codigo;
	this->codigo = new char[strlen(codigo) + 1];
	strcpy(this->codigo, codigo);
}

void Estante::GetCodigo(char *codigo) const {
	if(this->codigo == nullptr) codigo[0] = 0;
	else strcpy(codigo, this->codigo);
}

void Estante::leer(ifstream &arch) {
	char codigo[100];
	arch.getline(codigo, 100, ',');
	if(arch.eof()) return;
	SetCodigo(codigo);
	arch >> anchura;
	arch.get();
	arch >> altura;
	arch.get();
	cantLibros = 0;
	espacios = new Espacio[anchura*altura]{};
}

void Estante::mostrar(ofstream &arch) {
	char codigo[100];
	GetCodigo(codigo);
	arch << "Codigo Estante: " << left << setw(10) << codigo;
	arch << "Cantidad de Libros: " << cantLibros << endl;
	arch << "Anchura del Estante: " << left << setw(5) << anchura;
	arch << "Altura del Estante: " << altura << endl;
	imprimirLinea(arch, '-');
//	for(int i = 0; i < altura; i++) {
//		for(int j = 0; j < anchura; j++) {
//			arch << espacios[j];
//		}
//		arch << endl;
//	}
//	for(int i = altura - 1; i >= 0; i--) {
//		for(int j = anchura - 1; j >= 0; j--) {
//			arch << espacios[j];
//		}
//		arch << endl;
//	}
	for(int i = 1; i <= anchura * altura; i++) {
		arch << espacios[i - 1];
		if(i % anchura == 0)
			arch << endl;
	}
	arch << endl;
	imprimirEncabezados(arch);
	for(int i = 0; i < cantLibros; i++)
		arch << libros[i];
}

void Estante::imprimirEncabezados(ofstream &arch) {
	arch << left << setw(11) << "CODIGO" << setw(25) << "NOMBRE";
	arch << setw(8) << "ANCHO" << "ALTO" << endl;
	imprimirLinea(arch, '.');
}

void Estante::imprimirLinea(ofstream &arch, char c) {
	for(int i = 0; i < MAX_LIN; i++)
		arch << c;
	arch << endl;
}

bool Estante::operator +=(Libro &libro) {
	// Calculo la anchura sobrante en el estante
	int anchuraSobrante = calcularAnchuraSobrante();
	// Verifico si el alto y ancho del libro son menores que la altura y
	// la anchura sobrante del estante
	if(anchuraSobrante >= libro.GetAncho() && altura >= libro.GetAlto()) {
		int colInicial = anchura - anchuraSobrante;  // Columna inicial donde pondre el libro
		int contadorAltura = libro.GetAlto();  // Me da el tamanho de la altura
		// Este doble for va a pintar mi matriz de estante de abajo para arriba
		for(int i = altura - 1; contadorAltura > 0; i--, contadorAltura--) {
			int contadorAnchura = libro.GetAncho();  // Me da el tamanho de la anchura
			for(int j = colInicial; contadorAnchura > 0; j++, contadorAnchura--) {
				espacios[i * anchura + j].SetContenido('*');
			}
		}
		libros[cantLibros] = libro;
		cantLibros++;
		libro.SetColocado(true);
		return true;
	} else {
		libro.SetColocado(false);
		return false;
	}
}

int Estante::calcularAnchuraSobrante() {
	int anchuraSobrante = 0;
	// Solo voy a leer la ultima fila de la matriz, xq es la que me dice si hay
	// posicionado un libro o no en el estante
	for(int i = altura - 1; i >= 0; i--) {
		for(int j = 0; j < anchura; j++) {
			if(espacios[i * anchura + j].GetContenido() == ' ')
				anchuraSobrante++;
		}
		break;
	}
	return anchuraSobrante;
}

ifstream &operator >>(ifstream &arch, Estante &estante) {
	estante.leer(arch);
}

ofstream &operator <<(ofstream &arch, Estante &estante) {
	estante.mostrar(arch);
}
