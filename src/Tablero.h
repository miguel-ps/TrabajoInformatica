#pragma once
#include "Casilla.h"
#define MAX 8
class Tablero
{
	friend class Movimientos;
	friend class Interaccion;
private:
	Casilla lista[MAX][MAX];
public:
	Tablero();
	~Tablero();
	void dibuja();
	Casilla limites();
};

