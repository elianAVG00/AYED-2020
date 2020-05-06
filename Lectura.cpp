#include "Lectura.h"
#include "Figuras.h"
#include <list>
using namespace std;


string replaceNum(string s){
    int limite = static_cast<int>(s.size());//casteo como "int" el resultado de "palabra.size()" que es de tipo size_t (esto lo hice porque me arrojaba un warning por comparar con int en el for)
    for(int i=0; i<limite; i++)
    {
       if (s[i] == ','){
          s[i] = '.';
      }else if(s[i] == ';'){
          s[i] = '\0';
      }
    }
    return s;
}

void separarPalabras(string s, int id, t_lectura *&lectura_delinea)
{
    string aux;
    std::string delimiter = " ";
    size_t posDelimiter = 0;
    
    t_lectura *nueva_lec =  new t_lectura();
    int i=0;
	nueva_lec ->id = id;
	
    //ver info de npos http://www.cplusplus.com/reference/string/string/npos/
    while ((posDelimiter = s.find(delimiter)) != std::string::npos)//mientras la posicion del espacio (delimiter) no sea la última de la linea
    {
    	
        nueva_lec->p[i] = s.substr(0, posDelimiter);//guardo en geeks[i] los caracteres desde 0 la cantidad de "pos" caracteres
        s.erase(0, posDelimiter + delimiter.length());//Elimina del vector un solo elemento (posición) o un rango de elementos([desde, hasta]), este caso es el segundo de modo que en la vuelta siguiente la posicion 0 va a ser donde está el espacio ahora.
		i++;
    }
    
    nueva_lec->p[i] = s;
    
    t_lectura *aux1 = lectura_delinea;//1 creo una lista auxiliar y guardo los datos de lista
    lectura_delinea = nueva_lec;	  //2  los datos del nuevo nodo(nueva_figura) los guardo en la lista y el siguente de lista apunta a nuevo nodo
    nueva_lec->siguiente = aux1;	 	  //3  el siuente de nuevo nodo va a ser lo ultimo que haya en lista (la primera vez es null)

}


void Lectura(t_lectura *&o_lectura)
{
    ifstream archivo;//ifstream(tipo de variable para abrir un archivo)...  archivo (nombre de la variable)
    string texto;// variable string
    string* puntero=new string[5];
//    list<string> listaString;
    int id=0;
    archivo.open("Figuras.txt",ios::in);// con archivo.open le digo que quiero abrir un archivo (el archivo "FigurasEjemplo.txt") y con ios::in le digo que abro para leerlo

    if(archivo.fail())//si hay un error y no se abre el arvhivo
    {
        cout<<"No se ha podido abrir archivo"<<endl;//se muestra
        exit(1);//sale
    }

     //si se abre
    while(!archivo.eof())//mientras no sea el final del archivo
    {  
		id++;
        getline(archivo,texto);//Tomo lo que va encontrando (por linea, creo) en "archivo" y lo copio en "texto"
        //Mando un puntero a un vector y toda lo copiado (la linea) a separarlo (para guardar en las distintas posiciones del vector)
        separarPalabras(texto, id, o_lectura);
        
    }
      archivo.close();//cerramos archivo

}

float convertirStringA_float(string variableString){

	char *str=const_cast< char *>(variableString.c_str());//castea string a char arrays
	float num;
    num = atof(str);//es como un atoi pero f de float
	return num;
}
