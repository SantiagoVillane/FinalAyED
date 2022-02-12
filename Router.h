#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include "Pagina.h"
#include "Pagina.h"
#include "Cola.h"
#include "PC.h"

using namespace std;

/*
Esta clase representa los nodos de la red y opera como enrutador, 
tiene las funcionalidades de enviar y recibir paquetes así como 
recibi páginas completas desde las computadoras que están conectadas a este router. 
La recepción del paquete se realiza mediante la lectura de sus conexiones de recepción 
y el envío mediante la carga de las conexiones de envío. 
Cada router tiene una identificación entera, una colección de computadoras, 
una lista de conexiones de envío y otra de recepción, además cuenta con una tabla de enrutamiento 
que contiene las etiquetas para cada destino.
*/
class Router{
	private:
		//int RouterOrigen;
		int ip;
		int ancho_de_banda;
		Router* routersEnlazados;
		PC* pcsEnlazadaS;
		Cola colaDePaquetes;
	public:
		/*Router(int);
		~Router();	*/	
		int getIp();
		void setIp(int );
		void dividirPagina();
		void enviarPaquetes();
		void tamanioPaquetes();
		void encolarPaqueteS();
};

#endif // Paquete_H
