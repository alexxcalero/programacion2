/*
 * Proyecto : EX1-2024_1-P1-PunterosMultiples
 * Archivo  : Pregunta1.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 08:07
 */

#include <iomanip>
#include <fstream>
#include <cstring>
#include "Enums.h"
#include "Pregunta1.h"
#include "AperturaDeArchivos.h"
using namespace std;

void cargarVentas(char **&ventasLibroCodigo, int **&ventasDniFechaPuntaje,
        const char *nombArch) {
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);

	ventasLibroCodigo = nullptr;
	ventasDniFechaPuntaje = nullptr;

	int numDat = 0, capacidad = 0, dni, dia, mes, anho, fecha, puntaje;
	char *codigo, c;
	while(1) {
		codigo = leerCadena(arch, 8, ',');
		if(arch.eof()) break;
		arch >> dni >> c >> dia >> c >> mes >> c >> anho >> c >> puntaje;
		arch.get();  // Leo el salto de linea
		if(numDat == capacidad)
			incrementarMemoria(ventasLibroCodigo, ventasDniFechaPuntaje, numDat, capacidad);
		fecha = anho * 10000 + mes * 100 + dia;
		ventasLibroCodigo[numDat - 1] = codigo;
		ventasDniFechaPuntaje[numDat - 1] = insertarDatosFecha(dni, fecha, puntaje);
		numDat++;
	}
}

char *leerCadena(ifstream &arch, int size, char delim) {
	char *cadena, buffCad[size];
	arch.getline(buffCad, size, delim);
	if(arch.eof()) return nullptr;
	cadena = new char[strlen(buffCad) + 1];
	strcpy(cadena, buffCad);
	return cadena;
}

void incrementarMemoria(char **&ventasLibroCodigo, int **&ventasDniFechaPuntaje,
        int &num, int &cap) {
	char **auxVentasLibro;
	int **auxVentasDni;
	cap += INCREMENTO;
	if(ventasLibroCodigo == nullptr) {
		ventasLibroCodigo = new char*[cap]{};
		ventasDniFechaPuntaje = new int*[cap]{};
		num = 1;
	} else {
		auxVentasLibro = new char*[cap]{};
		auxVentasDni = new int*[cap]{};
		for(int i = 0; i < num; i++) {
			auxVentasLibro[i] = ventasLibroCodigo[i];
			auxVentasDni[i] = ventasDniFechaPuntaje[i];
		}
		delete ventasLibroCodigo;
		delete ventasDniFechaPuntaje;
		ventasLibroCodigo = auxVentasLibro;
		ventasDniFechaPuntaje = auxVentasDni;
	}
}

int *insertarDatosFecha(int dni, int fecha, int puntaje) {
	int *datos = new int[3]{};
	datos[DNI] = dni;
	datos[FECH] = fecha;
	datos[PUNT] = puntaje;
	return datos;
}

void pruebaDeCargaDeVentas(char **ventasLibroCodigo, int **ventasDniFechaPuntaje,
        const char *nombArch) {
	ofstream arch;
	AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);

	imprimirTitulo(arch);
	imprimirEncabezados(arch);
	int *auxVentasDni, dia, mes, anho;
	for(int i = 0; ventasLibroCodigo[i]; i++) {
		auxVentasDni = ventasDniFechaPuntaje[i];
		arch << left << setw(10) << ventasLibroCodigo[i] << setw(10) << auxVentasDni[DNI];
		convertirFecha(auxVentasDni[FECH], dia, mes, anho);
		arch << right << setw(2) << setfill('0') << dia << '/' << setw(2) << setfill('0') << mes << '/';
		arch << setw(4) << setfill('0') << anho << setfill(' ') <<  "  ";
		arch << setw(3) << auxVentasDni[PUNT] << endl;
	}
}

void imprimirTitulo(ofstream &arch) {
	arch << setw(30) << "REPORTE DE VENTAS" << endl;
	imprimirLinea(arch, MAXLINREPVENT, '=');
}

void imprimirEncabezados(ofstream &arch) {
	arch << left << setw(12) << "CODIGO" << setw(10) << "DNI";
	arch << left << setw(10) << "FECHA" << setw(10) << "PUNTAJE" << endl;
	imprimirLinea(arch, MAXLINREPVENT, '=');
}

void convertirFecha(int fecha, int &dia, int &mes, int &anho) {
	anho = fecha / 10000;
	fecha %= 10000;
	mes = fecha / 100;
	dia = fecha % 100;
}

void imprimirLinea(ofstream &arch, int cant, char car) {
	for(int i = 0; i < cant; i++)
		arch << car;
	arch << endl;
}

void cargaLibros(char ***&libro, const char *nombArch) {
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);

	libro = nullptr;
	int numDat = 0, capacidad = 0;
	char *codigo, *nombre, *autor;
	while(1) {
		codigo = leerCadena(arch, 8, ',');
		if(arch.eof()) break;
		nombre = leerCadena(arch, 100, ',');
		autor = leerCadena(arch, 100, '\n');
		if(numDat == capacidad)
			incrementarMemoria(libro, numDat, capacidad);
		libro[numDat - 1] = insertarDatosLibro(codigo, nombre, autor);
		numDat++;
	}
	ordenarLibros(libro);
}

void incrementarMemoria(char ***&libro, int &num, int &cap) {
	char ***auxLib;
	cap += INCREMENTO;
	if(libro == nullptr) {
		libro = new char**[cap]{};
		num = 1;
	} else {
		auxLib = new char**[cap]{};
		for(int i = 0; i < num; i++)
			auxLib[i] = libro[i];
		delete libro;
		libro = auxLib;
	}
}

char **insertarDatosLibro(char *codigo, char *nombre, char *autor) {
	char **datos = new char*[3]{};
	datos[COD] = codigo;
	datos[NOMB] = nombre;
	datos[AUT] = autor;
	return datos;
}

void ordenarLibros(char ***libro) {
	int n = 0;
	while(libro[n]) n++;
	qsort(libro, n - 1, sizeof(char**), cmp_cod);
}

int cmp_cod(const void *a, const void *b) {
	void **valorA = (void**)a, **valorB = (void**)b;
	void **regA = (void**)(*valorA), **regB = (void**)(*valorB);
	char *codA = (char*)regA[COD], *codB = (char*)regB[COD];
	return strcmp(codA, codB);
}

void pruebaDeCargaDeLibros(char ***libro, const char *nombArch) {
	ofstream arch;
	AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);

	imprimirTitRepLibros(arch);
	imprimirEncabRepLibros(arch);
	char **auxLibro;
	for(int i = 0; libro[i]; i++) {
		auxLibro = libro[i];
		arch << left << setw(10) << auxLibro[COD] << setw(65) << auxLibro[NOMB];
		arch << setw(40) << auxLibro[AUT] << endl;
	}
}

void imprimirTitRepLibros(ofstream &arch) {
	arch << setw(65) << "REPORTE DE LIBROS" << endl;
	imprimirLinea(arch, MAXLINREPLIB, '=');
}

void imprimirEncabRepLibros(ofstream &arch) {
	arch << left << setw(12) << "CODIGO" << setw(65) << "NOMBRE";
	arch << left << "AUTOR" << endl;
	imprimirLinea(arch, MAXLINREPLIB, '=');
}
