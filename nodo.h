#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Nodo
{
public:
    Nodo();

    Nodo* CrearNodo(std::string _p);
    void InsertarNodo(Nodo*& arbol, bool respuesta, std::string pregunta, std::string entidad);
    void MostrarArbol(Nodo* arbol, int n, std::ofstream& archivo);
    void GuardarArbol(Nodo* arbol);  // Guardar el árbol completo
    void CargarArbol(Nodo*& arbol);  // Cargar el árbol desde el archivo
    void Akinator(Nodo* arbol);

private:
    std::string preguntaTF;
    Nodo* dere;
    Nodo* izq;
};
