/*
 * Proyecto : EX1-2023_1-P3-PunterosGenericos
 * Archivo  : PunterosGenericos.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 19:47
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

enum Registro {COD, NUMCUR, NUMCURAPB, PRIMA, BIKA, TRIKA, CURSOS};
enum Cursos {CODCUR, CICLO, NOTA};

void CargaCurso(int *alumnos_cod, void *&alumnoveces, const char *nombArch);
int buscarAlumno(int codAlumno, int *alumnos);
int buscarCurso(char *codCurso, void *registro);
void *agregarDatosAlumno(int codAlumno);
void agregarDatosCurso(void *&alumno, char *codCurso, int ciclo, int nota);
void agregarCurso(void *&cursos, char *codCurso, int ciclo, int nota, int numCur);
void *insertarDatosCurso(char *codCurso, int ciclo, int _nota);
void actualizarNotaCiclo(void *alumno, int posCurso, int nota, int ciclo);
void actualizarCurso(void *curso, int _nota, int ciclo);
void ActualizaVeces(void *&alumnoveces);
void actualizarDatos(void *&alumno);
void verificarNota(void *arrcursos, void *curso, int numCur, int &numCurApb, int &prima, int &bika, int &trika);
void contarLlevada(void *curso, char *codigo, int &cantLlevada);

#endif /* PUNTEROSGENERICOS_H */
