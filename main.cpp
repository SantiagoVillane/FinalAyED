#include <iostream>
#include "Administrador.h"
#include "VarGlobales.h"

using namespace std;
int Routers;
int Computadoras;

int main()
{   Administrador administrador;
    
    //cout<<"La cantidad de Routers al principo es: "<<Routers<<endl;
    //cout<<"La cantidad de Computadoras al principio es "<<Computadoras<<endl;
    cout<<"--------Bienvenido al examen final de Algoritmos y estructuras de datos --------"<<endl;
    cout<<"En el directorio de este programa encontrara un archivo configurable llamado config.txt"<<endl;
    cout<<"Si desea modificarlo modifiquelo y luego presione enter"<<endl;
    cin.get();
    administrador.leerArchivo();
    cout<<"Cantidad de Routers: "<<Routers<<endl;
    cout<<"Cantidad de Computadoras "<<Computadoras<<endl;
    


    return 0;
}