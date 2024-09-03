/*
 * Proyecto : EX1-2023_1-P2-PunterosMultiples
 * Archivo  : Pregunta2.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 19:00
 */

#include <cstring>
#include "Pregunta1.h"
#include "Pregunta2.h"
#include "AperturaDeArchivos.h"
using namespace std;

void cargarNotas(char ***&cursos_cod, int ***&cursos_nota_sem_veces, double **&costos,
				 int **alumnos, char ***alumnos_nom_mod, double *escalas, char ***cursos,
				 double *cursos_cred, const char *nombArch) {
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);

	int n = 0;
	while(alumnos[n]) n++;
	cursos_cod = new char**[n + 1]{};
	cursos_nota_sem_veces = new int**[n + 1]{};
	costos = new double*[n + 1]{};

	for(int i = 0; i < n; i++) {
		cursos_cod[i] = new char*[200]{};
		cursos_nota_sem_veces[i] = new int*[200]{};
		costos[i] = new double[200]{};
	}

	int cantCursos[200]{}, codAlumno, ciclo, nota, posAlumno, posCurso;
	char *codCurso, c;
	while(1) {
		arch >> codAlumno;
		if(arch.eof()) break;
		arch.get();
		codCurso = leerCadena(arch, 7, ',');
		arch >> ciclo >> c >> nota;
		posAlumno = buscarAlumno(codAlumno, alumnos);
		if(posAlumno != -1) {
			posCurso = buscarCurso(codCurso, cursos_cod[posAlumno], cantCursos[posAlumno]);
			if(posCurso != -1) {
				actualizarNota(cursos_nota_sem_veces[posAlumno], posCurso, nota, ciclo);
				actualizarCosto(costos[posAlumno], posCurso);
			} else {
				agregarCodigo(cursos_cod[posAlumno], cantCursos[posAlumno], codCurso);
				agregarNota(cursos_nota_sem_veces[posAlumno], cantCursos[posAlumno], nota, ciclo);
				agregarCosto(costos[posAlumno], cantCursos[posAlumno], posAlumno, alumnos,
							 codCurso, cursos, cursos_cred, escalas);
				cantCursos[posAlumno]++;
			}
		} else {
			while(arch.get() != '\n');
		}
	}
	int i;
//	for(i = 0; costos[i]; i++)
//		sumarCostoTotal(costos[i]);
	for(i = 0; cursos_cod[i]; i++)
		recortarMemoriaSobrante(cursos_cod[i], cursos_nota_sem_veces[i], costos[i], cantCursos[i]);
}

int buscarAlumno(int codAlumno, int **alumnos) {
	for(int i = 0; alumnos[i]; i++) {
		int *auxAlumno = alumnos[i];
		if(codAlumno == auxAlumno[0])
			return i;
	}
	return -1;
}

int buscarCurso(char *codCurso, char **cursos, int cantCursos) {
	for(int i = 0; i < cantCursos; i++)
		if(strcmp(codCurso, cursos[i]) == 0)
			return i;
	return -1;
}

void agregarCodigo(char **curso, int ind, char *codCurso) {
	curso[ind] = codCurso;
}

void agregarNota(int **curso, int ind, int nota, int ciclo) {
	curso[ind] = insertarNota(nota, ciclo);
}

int *insertarNota(int nota, int ciclo) {
	int *reg = new int[3]{};
	reg[0] = nota;
	reg[1] = ciclo;
	reg[2] = 1;
	return reg;
}

void agregarCosto(double *costos, int ind, int posAlumno, int **alumnos, char *codCur,
				  char ***cursos, double *cursos_cred, double *escalas) {
	int posCur = buscarCurso(codCur, cursos);
	if(posCur != -1) {
		int *auxAlumnos = alumnos[posAlumno];
		int indEscala = auxAlumnos[1];
		double escala = escalas[indEscala - 1];
		double creditos = cursos_cred[posCur];
		double precioTotal = creditos * escala;
		costos[ind] = precioTotal;
	}
}

int buscarCurso(char *codCur, char ***cursos) {
	char **auxCurso;
	for(int i = 0; cursos[i]; i++) {
		auxCurso = cursos[i];
		if(strcmp(codCur, auxCurso[0]) == 0)
			return i;
	}
	return -1;
}

void actualizarNota(int **curso, int posCurso, int nota, int ciclo) {
	int *auxCurso = curso[posCurso];
	if(ciclo > auxCurso[1]) {
		auxCurso[0] = nota;
		auxCurso[1] = ciclo;
	}
	auxCurso[2]++;
}

void actualizarCosto(double *costos, int posCurso) {
	costos[posCurso] *= costos[posCurso];
}

void sumarCostoTotal(double *costos) {
	int i;
	double suma = 0;
	for(i = 0; costos[i]; i++)
		suma += costos[i];
	costos[i] = suma;
}

void recortarMemoriaSobrante(char **&cursos_cod, int **&cursos_nota_sem_veces, double *&costos, int cantCursos) {
	char **auxCursoCod;
	int **auxCursosNotas;
	double *auxCostos, suma = 0;
	if(cantCursos == 0) {
		delete cursos_cod; cursos_cod = nullptr;
		delete cursos_nota_sem_veces; cursos_nota_sem_veces = nullptr;
		delete costos; costos = nullptr;
	} else {
		auxCursoCod = new char*[cantCursos + 1]{};
		auxCursosNotas = new int*[cantCursos + 1]{};
		auxCostos = new double[cantCursos + 1]{};
		for(int i = 0; i < cantCursos; i++) {
			auxCursoCod[i] = cursos_cod[i];
			auxCursosNotas[i] = cursos_nota_sem_veces[i];
			auxCostos[i] = costos[i];
			suma += costos[i];
		}
		auxCostos[cantCursos] = suma;
		delete cursos_cod; cursos_cod = auxCursoCod;
		delete cursos_nota_sem_veces; cursos_nota_sem_veces = auxCursosNotas;
		delete costos; costos = auxCostos;
	}
}

void pruebaDeCargaDeNotas(char ***cursos_cod, int ***cursos_nota_sem_veces, double **costos,
						  int **alumnos, char ***alumnos_nom_mod, const char *nombArch) {
	ofstream arch;
	AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);

	int *auxAlumnos;
	char **auxNomb;
	impEncabezadosAlumnos(arch);
	for(int i = 0; alumnos[i]; i++) {
		auxAlumnos = alumnos[i];
		auxNomb = alumnos_nom_mod[i];
		arch << right << setw(12) << auxAlumnos[0] << "  " << left << setw(45) << auxNomb[0] << endl;
		if(cursos_cod[i] != nullptr)
			imprimirCursos(arch, cursos_cod[i], cursos_nota_sem_veces[i], costos[i]);
	}
}

void imprimirCursos(ofstream &arch, char **cursos_cod, int **cursos_nota_sem_veces, double *costos) {
	int *auxCurNot, i;
	for(i = 0; cursos_cod[i]; i++) {
		auxCurNot = cursos_nota_sem_veces[i];
		arch << left << setw(10) << cursos_cod[i] << right << setw(5) << auxCurNot[0] << "  ";
		arch << setw(5) << auxCurNot[1] << setw(5) << auxCurNot[2] << setw(25) << fixed << setprecision(2) << costos[i] << endl;
	}
	arch << "TOTAL PAGADO: " << costos[i] << endl << endl;
}
