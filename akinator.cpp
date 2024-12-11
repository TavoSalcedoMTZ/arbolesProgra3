#include "Akinator.h"

Akinator::Akinator() : arbol(nullptr) {}

Akinator::~Akinator() {
    liberarMemoria(arbol);
}

Nodo* Akinator::cargarArbol(std::ifstream& archivo) {
    std::string linea;
    if (!std::getline(archivo, linea)) {
        return nullptr;
    }
    if (linea == "#") {
        return nullptr;
    }
    Nodo* nuevo = new Nodo(linea);
    nuevo->izq = cargarArbol(archivo);
    nuevo->dere = cargarArbol(archivo);
    return nuevo;
}

void Akinator::guardarArbol(std::ofstream& archivo, Nodo* nodo) {
    if (!nodo) {
        archivo << "#\n";
        return;
    }
    archivo << nodo->dato << "\n";
    guardarArbol(archivo, nodo->izq);
    guardarArbol(archivo, nodo->dere);
}

void Akinator::jugar(Nodo*& nodo) {
    if (!nodo->izq && !nodo->dere) {
        std::cout << "Tu objeto es " << nodo->dato << "? (s/n): " << std::endl<< std::endl;
        char respuesta;
        std::cin >> respuesta;
        if (respuesta == 's'|| respuesta =='S') {
            std::cout << "He adivinado tu objeto!\n";
        }
        else {
            std::cout << "¿En que pensabas?: ";
            std::cin.ignore();
            std::string nuevoObjeto;
            std::getline(std::cin, nuevoObjeto);

            std::cout << "Escribe una pregunta para diferenciar " << nodo->dato << " de " << nuevoObjeto << ": "<<std::endl;
            std::string nuevaPregunta;
            std::getline(std::cin, nuevaPregunta);

            Nodo* nuevoNodo = new Nodo(nuevaPregunta);
            std::cout << "Si la respuesta es 'si', es " << nuevoObjeto << "? (s/n): "<<std::endl;
            std::cin >> respuesta;

            if (respuesta == 's') {
                nuevoNodo->izq = new Nodo(nuevoObjeto);
                nuevoNodo->dere = nodo;
            }
            else {
                nuevoNodo->izq = nodo;
                nuevoNodo->dere = new Nodo(nuevoObjeto);
            }
            nodo = nuevoNodo;
        }
        guardar("akinator.txt");
    }
    else {
        std::cout << nodo->dato << " (s/n): "<<std::endl;
        char respuesta;
        std::cin >> respuesta;
        if (respuesta == 's') {
            jugar(nodo->izq);
        }
        else {
            jugar(nodo->dere);
        }
    }
}

void Akinator::liberarMemoria(Nodo* nodo) {
    if (!nodo) return;
    liberarMemoria(nodo->izq);
    liberarMemoria(nodo->dere);
    delete nodo;
}

void Akinator::cargar(const std::string& archivo) {
    std::ifstream entrada(archivo);
    if (entrada.is_open()) {
        arbol = cargarArbol(entrada);
        entrada.close();
    }
    else {
        arbol = new Nodo("Es un animal?");
        arbol->izq = new Nodo("Perro");
        arbol->dere = new Nodo("Piedra");
    }
}

void Akinator::guardar(const std::string& archivo) {
    std::ofstream salida(archivo);
    if (salida.is_open()) {
        guardarArbol(salida, arbol);
        salida.close();
    }
    else {
        std::cout << "No se pudo guardar el arbol.\n";
    }
}

void Akinator::jugar() {
    if (!arbol) {
        std::cout << "El arbol esta vacio.\n";
        return;
    }
    jugar(arbol);
}
