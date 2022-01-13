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
#define TAM_MAX_PAG 25
using namespace std;

int cost[100][100], n ; 

int getMin(int dist[] , bool visited[]){
    int key = 0 ; 
    int min = INT_MAX ;

    for(int i=0;i < n ; i++){
        if(!visited[i] && dist[i]<min){
            min = dist[i] ; 
            key = i ; 
        }
    }

    return key ; 
}

void display(int dist[] , int par[] ){
   for(int i =0 ;i < n ;i++){
       int temp = par[i] ; 
       cout<<i << " <- " ;
       
       while(temp!=-1){
           cout<< temp << " <- " ;
           temp = par[temp] ; 
       }
       cout<<endl; 
       cout<<"::::Distance = " << dist[i] ; 
       cout<<endl; 
   } 
}


void dijkstra(int src ){
    int par[100] , dist[100] ; 
    bool visited[100] ={0} ; 
    fill(dist , dist+n  , INT_MAX ) ; 

    dist[src] =0 ; 
    par[src] =-1 ;
    
    for(int g = 0  ;g<n-1 ; g++){
        int u = getMin( dist ,  visited )  ; 
        visited[u] = true ;
        cout<< " min = " << u <<endl; 
        for(int v =0 ; v< n ;v++){
            if(!visited[v] && (dist[u]+cost[u][v]) <  dist[v] && cost[u][v]!=9999)
            {
                par[v] = u ; 
                dist[v] = dist[u] + cost[u][v] ; 
            }
        }
    }
    
    display(dist , par) ; 
}



int main(void) { 

        int Routers;
        int Computadoras;
        int origen;
        int destino;
        int ancho_banda;
        
        /* Definiendo la matriz de adyacencia */
       int i, j, **A;
       for(int i=0; i<100; i++){
           for (int j = 0; j < 100; j++){
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
        
          
        /*
       for ( i = 0; i < Routers; i++ )
        {
            //cout<<"el valor de i es: "<<i<<endl;
          for ( j = 0; j < Routers; j++ )
          {
             // cout<<"el valor de j es: "<<j<<endl;
              if(i == origen && j== destino)
              {
                  cout<<"Estoy en el if"<<endl;
                  cout<<"El valor de i es: "<<i<<endl;
                  cout<<"El valor de origen es: "<<origen<<endl;
                   cout<<endl;
                  cout<<"El valor de j es: "<<j<<endl;
                  cout<<"El valor de destino es: "<<destino<<endl;
                  cout<<"El valor del ancho de banda es: "<<ancho_banda<<endl;
                  cost[i][j]=ancho_banda;
                  cout<<"Mostrando matriz"<<endl;

                  cout<<cost[i][j]<<endl;
              }
              else if(i ==j){
                  cout<<"i deberia ser igual a a j "<<i<<" Igual a "<<j<<endl;
                  cost[i][j]=0;
                  cout<<"Mostrando matriz"<<endl;

                  cout<<cost[i][j]<<endl;
                  
              }
              else{
                  cost[i][j]=INF;
              }
            
        }
        */
            cost[origen][destino] = ancho_banda;
            cout<<origen <<endl;
            cout<<destino <<endl;

		//break;
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
}
//    int src ; 
  //  cout<<"\nEnter source : " ;  cin>>src ;
    // dijkstra(src);



