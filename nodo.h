#pragma once
#include <iostream>
#include <fstream>

class Nodo
{
public:
    Nodo();

    Nodo* CrearNodo(int n);  
    void InsertarNodo(Nodo*& arbol, int n);  
    void MostrarArbol(Nodo* arbol, int n, std::ofstream& archivo);  
    void MostrarArbolPreOrden(Nodo* arbol, int n, std::ofstream& archivo);
    void MostrarArbolPostOrden(Nodo* arbol, int n, std::ofstream& archivo);  

private:
    int dato; 
    Nodo* dere; 
    Nodo* izq;  
};
