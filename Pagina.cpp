#include "Pagina.h"

using namespace std;

Pagina::Pagina(int id, int tamanio, int ipDestino){
	this->id = id;
	this->tamanio = tamanio;
	this->ipDestino = ipDestino;
}

Pagina::~Pagina()
{}

int Pagina::obtener_id(){
return this->id;
}

int Pagina::obtener_tamanio(){
return this->tamanio;
}

int Pagina::getIpDestino(){
	return this->ipDestino;
}

void Pagina::setIpDestino(int ipDestino){
	this->ipDestino = ipDestino;
}

/*
vector<int> Pagina::obtener_ip_comp_origen(){
return this->ip_comp_origen;
}

vector<int>  Pagina::obtener_ip_comp_destino(){
return this->ip_comp_destino;
}
*/
void Pagina::imprimir(void){
	cout<<"Pagina: "<<this->obtener_id()<<endl;
	cout<<"tamanio: "<<this->obtener_tamanio()<<endl;
	//cout<<"ip origen: "<<this->obtener_ip_comp_origen()[0]<<"--"<<this->obtener_ip_comp_origen()[1]<<endl;
	//cout<<"ip destino: "<<this->obtener_ip_comp_destino()[0]<<"--"<<this->obtener_ip_comp_destino()[1]<<endl;
}

