/*
 * Proyecto : memoria-incremental-erasmo-2archivos
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de abril de 2024, 21:36
 */

#include <iostream>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
	int *fechas;
	char **tweets, ***hashtags;
	leerTweets(fechas, tweets, "Tweets.csv");
	leerHashtags(fechas, hashtags, "Hashtags.csv");
	mostrarTweets(fechas, tweets, hashtags, "ReporteInicial.txt");
	ordenarTweets(fechas, tweets, hashtags);
	mostrarTweets(fechas, tweets, hashtags, "ReporteOrdenado.txt");
	return 0;
}
