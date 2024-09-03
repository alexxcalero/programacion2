/*
 * Proyecto : EX1-2023_1-P2-PunterosMultiples
 * Archivo  : Pregunta2.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 19:00
 */

#ifndef PREGUNTA2_H
#define PREGUNTA2_H

void cargarNotas(char ***&cursos_cod, int ***&cursos_nota_sem_veces, double **&costos,
				 int **alumnos, char ***alumnos_nom_mod, double *escalas, char ***cursos,
				 double *cursos_cred, const char *nombArch);
int buscarAlumno(int codAlumno, int **alumnos);
int buscarCurso(char *codCurso, char **cursos, int cantCursos);
void agregarCodigo(char **curso, int ind, char *codCurso);
void agregarNota(int **curso, int ind, int nota, int ciclo);
int *insertarNota(int nota, int ciclo);
void agregarCosto(double *costos, int ind, int posAlumno, int **alumnos, char *codCur,
				  char ***cursos, double *cursos_cred, double *escalas);
void actualizarNota(int **curso, int posCurso, int nota, int ciclo);
int buscarCurso(char *codCur, char ***cursos);
void actualizarCosto(double *costos, int posCurso);
void sumarCostoTotal(double *costos);
void recortarMemoriaSobrante(char **&cursos_cod, int **&cursos_nota_sem_veces, double *&costos, int cantCursos);
void pruebaDeCargaDeNotas(char ***cursos_cod, int ***cursos_nota_sem_veces, double **costos,
						  int **alumnos, char ***alumnos_nom_mod, const char *nombArch);
void imprimirCursos(ofstream &arch, char **cursos_cod, int **cursos_nota_sem_veces, double *costos);

#endif /* PREGUNTA2_H */
