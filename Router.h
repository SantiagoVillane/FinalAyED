#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>

#include "Pagina.h"


using namespace std;

/*
Esta clase representa los nodos de la red y opera como enrutador, tiene las funcionalidades de enviar y recibir paquetes así como recibi páginas completas desde las computadoras que están conectadas a este router. La recepción del paquete se realiza mediante la lectura de sus conexiones de recepción y el envío mediante la carga de las conexiones de envío. Cada router tiene una identificación entera, una colección de computadoras, una lista de conexiones de envío y otra de recepción, además cuenta con una tabla de enrutamiento que contiene las etiquetas para cada destino.
*/
class Router
{
	private:
		int RouterOrigen;
		
	public:
		/*Router(int);
		~Router();	*/	
		int obtenerRouterOrigen(int RouterOrigen);
};

#endif // Paquete_H
