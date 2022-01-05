#include<iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h> 
#include <unistd.h>
#include<string.h>
#include <ctype.h>
#include"Administrador.h"
#include"VarGlobales.h"
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

                    
                    
                    
    fclose ( fichero );
}








