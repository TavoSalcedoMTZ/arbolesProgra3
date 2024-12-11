#pragma once
#include "Nodo.h"
#include <string>
#include <fstream>
#include <iostream>

class Akinator {
private:
    Nodo* arbol;


    int altura(Nodo* nodo);
    int factorEquilibrio(Nodo* nodo);
    Nodo* rotacionDerecha(Nodo* y);
    Nodo* rotacionIzquierda(Nodo* x);
    Nodo* rotacionDobleDerecha(Nodo* nodo);
    Nodo* rotacionDobleIzquierda(Nodo* nodo);
    Nodo* insertar(Nodo* nodo, const std::string& dato);


    Nodo* cargarArbol(std::ifstream& archivo);
    void guardarArbol(std::ofstream& archivo, Nodo* nodo);

    void jugar(Nodo*& nodo);


    void liberarMemoria(Nodo* nodo);

    void ImprimirArbol(Nodo* node, std::string prefix="", bool isIzq=true);
public:
    Akinator();
    ~Akinator();


    void cargar(const std::string& archivo);
    void guardar(const std::string& archivo);
    void jugar();
    void mostrararbol();
};
