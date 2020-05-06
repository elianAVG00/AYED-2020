#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>

using namespace std;

struct t_lectura{
	int id;
	string p[5];//tipo-color-radio-lado1-lado2
	t_lectura *siguiente;
};

struct t_figura;
void mostrarLista (t_figura *&ptrfigura);
void separarPalabras(string s, int id, t_lectura*& lectura_delinea);
int ContarPalabras(string palabra);
void Lectura(t_lectura *&o_lectura);
//void buscarFigura(*&t_lectura o_lectura);
string replaceNum(string s);
float convertirStringA_float(string variableString);
void llamarContructorDeLista(int id, string tipo, string color, string valor1, string valor2, t_figura *&o_figura);

#endif // LECTURA_H_INCLUDED
