/*
 * Proyecto : EX1-2023_1-P1-PunterosMultiples
 * Archivo  : Pregunta1.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 18:27
 */

#include <iomanip>
#include <fstream>
#include <cstring>
#include "Pregunta1.h"
#include "AperturaDeArchivos.h"
using namespace std;

void cargarCursosYEscalas(char ***&cursos, double *&cursos_cred, double *escalas, const char *nombArchCur, const char *nombArchEsc) {
	ifstream archCur;
	ifstream archEsc;
	AperturaDeUnArchivoDeTextosParaLeer(archCur, nombArchCur);
	AperturaDeUnArchivoDeTextosParaLeer(archEsc, nombArchEsc);

	int n;
	double esc;
	char c;
	while(1) {
		archEsc >> c;
		if(archEsc.eof()) break;
		archEsc >> n >> c >> esc;
		escalas[n - 1] = esc;
	}

	cursos = nullptr; cursos_cred = nullptr;
	int numDat = 0, capacidad = 0, codProf;
	char *codigo, *nombre, *profesor;
	double cred;
	while(1) {
		codigo = leerCadena(archCur, 7, ',');
		if(archCur.eof()) break;
		nombre = leerCadena(archCur, 60, ',');
		archCur >> cred >> c >> codProf >> c;
		profesor = leerCadena(archCur, 60, '\n');
		if(numDat == capacidad)
			incrementarMemoria(cursos, cursos_cred, numDat, capacidad);
		cursos_cred[numDat - 1] = cred;
		cursos[numDat - 1] = insertarDatosCurso(codigo, nombre, profesor);
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

void incrementarMemoria(char ***&cursos, double *&cursos_cred, int &num, int &cap) {
	char ***auxCur;
	double *auxCred;
	cap += INCREMENTO;
	if(cursos == nullptr) {
		cursos = new char**[cap]{};
		cursos_cred = new double[cap]{};
		num = 1;
	} else {
		auxCur = new char**[cap]{};
		auxCred = new double[cap]{};
		for(int i = 0; i < num; i++) {
			auxCur[i] = cursos[i];
			auxCred[i] = cursos_cred[i];
		}
		delete cursos; delete cursos_cred;
		cursos = auxCur; cursos_cred = auxCred;
	}
}

char **insertarDatosCurso(char *codigo, char *nombre, char *profesor) {
	char **curso = new char*[3]{};
	curso[0] = codigo;
	curso[1] = nombre;
	curso[2] = profesor;
	return curso;
}

void pruebaDeCargaDeCursos(char ***cursos, double *cursos_cred, const char *nombArch) {
	ofstream arch;
	AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);

	impEncabezados(arch);
	char **auxCur;
	for(int i = 0; cursos[i]; i++) {
		auxCur = cursos[i];
		arch << left << setw(10) << auxCur[0] << setw(60) << auxCur[1];
		arch << right << setw(5) << cursos_cred[i] << "   " << auxCur[2] << endl;
	}
}

void impEncabezados(ofstream &arch) {
	arch << left << setw(14) << "CODIGO" << setw(55) << "NOMBRE";
	arch << setw(10) << "CODIGO" << "PROFESOR" << endl;
	impLinea(arch, '-');
}

void impLinea(ofstream &arch, char c) {
	for(int i = 0; i < MAXLIN; i++)
		arch << c;
	arch << endl;
}

void cargarAlumnos(int *&alumnos_cod, int **&alumnos, char ***&alumnos_nom_mod, const char *nombArch) {
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);

	alumnos_cod = nullptr;

	int numDat = 0, capacidad = 0, cod, porc, n;
	char *nombre, mod, c;
	while(1) {
		arch >> cod;
		if(arch.eof()) break;
		arch.get();
		nombre = leerCadena(arch, 60, ',');
		mod = arch.get();
		if(mod == 'S') {
			arch >> c >> porc >> c >> c >> n;
		} else if(mod == 'V') {
			arch >> c >> c >> n;
		} else {
			arch >> n;
		}
		if(numDat == capacidad)
			incrementarMemoria(alumnos_cod, alumnos, alumnos_nom_mod, numDat, capacidad);
		alumnos_cod[numDat - 1] = cod;
		alumnos[numDat - 1] = insertarDatosAlumno(cod, n, mod, porc);
		alumnos_nom_mod[numDat - 1] = insertarNombreAlumno(nombre, mod);
		numDat++;
	}
}

void incrementarMemoria(int *&alumnos_cod, int **&alumnos, char ***&alumnos_nom_mod, int &num, int &cap) {
	int *auxCodigos, **auxAlumnos;
	char ***auxNombres;
	cap += INCREMENTO;
	if(alumnos_cod == nullptr) {
		alumnos_cod = new int[cap]{};
		alumnos = new int*[cap]{};
		alumnos_nom_mod = new char**[cap]{};
		num = 1;
	} else {
		auxCodigos = new int[cap]{};
		auxAlumnos = new int*[cap]{};
		auxNombres = new char**[cap]{};
		for(int i = 0; i < num; i++) {
			auxCodigos[i] = alumnos_cod[i];
			auxAlumnos[i] = alumnos[i];
			auxNombres[i] = alumnos_nom_mod[i];
		}
		delete alumnos_cod; delete alumnos; delete alumnos_nom_mod;
		alumnos_cod = auxCodigos; alumnos = auxAlumnos; alumnos_nom_mod = auxNombres;
	}
}

int *insertarDatosAlumno(int cod, int escala, char modalidad, int porcentaje) {
	int *datos;
	if(modalidad == 'S') {
		datos = new int[3]{};
		datos[0] = cod;
		datos[1] = escala;
		datos[2] = porcentaje;
	} else {
		datos = new int[2]{};
		datos[0] = cod;
		datos[1] = escala;
	}
	return datos;
}

char **insertarNombreAlumno(char *nombre, char modalidad) {
	char **datos = new char*[2]{};
	datos[0] = nombre;
	char *mod = new char;
	if(modalidad != 'S' && modalidad != 'V') *mod = 'P';
	else *mod = modalidad;
	datos[1] = mod;
	return datos;
}

void pruebaDeCargaDeAlumnos(int *alumnos_cod, int **alumnos, char ***alumnos_nom_mod, const char *nombArch) {
	ofstream arch;
	AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);

	int *auxAlumnos;
	char **auxNomb;
	impEncabezadosAlumnos(arch);
	for(int i = 0; alumnos_cod[i]; i++) {
		auxAlumnos = alumnos[i];
		auxNomb = alumnos_nom_mod[i];
		arch << right << setw(12) << auxAlumnos[0] << "  " << left << setw(45) << auxNomb[0];
		arch << setw(10) << auxNomb[1] << "G" << setw(10) << auxAlumnos[1];
		if(strcmp(auxNomb[1], "S") == 0)
			arch << setw(5) << auxAlumnos[2];
		arch << endl;
	}
}

void impEncabezadosAlumnos(ofstream &arch) {
	arch << right << setw(11) << "CODIGO" << "     " << left << setw(40) << "NOMBRE";
	arch << "MODALIDAD" << "  ESCALA" << "   PORCENTAJE" << endl;
	impLinea(arch, '-');
}
