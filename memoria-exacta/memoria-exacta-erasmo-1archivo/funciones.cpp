/*
 * Proyecto : memoria-exacta-erasmo-1archivo
 * Archivo  : funciones.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 9 de abril de 2024, 15:12
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.h"
using namespace std;

void leerTweets(int *&fechas, char **&tweets, char ***&hashtags, const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	int buffFechas[20]{};
	char *buffTweets[20]{}, **buffHashtags[20]{};
	int fech, cantDatos = 0;
	while(true) {
		arch >> fech;
		if(arch.eof()) break;
		arch.get();  // Leo la coma
		buffFechas[cantDatos] = fech;
		buffTweets[cantDatos] = leerCadena(arch);
		buffHashtags[cantDatos] = leerHashtag(arch);
		cantDatos++;
	}
	fechas = new int[cantDatos + 1]{};
	tweets = new char*[cantDatos + 1]{};
	hashtags = new char**[cantDatos + 1]{};
	for(int i = 0; i < cantDatos; i++) {
		fechas[i] = buffFechas[i];
		tweets[i] = buffTweets[i];
		hashtags[i] = buffHashtags[i];
	}
}

char *leerCadena(ifstream &arch) {
	char cadena[100], *cad;
	arch.getline(cadena, 100, ',');
	cad = new char[strlen(cadena) + 1];
	strcpy(cad, cadena);
	return cad;
}

char **leerHashtag(ifstream &arch) {
	char *buffHash[20]{}, **hashtags;
	int cant = 0;
	while(true) {
		buffHash[cant] = leerUnSoloHashtag(arch);
		cant++;
		if(arch.get() == '\n') break;
	}
	hashtags = new char*[cant + 1]{};
	for(int i = 0; i < cant; i++)
		hashtags[i] = buffHash[i];
	return hashtags;
}

char *leerUnSoloHashtag(ifstream &arch) {
	char *hash = new char[8];
	arch.get(hash, 8);
	return hash;
}

void mostrarTweets(int *fechas, char **tweets, char ***hashtags, const char *nombArch) {
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
		arch << right << setw(27) << hashtags[i] << endl;
	}
	arch << endl;
}
