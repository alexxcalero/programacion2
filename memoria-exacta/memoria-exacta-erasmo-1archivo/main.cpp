/*
 * Proyecto : memoria-exacta-erasmo-1archivo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 9 de abril de 2024, 15:12
 */

#include <iostream>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
	int *fechas;
	char **tweets, ***hashtags;
	leerTweets(fechas, tweets, hashtags, "Tweets.csv");
	mostrarTweets(fechas, tweets, hashtags, "ReporteDeTweets.txt");
	return 0;
}
