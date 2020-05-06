#ifndef FIGURAS_H_INCLUDED
#define FIGURAS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


/* material=area */

struct t_figura;//al  poner paso como parametro "t_figura *&lista"...  tambien puedo definir un puntero de tipo "t_figura" así "typedef struct t_figura *ptr_t_Figura" y pasar como parametro "ptr_t_Figura" con o sin nombre de variable

void constructor(int id, float area,string tipo,string color,string texto, t_figura *&lista);
void setId(int &id_global,t_figura *&ptrfigura);
float getId(t_figura *&ptrfigura);
void setArea(float area_calculada, t_figura *&ptrfigura);
float getArea(t_figura *&ptrfigura);
void setColor(string colorinput, t_figura *&ptrfigura);
string getColor(t_figura *&ptrfigura);
void setDescripcion(string texto, t_figura *&ptrfigura);
string getDescripcion(t_figura *&ptrfigura);
void setTipo(string inputTipo, t_figura *&ptrfigura);
string getTipo(t_figura *&ptrfigura);



float areaCirculo(float radio); //mati
float areaCubo(float lado); //franco astorga
float areaCilindro(float radio,float altura);//franco aguirre
float areaRectangulo(float base, float altura);//chino
float areaTriangulo(float base, float altura);//sergio


void totalfigura(t_figura *&ptrfigura);//franco astorga
void totalfiguracolor(t_figura *&ptrfigura);//franco aguirre
void mostrarOrdenProduccionPorColor(t_figura *&ptrfigura);//chino
void mostrarOrdenPorArea(t_figura *&ptrfigura);//mati


//



/*a desarrollar:
Una vez que termina un lote de producción (cada archivo es un lote), se necesita saber para
cada figura:
Que ​ Tipo de Figura ​ es: if(*p[0]=="cilindro") cout<<"es un cilindro"--- se resuelve getTipo()
Que ​ Color ​ posee.        							     getColor();
Que ​ Cantidad de Plástico ​ se usó (sería la suma de las áreas de las figuras): 	     get area();
Además, se necesitan saber:
○ Los ​ Totales ​ por Figura

+ total por Figura-Color.

sergio lectura y llamaria a los constructores
cada uno hace un constructor






*/



#endif // FIGURAS_H_INCLUDED
