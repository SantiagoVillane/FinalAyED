#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
//#include <iostream>
//#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand (para generar las paginas no implementado aun)*/
#include <time.h>       /* time */

#include "Pagina.h"
#include "Router.h"
using namespace std;
class Administrador
{
	private:
		int Routers_;
		int Computadoras_;
		int origen;
		int destino;
		int ancho_banda;
		int total_pag;
		int cost[5][5];
		
	public:
		void inicializarMatrizCostos();
		void leerArchivo();
		int getMin(int dist[] , bool visited[]);
		void dijkstra1(int src);
		int *dijkstra(int C[][5],int s, int t, int P[]);
		void camino(int P[], int s, int t);
		void display(int dist[] ,int  par[]) ; 
		void mostrar();
		void crearPagina();
		void mostrarEnlaces();
		void recomputarRutas();
};

#endif // Paquete_H

