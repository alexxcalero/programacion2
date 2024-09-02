/*
 * Proyecto : memoria-incremental-erasmo-2archivos
 * Archivo  : funciones.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de abril de 2024, 23:25
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
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}

	int cantDatos = 0, capacidad = 0, fech;
	char* tweet;
	fechas = nullptr;
	tweets = nullptr;

	while(true){
		arch >> fech;
		if(arch.eof()) break;
		arch.get();  // Leo la coma
		tweet = leerCadena(arch, 100, '\n');
		if(capacidad == cantDatos)  // Agregar memoria por incrementos
			incrementarMemoria(fechas, tweets, cantDatos, capacidad);
		fechas[cantDatos - 1] = fech;
		tweets[cantDatos - 1] = tweet;
		cantDatos++;
	}
}

char *leerCadena(ifstream &arch, int size, char delim) {
	char cadena[size], *cad;
	arch.getline(cadena, size, delim);
	cad = new char[strlen(cadena) + 1];
	strcpy(cad, cadena);
	return cad;
}

void incrementarMemoria(int *&fechas, char **&tweets, int &cantDatos, int &capacidad) {
	int *auxFechas;
	char **auxTweets;
	capacidad += INCREMENTO;
	if(fechas == nullptr) {
		fechas = new int[capacidad]{};
		tweets = new char*[capacidad]{};
		cantDatos = 1;
	} else {
		auxFechas = new int[capacidad]{};
		auxTweets = new char*[capacidad]{};
		for(int i = 0; i < cantDatos; i++) {
			auxFechas[i] = fechas[i];
			auxTweets[i] = tweets[i];
		}
		delete fechas;
		delete tweets;
		fechas = auxFechas;
		tweets = auxTweets;
	}
}

void leerHashtags(int *fechas, char ***&hashtags, const char *nombArch) {
	ifstream arch(nombArch, ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}

	int pos, cantDatos = 0, cantHashtagsFila[20]{}, capacidadFila[20]{}, fech;
	while(fechas[cantDatos])cantDatos++;
	hashtags = new char**[cantDatos + 1]{};

	while(true) {
		arch >> fech;
		if(arch.eof()) break;
		arch.get();  // Leo la coma
		pos = buscarTweet(fech, fechas);
		if(pos != -1)
			agregarHashtags(arch, hashtags[pos], cantHashtagsFila[pos], capacidadFila[pos]);
		else
			while(arch.get() != '\n');
	}
}

int buscarTweet(int fecha, int *fechas) {
	for(int i = 0; fechas[i]; i++)
		if(fechas[i] == fecha)
			return i;
	return -1;
}

void agregarHashtags(ifstream &arch, char **&hashtags, int &cantHashtags, int &capacidadFila) {
	char *hashtag;
	hashtag = leerCadena(arch, 100, '\n');
	if(cantHashtags == capacidadFila)
		incrementarMemoria(hashtags, cantHashtags, capacidadFila);
	hashtags[cantHashtags - 1] = hashtag;
	cantHashtags++;
}

void incrementarMemoria(char **&hashtags, int &cantidad, int &capacidad) {
	char **auxHashtags;
	capacidad += INCREMENTO;
	if(hashtags == nullptr){
		hashtags = new char*[capacidad]{};
		cantidad = 1;
	} else {
		auxHashtags = new char*[capacidad]{};
		for(int i = 0; i < cantidad; i++) {
			auxHashtags[i] = hashtags[i];
		}
		delete hashtags;
		hashtags = auxHashtags;
    }
}

void mostrarTweets(int *fechas, char **tweets, char ***hashtags, const char *nombArch) {
	ofstream arch(nombArch, ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
		exit(1);
	}
	for(int i = 0; fechas[i]; i++) {
		arch << left << setw(10) << fechas[i] << tweets[i] << endl;
		if(hashtags[i]) {
			arch << "Hashtags incluidos:\n";
			mostrarHashtags(arch, hashtags[i]);
		}
		else
			arch << "No tiene hashtags\n";
    }
}

void mostrarHashtags(ofstream &arch, char **hashtags) {
	for(int i = 0; hashtags[i]; i++)
		arch << setw (20) << " " << hashtags[i] << endl;
}

void ordenarTweets(int *fechas, char **tweets, char ***hashtags) {
	int cant = 0;
	while(fechas[cant]) cant++;
	quickSort(fechas, tweets, hashtags, 0 /*Indice izquierdo*/, cant - 1 /*indice derecho*/);
}

void quickSort(int *fechas, char **tweets, char ***hashtags, int izq, int der) {
	int limite, pivote;
	if(izq >= der) return;
	pivote = (izq + der) / 2;
	swap2(fechas[izq], fechas[pivote], tweets[izq], tweets[pivote], hashtags[izq], hashtags[pivote]);
	limite = izq;
	for(int i = izq + 1; i <= der; i++) {
		if(strcmp(tweets[i], tweets[izq]) < 0) { //Alfabeticamente tweets
			limite++;
			swap2(fechas[limite], fechas[i], tweets[limite], tweets[i], hashtags[limite], hashtags[i]);
		}
	}
	swap2(fechas[limite], fechas[izq], tweets[limite], tweets[izq], hashtags[limite], hashtags[izq]);
	quickSort(fechas, tweets, hashtags, izq, limite - 1);
	quickSort(fechas, tweets, hashtags, limite + 1, der);
}

void swap2(int &fecha1, int &fecha2, char *&tweet1, char*&tweet2, char**&hashtags1, char**&hashtags2) {
	int auxFecha;
	char *auxTweet;
	char **auxHashtags;

	auxFecha = fecha1;
	fecha1 = fecha2;
	fecha2 = auxFecha;

	auxTweet = tweet1;
	tweet1 = tweet2;
	tweet2 = auxTweet;

	auxHashtags = hashtags1;
	hashtags1 = hashtags2;
	hashtags2 = auxHashtags;
}
