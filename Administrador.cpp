#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

#include "Administrador.h"
#include"VarGlobales.h"


#define INF 9999
#define TAM_MAX_PAG 25
#define TAM_MIN_PAG 5

using namespace std;

void Administrador :: leerArchivo()
{
    FILE *fichero = fopen ( "config.txt" , "r" );
        
    const char delimitador[2] = " ";
    char cadena1 [200];
    char cadena2 [200];
    char *linea1;
    char *linea2;

    
    
        
    
       
    fgets (cadena1, 200, fichero);
    fgets (cadena2, 200, fichero);
       
           
    linea1 = strtok(cadena1, delimitador);
    linea1 = strtok(NULL, delimitador);
    linea2 = strtok(cadena2, delimitador);
    linea2 = strtok(NULL, delimitador);
                    
                    
    Routers_ = atoi(linea1);
    Computadoras_ = atoi(linea2);
    Routers = Routers_;
    Computadoras = Computadoras_;
    
    
    cout<<"Cantidad de Routers: "<<Routers<<endl;
    cout<<"Cantidad de Computadoras "<<Computadoras<<endl;                
                    
                    
    fclose ( fichero );
    std::ifstream archivo_conf("config.txt");
	string linea;
	while(getline(archivo_conf, linea)){
		switch(linea[0]){
		
		case('*'):
		{
			linea.erase(linea.begin());
			std::istringstream iss(linea);
		//	int origen, destino, ancho_banda;
			if (!(iss >> origen >> destino >> ancho_banda)) { 
				cout<<"Error en la lectura de la conexion de router."<<endl;
				break; 
			} 
			cout<<endl;
            cout<<"Origen -> "<<origen<<" Destino -> "<<destino<<" Ancho de banda -> "<<ancho_banda<<" Peso -> "<<TAM_MAX_PAG/ancho_banda<<endl;
            
		break;
		}
	}
    


}
