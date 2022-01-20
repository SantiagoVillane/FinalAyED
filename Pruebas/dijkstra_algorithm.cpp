#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include<bits/stdc++.h>


#define INF 999 
#define TAM_MAX_PAG 5
#define MIEMBRO   1
#define NO_MIEMBRO 0
using namespace std;

int cost[TAM_MAX_PAG][TAM_MAX_PAG], n ; 

int *dijkstra(int C[][TAM_MAX_PAG],int s, int t, int P[]);
void camino(int P[], int s, int t);




int main(void) { 

        int Routers;
        int Computadoras;
        int origen;
        int destino;
        int ancho_banda;

        /* Definiendo la matriz de adyacencia */
       int i, j, **A;
       for(int i=0; i<TAM_MAX_PAG; i++){
           for (int j = 0; j < TAM_MAX_PAG; j++){
                if(i==j)
                    cost[i][j] = 0;
                else
                    cost[i][j] = INF;
           }
       }

    
    FILE *fichero = fopen ( "config.txt" , "r" );
        
    const char delimitador[2] = " ";
    char cadena1 [INF];
    char cadena2 [INF];
    char *linea1;
    char *linea2;

    fgets (cadena1, INF, fichero);
    fgets (cadena2, INF, fichero);
          
    linea1 = strtok(cadena1, delimitador);
    linea1 = strtok(NULL, delimitador);
    linea2 = strtok(cadena2, delimitador);
    linea2 = strtok(NULL, delimitador);
                    
    Routers= atoi(linea1);
    Computadoras = atoi(linea2);
    
     cout<<"La cantidad de Routers es: "<<Routers<<endl;
     cout<<"La cantidad de Computadoras es: "<<Computadoras<<endl;
       /* cantidad total de nodos */
    
    std::ifstream archivo_conf("config.txt");
	string linea;
	while(getline(archivo_conf, linea)){
		switch(linea[0]){
		    case('*'):{
		    	linea.erase(linea.begin());
		    	std::istringstream iss(linea);
		    //	int origen, destino, ancho_banda;
		    	if (!(iss >> origen >> destino >> ancho_banda)) { 
		    		cout<<"Error en la lectura de la conexion de router."<<endl;
		    		break; 
		    	} 
		    	cout<<endl;
                cout<<"Origen -> "<<origen<<" Destino -> "<<destino<<" Ancho de banda -> "<<ancho_banda<<" Peso -> "<<TAM_MAX_PAG/ancho_banda<<endl;

                cost[origen][destino] = ancho_banda;        //Matriz de costos
                cout<<origen <<endl;
                cout<<destino <<endl;
		    } 
	    }
    }
    
      
   /* cout<<"Enter n : " ; 
    cin>>n ; */

    cout<<" cost matrix : \n" ; 
    for(int i = 0 ;i < Routers ; i++){
        for(int j = 0 ; j< Routers; j++)
            cout<<cost[i][j] <<"         " ; 
        cout<< endl;
    }

    int *pdist, s, t, P[TAM_MAX_PAG];

    s = 0;
    t = 4;

    pdist = dijkstra(cost, s, t, P);

    if (pdist[t]!=INF){
        cout<<"\n\n distancia minima del nodo "<<s
            <<" al nodo "<<t<<" es= "<< pdist[t];
   
        cout<<"\n\n CAMINO = ";
        camino(P,s,t);
        cout<<endl;
       
    }                

}
//    int src ; 
//    cout<<"\nEnter source : " ;  cin>>src ;
//    dijkstra(src);


int *dijkstra(int C[][TAM_MAX_PAG], int s, int t, int Pre[]){

       static int D[TAM_MAX_PAG];
       int S[TAM_MAX_PAG];
       int actual, i, k, b;
       int menordist, nuevadist;

       // inicializan las variables y se asignan
       for(i=0;i<TAM_MAX_PAG;i++){
              S[i]=NO_MIEMBRO;
              D[i]=INF;
              Pre[i]= -1;
        }//fin for

       S[s]=MIEMBRO; D[s]=0; actual=s; b=1; k=0;
       
       while((actual!=t)&&(b==1)){       
              b=0;
              menordist=INF;
              //printf("\n\n   D[%i]=%3i ",actual,D[actual]);
              
              for(i=0;i<TAM_MAX_PAG;i++){
                      //cout<<"\n  i= "<<i;                
                      if(S[i]==NO_MIEMBRO){
                             nuevadist=D[actual]+C[actual][i];
                             //printf("\n nuevadist=%3i D[%2i]=%3i ",nuevadist,i,D[i]);
                             if(nuevadist<D[i]){
                                    D[i]=nuevadist;//actual es menor que la anterior
                                    Pre[i]=actual; b=1;
                             }//fin if
                             //printf("\n menordist=%3i D[%2i]=%3i ",menordist,i,D[i]);
                             if(D[i]<menordist){
                                    menordist=D[i];
                                    k=i;  b=1;//guardo el nodo de la menor distancia
                             }//fin if
                      }//fin if
              }//fin for

              actual=k;                                 // actual se ubica en el nodo de menor distancia
              S[actual]=MIEMBRO;
              printf("\n\n         D     S     Pre");

              for(i=0;i<TAM_MAX_PAG;i++)
                       printf("\n[%2i] %5i %5i %5i     ",i,D[i], S[i],Pre[i]);
       
              //printf("\n\n   D[%i]=%3i ",actual,D[actual]);

              //system("PAUSE");
              cin.get();
       }//fin while

       return D;
}// fin dijkstra

//Funcion para imprimir el camino mas corto nodo por nodo
void camino(int P[], int s, int t){
    if(t==s)
        cout << s <<"   ";
    else{
        camino(P, s, P[t]);
        cout << t <<"   ";
    }
}

