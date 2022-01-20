#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include<climits>
 
//#include<bits/stdc++.h>
#include "Administrador.h"
 
#include"VarGlobales.h"
 
 
 
#define INF 999
#define TAM_MAX_PAG 25
#define TAM_MIN_PAG 5
 
using namespace std;
 
 
 
/*Inicializamos la matriz con todos los pesos en INF, ya que no sabemos que nodos estan conectados entre si,
 La diagonal proncipal la dejamos en 0 porque estamos parados en el mismo nodo por ende el coste es 0 */
void Administrador::inicializarMatrizCostos()
{
    for(int i=0; i<100; i++){
           for (int j = 0; j < 100; j++){
                if(i==j)
                    cost[i][j] = 0;
                else
                    cost[i][j] = INF;
           }
       }
 
      
}
 
 
 
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
                    
                    
    Routers_= atoi(linea1);
    Computadoras_ = atoi(linea2);
    //Routers = Routers_;
    //Computadoras = Computadoras_;
    
    
    cout<<"Cantidad de Routers: "<<Routers_<<endl;
    cout<<"Cantidad de Computadoras "<<Computadoras_<<endl;                
                    
                    
    fclose ( fichero );
    std::ifstream archivo_conf("config.txt");
    string linea;
    while(getline(archivo_conf, linea)){
        switch(linea[0]){
        
        case('*'):
        {
            linea.erase(linea.begin());
            std::istringstream iss(linea);
        //  int origen, destino, ancho_banda;
            if (!(iss >> origen >> destino >> ancho_banda)) { 
                cout<<"Error en la lectura de la conexion de router."<<endl;
                break; 
            } 
            cout<<endl;
            cout<<"Origen -> "<<origen<<" Destino -> "<<destino<<" Ancho de banda -> "<<ancho_banda<<" Peso -> "<<TAM_MAX_PAG/ancho_banda<<endl;
            cost[origen][destino] = ancho_banda; //guardamos los valores de las conexiones en la matriz 
            
            
        }
    }
    
    }
    cout<<endl;
    cout<<"Matriz de costos "<<endl;
    cout<<endl;
       for(int i=0; i<Routers_; i++){
           
           for (int j = 0; j < Routers_; j++){
                
                   cout<< cost[i][j]<< "   "  ;
                
           }
           cout<<endl;
       }
 
 
}
 
 
 
/* \brief   Obtiene el nodo que tiene la distancia mínima. Solo tiene en cuenta
 *          los nodos que no han sido visitados
 *  \param  dist: Array de las distancias entre los nodos y el nodo source
 *  \param  visited: Nodos que han sido visitados
 *  \return Retorna el indice del nodo que tiene la menor distancia.
 * */
 
 
int Administrador :: getMin(int dist[] , bool visited[]){
    int key = 0 ;      //Indice del nodo que corresponde a la menor distancia
    int min = INT_MAX ;  //Minimo valor de distancia. Empieza en Infinito y se va disminuyendo hasta encontrar el minimo
 
    for(int i=0;i < Routers_ ; i++){   //Recorro todoo el array dist, hasta encontrar el menor
        if(!visited[i] && dist[i]<min){ //Pregunto cual es el nodo que tiene menor distancia, que no haya sido visitado
            min = dist[i] ; 
            key = i ; 
        }
    }
    return key ; 
}
 
 
/* \brief   Imprime la distancia y el camino mas corto para llegar de src a todos los nodos
*/
void Administrador :: display(int dist[] , int par[] ){
   for(int i =0 ;i < Routers_ ;i++){
       int temp = par[i] ; 
       cout<<i << " <- " ;
       while(temp!=-1)
       {
           cout<< temp << " <- " ;
           temp = par[temp] ; 
       }
       cout<<endl; 
       cout<<"::::Distance = " << dist[i] ; 
       cout<<endl; 
   } 
} 
 
 
void Administrador :: dijkstra(int src){
    int dist[100] ; //Distancia entre el nodo source y cada uno de los nodos
    int par[100];         //par[i] contiene el nodo anterior al nodo i. Para llegar al nodo i el camino mas corto es par[i] (par significa parent(nodo padre)) 
    bool visited[100] ={0} ;  //Array de nodos visitados, inicializa todos en cero (ningun nodo fue visitado)
 
    fill(dist , dist+Routers_  , INT_MAX ) ; //Setea el array dist con todos infinitos 
 
    dist[src] = 0 ;     //No hay distancia con sigo mismo
    par[src]  = -1 ;    //No tiene nodo anterior
 
    for(int g = 0  ;g<Routers_-1 ; g++){    //Analizamos todos los nodos (dentro del for se esta analizando el nodo g)
         //u es el nodo adyacente
        int u = getMin( dist, visited);     //Obtengo el indice del nodo de menor distancia  al nodo g
        visited[u] = true ;                 //Coloco este nodo como visitado
        cout<< " min = " << u <<endl; 
        //Analizo que no haya ningun nodo mejor que u
        for(int v =0 ; v< Routers_ ;v++){
            if(!visited[v] && (dist[u]+cost[u][v]) <  dist[v] && cost[u][v]!=9999)  //Pregunto si el nodo no fue visitado &&
                                                                                             //Compruebo que la distancia del nodo v(nodo adyacente (el nodo que estoy evaluando)), es mayor que la distancia del nodo u (nodo mas cercano) + el costo
                                                                                             // que tiene ir de u a v (Es decir comprueba que no te conviene ir al nodo v directamente, en lugar de ir al nodo u y de ahi al v) &&
                                                                                             //Pregunto si el nodo v es el nodo adyacente al nodo de menor distancia && C
 
            {
                par[v] = u ;                  //Le digo que u es el nodo anterior a v
                dist[v] = dist[u] + cost[u][v] ; //Corrijo la distancia que tengo al nodo v
            }
        }
    }
    
    display(dist , par) ; 
     
}
 
void Administrador :: mostrar()
{
    for (int i = 0; i < Routers_ ; i++ )
    {
        dijkstra(i);
    }
}
/*void Administrador :: mostrarEnlaces()
{
    int enlaces = 0;
    for(int i=0; i<Routers_; i++){
           
           for (int j = 0; j < Routers_; j++){
                
                  if( cost[i][j] > 0 && cost[i][j]  != INF)
                  {
                      enlaces++;
                  }
                
           }
           cout<<"La cantidad de enlaces del Router "<<i<< " son: "<<enlaces<<endl;
       }
 
}*/
 
 
 
void Administrador :: crearPagina(){
//Cada cierta cantidad de pasos de simulacion (5) se generaran paginas aleatorioas de compuatadoras aleatorias.
//
    unsigned int seed; //semilla 
    FILE* urandom = fopen("/dev/urandom", "r"); //archivo que sirve como generador de numeros aleatorios 
    fread(&seed, sizeof(int), 1, urandom);//leemos el archivo
                                          //param: la semilla, tamaño : sizeof(int),  Número de elementos, cada uno con un tamaño de bytes de tamaño,puntero al file
    fclose(urandom); //cierro el archivo
    srand(seed); //inicializamos el  generador de números pseudoaleatorios usando el argumento seed (semilla) . 
    
    //srand(time(0));
        
  
   
 
 
    int i = rand() % (Routers_);
    //srand(time(0));
    int j = rand() % (Computadoras_);//el +1 vá por definición de rand().
    int arreglo1[2]={i,j};
    cout<<"Areglo 1 "<<sizeof(arreglo1)<<endl;
     //Las direcciones  IP tienen dos partes de 1 byte cada una: la primera indica el router y la segunda la máquina terminal conectada al router
    vector<int> ip_comp_origen(arreglo1,arreglo1+sizeof(arreglo1)/sizeof(arreglo1[0]));
    //srand(time(0));
    int k = rand() % (Routers_);
    //srand(time(0));
    int l = rand() % (Computadoras_);
    int arreglo2[2]={k,l};
    cout<<"Areglo 2 "<<sizeof(arreglo2)<<endl;
    vector<int> ip_comp_destino(arreglo2,arreglo2+sizeof(arreglo2)/sizeof(arreglo2[0]));
 
    int tam_pag = TAM_MIN_PAG + rand() % ( (TAM_MAX_PAG+1) - TAM_MIN_PAG )  ;//uso (TAM_MAX_PAG+1) así el rango de valores pseudoaleatorios incluye el nro TAM_MAX_PAG
    
    Pagina nva_pag(total_pag, tam_pag, ip_comp_origen, ip_comp_destino);
    cout<<"NUEVA PAGINA CREADA: "<<endl;
    nva_pag.imprimir();
 
    total_pag++;
    
}