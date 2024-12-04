#include "nodo.h"

Nodo::Nodo() {
    dere = izq = nullptr;
}

Nodo* Nodo::CrearNodo(std::string _p) {
    Nodo* Temp = new Nodo();
    Temp->preguntaTF = _p;
    Temp->dere = nullptr;
    Temp->izq = nullptr;
    return Temp;

  
}

void Nodo::InsertarNodo(Nodo*& arbol, bool respuesta, std::string pregunta, std::string entidad) {
    if (arbol == nullptr) {
        arbol = CrearNodo(pregunta);  
    }
    else {

        if (!arbol->preguntaTF.empty() && arbol->preguntaTF.back() == '?') {
            if (respuesta) {
                InsertarNodo(arbol->dere, respuesta, pregunta, entidad); 
            }
            else {
                InsertarNodo(arbol->izq, respuesta, pregunta, entidad);  
            }
        }
        else {

            Nodo* nuevaPregunta = CrearNodo(pregunta);
            Nodo* entidadExistente = CrearNodo(arbol->preguntaTF);  
            Nodo* entidadNueva = CrearNodo(entidad);  

      
            if (respuesta) {
                nuevaPregunta->dere = entidadNueva;
                nuevaPregunta->izq = entidadExistente;
            }
            else {
                nuevaPregunta->dere = entidadExistente;
                nuevaPregunta->izq = entidadNueva;
            }
            arbol = nuevaPregunta; 
        }
    }


    GuardarArbol(arbol);
}

void Nodo::MostrarArbol(Nodo* arbol, int n, std::ofstream& archivo) {
    if (arbol == nullptr) {
        return;
    }

    MostrarArbol(arbol->dere, n + 1, archivo);  
    for (int i = 0; i < n; i++) {
        std::cout << " ";
    }

    std::cout << arbol->preguntaTF << std::endl;
    archivo << arbol->preguntaTF << std::endl; 
    MostrarArbol(arbol->izq, n + 1, archivo);  
}

void Nodo::GuardarArbol(Nodo* arbol) {
    std::ofstream archivo("arbol.txt");

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        return;
    }


    if (arbol) {
        if (arbol->preguntaTF.empty()) {
            return;
        }
        archivo << arbol->preguntaTF << std::endl;
        if (arbol->dere != nullptr) {
            GuardarArbol(arbol->dere); 
        }
        if (arbol->izq != nullptr) {
            GuardarArbol(arbol->izq); 
        }
    }

    archivo.close();
}

void Nodo::CargarArbol(Nodo*& arbol) {
    std::ifstream archivo("arbol.txt");
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para leer." << std::endl;
        return;
    }

    std::string pregunta;
    while (std::getline(archivo, pregunta)) {
        if (!pregunta.empty()) {
            InsertarNodo(arbol, true, pregunta, "Entidad desconocida");
        }
    }
    archivo.close();
}

void Nodo::Akinator(Nodo* arbol) {
    if (arbol == nullptr) {
        std::cout << "El árbol está vacío." << std::endl;
        return;
    }

    if (arbol->preguntaTF.back() == '?') {
        char respuesta;
        std::cout << arbol->preguntaTF << " (s/n): ";
        std::cin >> respuesta;

        if (respuesta == 's' || respuesta == 'S') {
            Akinator(arbol->dere); 
        }
        else {
            Akinator(arbol->izq);  
        }
    }
    else {
        std::cout << "Creo que es: " << arbol->preguntaTF << std::endl;
        char respuesta;
        std::cout << "¿Es correcto? (s/n): ";
        std::cin >> respuesta;

        if (respuesta == 'n' || respuesta == 'N') {
            std::string nuevaPregunta, nuevaEntidad;
            std::cout << "Introduce una nueva pregunta para diferenciar entre " << arbol->preguntaTF << " y la entidad correcta: ";
            std::cin.ignore(); 
            std::getline(std::cin, nuevaPregunta);

            std::cout << "¿Qué entidad sería la respuesta correcta? ";
            std::getline(std::cin, nuevaEntidad);

            std::cout << "¿La respuesta correcta es sí (s) o no (n)? ";
            std::cin >> respuesta;

            bool respuestaCorrecta = (respuesta == 's' || respuesta == 'S');
            InsertarNodo(arbol, respuestaCorrecta, nuevaPregunta, nuevaEntidad);
        }
    }
}
