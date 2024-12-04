#include <iostream>
#include "nodo.h"

void menu() {
    int opcion;
    Nodo arbolito;
    Nodo* arbol = nullptr;


    arbolito.CargarArbol(arbol);

    do {
        std::cout << "Menu Akinator\n";
        std::cout << "1. Jugar\n";
        std::cout << "2. Ver árbol\n";
        std::cout << "3. Salir\n";
        std::cout << "Elige una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            arbolito.Akinator(arbol);  
            break;
        case 2:
        {
            std::ofstream archivo("arbol.txt");
            arbolito.MostrarArbol(arbol, 0, archivo);  
            break;
        }
        case 3:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opción no válida.\n";
            break;
        }
    } while (opcion != 3);
}

int main() {
    menu(); 
    return 0;
}
