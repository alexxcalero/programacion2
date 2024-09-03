/*
 * Proyecto : EX1-2023_1-P3-PunterosGenericos
 * Archivo  : PunterosGenericos.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 19:47
 */

#include <cstring>
#include "PunterosGenericos.h"
#include "AperturaDeArchivos.h"
#include "Pregunta1.h"
using namespace std;

void CargaCurso(int *alumnos_cod, void *&alumnoveces, const char *nombArch) {
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);

	int num = 0;
	while(alumnos_cod[num]) num++;

	void **veces = new void*[num + 1]{};
	for(int i = 0; alumnos_cod[i]; i++)
		veces[i] = agregarDatosAlumno(alumnos_cod[i]);

	int codAlumno, ciclo, nota, posAlumno, posCurso;
	char *codCurso, c;
	while(1) {
		arch >> codAlumno;
		if(arch.eof()) break;
		arch.get();
		codCurso = leerCadena(arch, 7, ',');
		arch >> ciclo >> c >> nota;
		posAlumno = buscarAlumno(codAlumno, alumnos_cod);
		if(posAlumno != -1) {
//			if(veces[posAlumno] == nullptr)
//				veces[posAlumno] = agregarDatosAlumno(codAlumno);
//			posCurso = buscarCurso(codCurso, veces[posAlumno]);
//			if(posCurso != -1) {
//				actualizarNotaCiclo(veces[posAlumno], posCurso, nota, ciclo);
//			} else {
			agregarDatosCurso(veces[posAlumno], codCurso, ciclo, nota);
//			}
		} else {
			while(arch.get() != '\n');
		}
	}
	alumnoveces = veces;
}

int buscarAlumno(int codAlumno, int *alumnos) {
	for(int i = 0; alumnos[i]; i++) {
		if(codAlumno == alumnos[i])
			return i;
	}
	return -1;
}

int buscarCurso(char *codCurso, void *alumno) {
	void **datosAlum = (void**)alumno;
	int *cantCursos = (int*)datosAlum[NUMCUR];
	int cant = *cantCursos;
	void **cursos = (void**)datosAlum[CURSOS];
	for(int i = 0; i < cant; i++) {
		char *cod = (char*)cursos[CODCUR];
		if(strcmp(codCurso, cod) == 0)
			return i;
	}
	return -1;
}

// COD, NUMCUR, NUMCURAPB, PRIMA, BIKA, TRIKA, CURSOS
void *agregarDatosAlumno(int codAlumno) {
	void **registro = new void*[7]{};
	int *codigo = new int;
	*codigo = codAlumno;
	registro[COD] = codigo;
	int *numCur = new int;
	*numCur = 0;
	registro[NUMCUR] = numCur;
	int *numCurApb = new int;
	*numCurApb = 0;
	registro[NUMCURAPB] = numCurApb;
	int *prim = new int;
	*prim = 0;
	registro[PRIMA] = prim;
	int *bik = new int;
	*bik = 0;
	registro[BIKA] = bik;
	int *trik = new int;
	*trik = 0;
	registro[TRIKA] = trik;
	registro[CURSOS] = nullptr;
	return registro;
}

void agregarDatosCurso(void *&alumno, char *codCurso, int ciclo, int nota) {
	void **datosAlum = (void**)alumno;
	int *cantCursos = (int*)datosAlum[NUMCUR];
	agregarCurso(datosAlum[CURSOS],codCurso, ciclo, nota, *cantCursos);
	(*cantCursos)++;
}

void agregarCurso(void *&cursos, char *codCurso, int ciclo, int nota, int numCur) {
	void **recCursos = (void**)cursos;
	void **auxCur = new void*[numCur + 1]{};
	if(numCur != 0) {
		for(int i = 0; i < numCur; i++)
			auxCur[i] = recCursos[i];
	}
	auxCur[numCur] = insertarDatosCurso(codCurso, ciclo, nota);
	delete recCursos;
	cursos = auxCur;
}

// CODCUR, CICLO, NOTA
void *insertarDatosCurso(char *codCurso, int ciclo, int _nota) {
	void **datos = new void*[3]{};
	datos[CODCUR] = codCurso;
	int *cic = new int;
	*cic = ciclo;
	datos[CICLO] = cic;
	int *nota = new int;
	*nota = _nota;
	datos[NOTA] = nota;
	return datos;
}

void actualizarNotaCiclo(void *alumno, int posCurso, int nota, int ciclo) {
	void **datosAlum = (void**)alumno;
	void **recCursos = (void**)datosAlum[CURSOS];
	actualizarCurso(recCursos[posCurso], nota, ciclo);
}

void actualizarCurso(void *curso, int _nota, int ciclo) {
	void **datosCur = (void**)curso;
	int *cicloCur = (int*)datosCur[CICLO];
	if(ciclo > *cicloCur) {
		*cicloCur = ciclo;
		int *nota = (int*)datosCur[NOTA];
		*nota = _nota;
	}
}

void ActualizaVeces(void *&alumnoveces) {
	void **alumnos = (void**)alumnoveces;
	for(int i = 0; alumnos[i]; i++) {
		actualizarDatos(alumnos[i]);
	}
}

// COD, NUMCUR, NUMCURAPB, PRIMA, BIKA, TRIKA, CURSOS
void actualizarDatos(void *&alumno) {
	void **datosAlum = (void**)alumno;
	int *numCur = (int*)datosAlum[NUMCUR];
	int *numCurApb = (int*)datosAlum[NUMCURAPB];
	int *prima = (int*)datosAlum[PRIMA];
	int *bika = (int*)datosAlum[BIKA];
	int *trika = (int*)datosAlum[TRIKA];
	void **cursos = (void**)datosAlum[CURSOS];
	for(int i = 0; i < (*numCur); i++)
		verificarNota(cursos, cursos[i], *numCur, *numCurApb, *prima, *bika, *trika);
}

void verificarNota(void *arrcursos, void *curso, int numCur, int &numCurApb, int &prima, int &bika, int &trika) {
	void **cursos = (void**)arrcursos;
	void **datosCur = (void**)curso;
	char *codigo = (char*)datosCur[CODCUR];
	int *nota = (int*)datosCur[NOTA];
	int cantLlevada;
	if(*nota > 10) {
		cantLlevada = 0;
		numCurApb++;
		for(int i = 0; i < numCur; i++)
			contarLlevada(cursos[i], codigo, cantLlevada);
		if(cantLlevada == 1)
			prima++;
		if(cantLlevada == 2)
			bika++;
		if(cantLlevada == 3)
			trika++;
	}
}

void contarLlevada(void *curso, char *codigo, int &cantLlevada) {
	void **datosCur = (void**)curso;
	char *codCur = (char*)datosCur[CODCUR];
	if(strcmp(codCur, codigo) == 0)
		cantLlevada++;
}
