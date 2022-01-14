

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
//#include <iostream>
//#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand (para generar las paginas no implementado aun)*/
#include <time.h>       /* time */

using namespace std;
class Administrador
{
	private:
		int Routers_;
		int Computadoras_;
		int origen;
		int destino;
		int ancho_banda;
		int cost[100][100];
		
	public:
		void inicializarMatrizCostos();
		void leerArchivo();
		int calcular_tablas();
		int suma (int origen_, int destino_);
		int getMin(int dist[] , bool visited[]);
		void dijkstra(int src);
		void display(int dist[] ,int  par[]) ; 
		
};

#endif // Paquete_H

