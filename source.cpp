#include "nodo.h"

void menu() {
    int dato;
    int opcion;
    Nodo arbolito;
    Nodo* arbol = nullptr;

    do {
        std::cout << "\n Ingrese una opcion" << std::endl;
        std::cout << "\n 1 Insertar un nuevo nodo" << std::endl;
        std::cout << "\n 2 Mostrar Arbol" << std::endl;
        std::cout << "\n 3 Salir" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "\n Ingresa un numero: " << std::endl;
            std::cin >> dato;
            arbolito.InsertarNodo(arbol, dato);  
            std::cout << "\n" << std::endl;
            break;

        case 2:
            arbolito.MostrarArbol(arbol); 
            std::cout << "\n" << std::endl;
            break;
        }
    } while (opcion != 3);  
}

int main() {
    menu();
    return 0;
}