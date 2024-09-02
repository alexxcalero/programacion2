/*
 * Proyecto : memoria-exacta-erasmo-2archivos
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 9 de abril de 2024, 15:58
 */

#include <iostream>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
	int *fechas;
	char **tweets, ***hashtags;
	leerTweets(fechas, tweets, "Tweets.csv");
//	for(int i = 0; fechas[i]; i++)
//		cout << fechas[i] << " " << tweets[i] << endl;
	leerHashtags(fechas, hashtags, "Hashtags.csv");
	imprimirReporte(fechas, tweets, hashtags, "ReporteDeTweets.txt");
	return 0;
}
