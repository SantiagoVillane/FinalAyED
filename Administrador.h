

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
//#include <iostream>
//#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand (para generar las paginas no implementado aun)*/
#include <time.h>       /* time */

#include "Pagina.h"
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
		int cost[100][100];
		
	public:
		void inicializarMatrizCostos();
		void leerArchivo();
		int getMin(int dist[] , bool visited[]);
		void dijkstra(int src);
		void display(int dist[] ,int  par[]) ; 
		void mostrar();
		void crearPagina();
		void mostrarEnlaces();
};

#endif // Paquete_H

