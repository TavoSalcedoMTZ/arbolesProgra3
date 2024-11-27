#include "nodo.h"

Nodo::Nodo() {
 
    dere = izq = nullptr;
}

Nodo* Nodo::CrearNodo(int n)
{
    Nodo* Temp = new Nodo();  
    Temp->dato = n;
    Temp->dere = nullptr;
    Temp->izq = nullptr;
    return Temp;  
}

void Nodo::InsertarNodo(Nodo*& arbol, int n)
{
    if (arbol == nullptr) {
        Nodo* Temp = CrearNodo(n);  
        arbol = Temp;  
    }
    else {
        int ValorRaiz = arbol->dato;
        if (n < ValorRaiz) {
            InsertarNodo(arbol->izq, n); 
        }
        else {
            InsertarNodo(arbol->dere, n);  
        }
    }
}

void Nodo::MostrarArbol(Nodo* arbol, int n)
{
    if (arbol == nullptr) {
        return;  
    }
    else {
        MostrarArbol(arbol->dere, n + 1); 
        for (int i = 0; i < n; i++) {
            std::cout << " ";  
        }

        std::cout << arbol->dato << std::endl;  
        MostrarArbol(arbol->izq, n + 1);  
    }
}
