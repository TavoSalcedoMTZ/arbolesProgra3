#pragma once
<<<<<<< HEAD
#include <iostream>
#include <fstream>
=======
>>>>>>> e895e7b (Akinator funcional)
#include <string>

class Nodo {
public:
<<<<<<< HEAD
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
=======
    std::string dato;
>>>>>>> e895e7b (Akinator funcional)
    Nodo* izq;
    Nodo* dere;

    Nodo(const std::string& dato);
};