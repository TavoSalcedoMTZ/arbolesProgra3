#include <iostream>
#include <fstream>
#include "nodo.h"

void menu() {
    int dato;
    int opcion;
    Nodo arbolito;
    Nodo* arbol = nullptr;

    std::ofstream archivo("arbol.txt");

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        return; 
    }

    do {
        std::cout << "\n Ingrese una opcion" << std::endl;
        std::cout << "\n 1 Insertar un nuevo nodo" << std::endl;
        std::cout << "\n 2 Mostrar Arbol" << std::endl;
        std::cout << "\n 3 Mostrar Arbol PreOrden" << std::endl;
        std::cout << "\n 4 Mostrar Arbol PostOrden" << std::endl;
        std::cout << "\n 5 Salir" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "\n Ingresa un numero: " << std::endl;
            std::cin >> dato;
            arbolito.InsertarNodo(arbol, dato);
            break;

        case 2:
            arbolito.MostrarArbol(arbol, 0, archivo);  
            std::cout << "\n" << std::endl;
            std::cout << "\nArbol guardado en el archivo." << std::endl;
            break;

        case 3:
            arbolito.MostrarArbolPreOrden(arbol, 0, archivo); 
            std::cout << "\n" << std::endl;
            std::cout << "\nArbol en PreOrden guardado en el archivo." << std::endl;
            break;

        case 4:
            arbolito.MostrarArbolPostOrden(arbol, 0, archivo);
            std::cout << "\n" << std::endl;
            std::cout << "\nArbol en PostOrden guardado en el archivo." << std::endl;
            break;

        case 5:
            std::cout << "Saliendo del programa" << std::endl;
            break;

        default:
            std::cout << "ERROR" << std::endl;
            break;
        }
    } while (opcion != 5);

    archivo.close();  
}

int main() {
    menu();
    return 0;
}
