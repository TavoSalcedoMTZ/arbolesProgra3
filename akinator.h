#pragma once
#include "Nodo.h"
#include <string>
#include <fstream>
#include <iostream>

class Akinator {
private:
    Nodo* arbol;

    Nodo* cargarArbol(std::ifstream& archivo);
    void guardarArbol(std::ofstream& archivo, Nodo* nodo);
    void jugar(Nodo*& nodo);
    void liberarMemoria(Nodo* nodo);

public:
    Akinator();
    ~Akinator();

    void cargar(const std::string& archivo);
    void guardar(const std::string& archivo);
    void jugar();
};
