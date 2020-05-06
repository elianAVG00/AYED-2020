#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Figuras.h"
#include "Lectura.h"

void mostrarLista (t_lectura *&o_lectura )
{
	t_lectura *actual=new t_lectura();
	actual= o_lectura;

	while(actual != NULL)
	{
		cout<<endl<<"ID: "<<actual->id<<", tipo: "<<actual->id;
		cout<<endl<<"Tipo: "<<actual->p[0]<<", Color: "<<actual->p[1];
		actual=actual->siguiente;

	}

}


void llamarContructorDeLista(int id, string tipo, string color, string valor1, string valor2, t_figura *&o_figura){
       string descripcion;
       float valor1f = convertirStringA_float(replaceNum(valor1));
       float valor2f = convertirStringA_float(replaceNum(valor2));

       if(tipo=="circulo"){
         descripcion = "Radio: "+valor1;
        constructor( id, valor1f, tipo, color, descripcion, o_figura);
       }
       if(tipo =="cubo"){
        descripcion = "Lado: "+valor1;
        constructor( id, valor1f, tipo, color, descripcion, o_figura);
       }
        if(tipo =="cilindro"){
        descripcion = "Radio: "+valor1+" Altura: "+valor2;
        constructor( id, valor1f+valor2f, tipo, color, descripcion, o_figura);
       }
       if(tipo =="rectangulo"){
        descripcion = "Base: "+valor1+" Altura: "+valor2;
        constructor( id, valor1f+valor2f, tipo, color, descripcion, o_figura);
       }
       if(tipo =="triangulo"){
        descripcion = "Base: "+valor1+" Altura: "+valor2;
        constructor( id, areaTriangulo(valor1f,valor2f), tipo, color, descripcion, o_figura);
       }
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	t_figura *o_figura=NULL;
	
	t_lectura *o_lectura = NULL;
	
	//Lectura deberia retornar un structura de lectura
    Lectura(o_lectura);
    
    
    mostrarLista(o_lectura);
}
