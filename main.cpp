#include <iostream>
#include "Administrador.h"
#include "VarGlobales.h"

using namespace std;


int main()
{   Administrador administrador;
    
    //cout<<"La cantidad de Routers al principo es: "<<Routers<<endl;
    //cout<<"La cantidad de Computadoras al principio es "<<Computadoras<<endl;
    cout<<"--------Bienvenido al examen final de Algoritmos y estructuras de datos --------"<<endl;
    cout<<"En el directorio de este programa encontrara un archivo configurable llamado config.txt"<<endl;
    cout<<"Si desea modificarlo modifiquelo y luego presione enter"<<endl;
    cout<<"Recuerde que si no lo modifica y solo presiona enter el archivo quedara como la ultima vez que fue modificado"<<endl;
    cin.get();
    
    administrador.leerArchivo();

    administrador.inicializarMatrizCostos();                    
    administrador.mostrar();                                   
/*
    for(int i = 0; i < 5 ; i++ )
        administrador.crearPagina();                            // DEFINIR
     
    return 0;
*/
}