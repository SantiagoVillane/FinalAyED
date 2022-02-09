#include<iostream>
#include "Router.h"

using namespace std;

int Router::getIp(){
    return this->ip;
}

void Router::setIp(int ip){
    this->ip = ip;
}
