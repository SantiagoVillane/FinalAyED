#ifndef PAGINA_H
#define PAGINA_H
#include <vector>
#include <iostream>
/*
Esta clase representa las páginas que generan las computadoras 
y que contiene una identificación 
su tamaño en cantidad de paquetes y las direcciones de origen 
y de destino en forma de duplas de enteros.
*/

using namespace std;

class Pagina{
	private:
		int id;				//número de la página.
		int tamanio;		//tamaño de la página en cantidad de paquetes
		int ipDestino;		//ip de la computadora donde debe ser enviada la pagina
		//vector<int> ip_comp_origen;//ip pc y router origen
		//vector<int> ip_comp_destino;//ip pc y router destino
		
	public:		
		Pagina(int, int, int);
		~Pagina();
		int obtener_id();
		int obtener_tamanio();
		int getIpDestino();
		void setIpDestino(int ipDestino);
		std::vector<int> obtener_ip_comp_origen();
		std::vector<int> obtener_ip_comp_destino();
		void imprimir(void);
};

#endif // Pagina_H

