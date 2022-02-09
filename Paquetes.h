#ifndef PAQUETE_H
#define PAQUETE_H
#include <iostream>
//#include "Pagina.h"

using namespace std;

class Paquete{
    private:
        int ipOrigen;
        int ipDestino;
        int tamanio;
        int camino[];

    public:
        void setIpOrigen(int ipOrigen) {this->ipOrigen = ipOrigen; }
        void setIpDestino(int ipDestino) {this->ipDestino = ipDestino; }
        void setTamanio(int tamanio) { this->tamanio = tamanio; }
        void setCamino(int camino[]) { this->camino = camino; }
        int getIpOrigen(){ return this->ipOrigen; }
        int getIpDestino(){ return this->ipDestino; }
        int getTamanio(){ return this->tamanio; }
        int getCamino(){ return this->camino; }

};

#endif