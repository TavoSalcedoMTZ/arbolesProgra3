#pragma once
#include <string>

class Nodo {
public:
    std::string dato;
    Nodo* izq;
    Nodo* dere;
    int altura;

    Nodo(const std::string& dato);
};