#include<iostream>
#include "Router.h"

using namespace std;

int Router :: obtenerRouterOrigen(int RouterOrigen)
{
    this->RouterOrigen = RouterOrigen;
    cout<<"Router Origen"<<RouterOrigen<<endl;
    return RouterOrigen;

} 