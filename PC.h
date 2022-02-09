#ifndef PC_H
#define PC_H
#include <iostream>
#include "Router.h"

using namespace std;

class PC{
    private:
        int ip;
        Router* routerTerminal;
        Pagina colaPaginas;

    public:
        void setIp(int ip){this->ip = ip;}
        int getIp(){return this->ip;}
        Pagina enviarPagina();

};

#endif