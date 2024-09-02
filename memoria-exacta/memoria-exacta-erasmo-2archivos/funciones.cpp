/*
 * Proyecto : memoria-exacta-erasmo-2archivos
 * Archivo  : funciones.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 9 de abril de 2024, 15:58
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.h"
using namespace std;

void leerTweets(int *&fechas, char **&tweets, const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el achivo " << nombArch << endl;
		exit(1);
	}
	int buffFechas[20]{};
	char *buffTweets[20]{};
	int fech, cantDatos = 0;
	while(true) {
		arch >> fech;
		if(arch.eof()) break;
		arch.get();
		buffFechas[cantDatos] = fech;
		buffTweets[cantDatos] = leerCadena(arch);
		cantDatos++;
	}
	fechas = new int[cantDatos + 1]{};
	tweets = new char*[cantDatos + 1]{};
	for(int i = 0; i < cantDatos; i++) {
		fechas[i] = buffFechas[i];
		tweets[i] = buffTweets[i];
	}
}

char *leerCadena(ifstream &arch) {
	char cadena[100], *cad;
	arch.get(cadena, 100);
	cad = new char[strlen(cadena) + 1];
	strcpy(cad, cadena);
	return cad;
}

void leerHashtags(int *fechas, char ***&hashtags, const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	int fech, pos, cantDatos = 0;

	int cantHash[20]{};  // Cantidad de hashtags de cada tweet (fila)

	while(fechas[cantDatos]) cantDatos++;  // Cuento el total exacto de tweets (filas)
	hashtags = new char**[cantDatos + 1]{};  // Creo la cantidad total de hashtags

	// Para cada fila estimo un valor de hashtags
	for(int i = 0; i < cantDatos; i++) hashtags[i] = new char*[20]{};

	while(true) {
		arch >> fech;
		if(arch.eof()) break;
		arch.get();  // Leo la coma
		pos = buscarTweet(fech, fechas);
		if(pos == -1)
			while(arch.get() != '\n');  // Descarto la linea
		else {
			colocarHashtag(arch, hashtags[pos], cantHash[pos]);
		}
	}

	// Coloco en memoria exacta la cantidad de hashtags
	for(int i = 0; hashtags[i]; i++)
		memoriaExactaDeHashtags(hashtags[i],cantHash[i]);
}

int buscarTweet(int f, int *fechas) {
	for(int i = 0; fechas[i]; i++)
		if(fechas[i] == f)
			return i;
	return -1;
}

void colocarHashtag(ifstream &arch, char **hashtags, int &cant) {
	char *hash = leerCadena(arch);
	hashtags[cant] = hash;
	cant++;
}

void memoriaExactaDeHashtags(char **&hashtags, int cantHash) {
	char **nuevosHashtags;
	if(cantHash == 0) {
		delete hashtags;
		hashtags = nullptr;
	} else {
		nuevosHashtags = new char*[cantHash + 1]{};
		for(int i = 0; i < cantHash; i++)
			nuevosHashtags[i] = hashtags[i];
		delete hashtags;
		hashtags = nuevosHashtags;
	}
}

void imprimirReporte(int *fechas, char **tweets, char ***hashtags, const char *nombArch) {
	ofstream arch(nombArch, ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el achivo " << nombArch << endl;
		exit(1);
	}
	for(int i = 0; fechas[i]; i++) {
		arch << left << setw(10) << fechas[i] << tweets[i];
		arch << "\nHashtags incluidos:\n";
		mostrarHashtags(hashtags[i], arch);
	}
}

void mostrarHashtags(char **hashtags, ofstream &arch) {
	for(int i = 0; hashtags[i]; i++) {
		arch << setw(20) << " " << hashtags[i] << endl;
	}
	arch << endl;
}
