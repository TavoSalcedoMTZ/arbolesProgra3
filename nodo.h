#pragma once
#include <string>

class Nodo {
public:
    std::string dato;
    Nodo* izq;
    Nodo* dere;

    Nodo(const std::string& dato);
};