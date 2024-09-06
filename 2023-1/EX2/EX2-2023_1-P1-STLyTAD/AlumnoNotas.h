/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : AlumnoNotas.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:53
 */

#ifndef ALUMNONOTAS_H
#define ALUMNONOTAS_H

#include <iomanip>
#include <fstream>
#include <vector>
#include <iterator>
#include "Nota.h"
#include "Alumno.h"
using namespace std;

class AlumnoNotas {
public:
	AlumnoNotas();
	AlumnoNotas(const AlumnoNotas &orig);
	virtual ~AlumnoNotas();
	void agregarAlumno(Alumno &alumno);
	int getCodigoDelAlumno();
	void leerNotas(ifstream &arch, int ciclo);
	void imprimir(ofstream &arch);
	void actualizarYtotalizar();
	void actualizar();
	void totalizar();
private:
	Alumno alumno;
	vector<Nota> notas;
};

#endif /* ALUMNONOTAS_H */
