#include "Akinator.h"

int main() {
    Akinator akinator;
    const std::string archivo = "akinator.txt";
    akinator.cargar(archivo);

    int opcion;
    do {
        std::cout << std::endl << "1. Jugar " << std::endl<<" 2. Guardar y salir"<<std::endl<<"Elige una opcion : "<<std::endl;
        std::cin >> opcion;

        if (opcion == 1) {
            akinator.jugar();
        }
        else if (opcion == 2) {
            akinator.mostrararbol();
        }
    } while (opcion != 3);

    akinator.guardar(archivo);
    return 0;
}
