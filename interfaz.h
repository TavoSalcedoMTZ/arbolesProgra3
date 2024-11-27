#pragma once
#include "nodo.h"
class interfaz
{
public:
	interfaz();

	void MainMenu();

	void ActiveCrearNodo();
	void ActiveInsertarNodo();
	void MostrarArbol();
private:

	Nodo* arbolito;
};

