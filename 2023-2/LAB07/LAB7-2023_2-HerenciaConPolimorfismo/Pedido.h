/*
 * Proyecto : LAB7-2023_2-HerenciaConPolimorfismo
 * Archivo  : Pedido.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de junio de 2024, 18:16
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Pedido {
public:
	Pedido();
	Pedido(const Pedido &orig);
	virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
	void SetCodigo(const char *codigo);
    void GetCodigo(char *codigo) const;
    void SetEstado(const char *estado);
    void GetEstado(char *estado) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetSubtotal(double subtotal);
    double GetSubtotal() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
	virtual void leer(ifstream &arch);
	virtual void actualizar();
	virtual void imprimir(ofstream &arch);
	void convertirFecha(int &dia, int &mes, int &anho);
private:
	char *codigo;
	int dni_cliente;
	double subtotal;
	int fecha;
	char *estado;
	double total;
};

#endif /* PEDIDO_H */
