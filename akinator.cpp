#include "Akinator.h"

Akinator::Akinator() : arbol(nullptr) {}

Akinator::~Akinator() {
    liberarMemoria(arbol);
}

int Akinator::altura(Nodo* nodo) {
    if (!nodo) return 0;
    return std::max(altura(nodo->izq), altura(nodo->dere)) + 1;
}

int Akinator::factorEquilibrio(Nodo* nodo) {
    if (!nodo) return 0;
    return altura(nodo->izq) - altura(nodo->dere);
}

Nodo* Akinator::rotacionDerecha(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* T2 = x->dere;

    x->dere = y;
    y->izq = T2;


    y->altura = std::max(altura(y->izq), altura(y->dere)) + 1;
    x->altura = std::max(altura(x->izq), altura(x->dere)) + 1;

    return x; 
}

Nodo* Akinator::rotacionIzquierda(Nodo* x) {
    Nodo* y = x->dere;
    Nodo* T2 = y->izq;


    y->izq = x;
    x->dere = T2;

  
    x->altura = std::max(altura(x->izq), altura(x->dere)) + 1;
    y->altura = std::max(altura(y->izq), altura(y->dere)) + 1;

    return y; 
}

Nodo* Akinator::rotacionDobleDerecha(Nodo* nodo) {
    nodo->izq = rotacionIzquierda(nodo->izq);
    return rotacionDerecha(nodo);
}

Nodo* Akinator::rotacionDobleIzquierda(Nodo* nodo) {
    nodo->dere = rotacionDerecha(nodo->dere);
    return rotacionIzquierda(nodo);
}

Nodo* Akinator::insertar(Nodo* nodo, const std::string& dato) {

    if (!nodo) return new Nodo(dato);

    
    if (dato < nodo->dato) {
        nodo->izq = insertar(nodo->izq, dato);
    } else if (dato > nodo->dato) {
        nodo->dere = insertar(nodo->dere, dato);
    } else {
        return nodo; 
    }

    nodo->altura = std::max(altura(nodo->izq), altura(nodo->dere)) + 1;

  
    int balance = factorEquilibrio(nodo);

  
    if (balance > 1 && dato < nodo->izq->dato) {
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && dato > nodo->dere->dato) {
        return rotacionIzquierda(nodo);
    }

    if (balance > 1 && dato > nodo->izq->dato) {
        return rotacionDobleDerecha(nodo);
    }

    if (balance < -1 && dato < nodo->dere->dato) {
        return rotacionDobleIzquierda(nodo);
    }

    return nodo;
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
        std::cout << "Tu objeto es " << nodo->dato << "? (s/n): " << std::endl << std::endl;
        char respuesta;
        std::cin >> respuesta;
        if (respuesta == 's' || respuesta == 'S') {
            std::cout << "He adivinado tu objeto!\n";
        } else {
            std::cout << "¿En que pensabas?: ";
            std::cin.ignore();
            std::string nuevoObjeto;
            std::getline(std::cin, nuevoObjeto);

            std::cout << "Escribe una pregunta para diferenciar " << nodo->dato << " de " << nuevoObjeto << ": " << std::endl;
            std::string nuevaPregunta;
            std::getline(std::cin, nuevaPregunta);

            Nodo* nuevoNodo = new Nodo(nuevaPregunta);
            std::cout << "Si la respuesta es 'si', es " << nuevoObjeto << "? (s/n): " << std::endl;
            std::cin >> respuesta;

            if (respuesta == 's') {
                nuevoNodo->izq = new Nodo(nuevoObjeto);
                nuevoNodo->dere = nodo;
            } else {
                nuevoNodo->izq = nodo;
                nuevoNodo->dere = new Nodo(nuevoObjeto);
            }
            nodo = nuevoNodo;
        }
        guardar("akinator.txt");
    } else {
        std::cout << nodo->dato << " (s/n): " << std::endl;
        char respuesta;
        std::cin >> respuesta;
        if (respuesta == 's') {
            jugar(nodo->izq);
        } else {
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

void Akinator::ImprimirArbol(Nodo* node, std::string prefix, bool isIzq)
{
    if (node) {
        std::cout << prefix;

        std::cout << (isIzq ? "+----" : "----");

        std::cout << node->dato << std::endl;

        std::string newPrEFIX = prefix + (isIzq ? "* " : " ");

        ImprimirArbol(node->izq, newPrEFIX, true);
        ImprimirArbol(node->dere, newPrEFIX, false);

    }
}

void Akinator::cargar(const std::string& archivo) {
    std::ifstream entrada(archivo);
    if (entrada.is_open()) {
        arbol = cargarArbol(entrada);
        entrada.close();
    } else {
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
    } else {
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


void Akinator::mostrararbol() {
    if (!arbol) {
        std::cout << "El aunrbol esta vacio.\n";
        return;
    }
    ImprimirArbol(arbol,"",true);
}