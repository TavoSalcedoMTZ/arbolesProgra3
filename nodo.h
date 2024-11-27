#pragma once
#include <iostream>

class Nodo
{
public:
    Nodo();

    Nodo* CrearNodo(int n);  
    void InsertarNodo(Nodo*& arbol, int n);
    void MostrarArbol(Nodo* arbol, int n = 0);  

private:
    int dato;
    Nodo* dere;
    Nodo* izq;
};
