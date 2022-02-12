#ifndef COLA_H
#define COLA_H
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class Nodo {
private:
    T dato;                                           // El tipo de dato es generico, se utiliza para Paquete y Pagina   
    Nodo* next;
public:
    Nodo() { next = NULL; };
    Nodo(T a) { dato = a; next = NULL; };
    void set_dato(T a) { dato = a; };
    void set_next(Nodo* n) { next = n; };
    T get_dato() { return dato; };
    Nodo* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};

template <class T> class Lista {
private: Nodo<T>* czo;
       void addO(T d, Nodo<T>* ant);
       void borrarD(T d, Nodo<T>* ant);
public:
    Lista() { czo = new Nodo<T>(); };
    Lista(Nodo<T>* n) { czo = n; };
    //~Lista(void);
    void add(T d);                          //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void);                         //retorna el dato del primer nodo
    Lista* resto(void);                     //retorna el puntero al "resto" de la lista
                                            //resto = lo que queda de la lista sin la cabeza
    string toPrint(string p);
    void impre(void);
    T suma(T i);
    int  size();
    bool esta(T d);// detecta si d esta en la lista
    void borrarDato(T d) { borrarD(d, NULL); }//borra el nodo que contiene d
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    void addOrdenado(T d) { addO(d, NULL); }; //sumar nodos a la lista Ordenados de menor a MAYOR
    T last(); //retorna el dato del ultimo nodo
};

//--------------Clase Pila----------------------
template <class T> class Pila :public Lista<T> {
public:
    Pila() { Lista<T>(); };
    void apilar(T d) { this->add(d); };
    T tope(void) { return this->cabeza(); };
    void desapilar(void) { this->borrar(); };
    bool pilavacia() { return this->esvacia(); };
};

//--------------Clase Cola----------------------
template <class T> class Cola :public Lista<T> {
public:
    Cola(void) { Lista<T>(); };
    //~Cola(void);
    T tope() { return this->last(); };
    bool colavacia(void) { return this->esvacia(); };
    void encolar(T a) { this->add(a); };
    void desencolar(void) { this->borrar_last(); };
    T ultimo(void) { return this->cabeza(); };
    string imprimir(string s) { return this->toPrint(s); };
};



#endif // Paquete_H
