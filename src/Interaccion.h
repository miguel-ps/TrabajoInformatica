#pragma once
#include "ListaFichas.h"
#include "Tablero.h"
class Interaccion
{
public:
	static bool seleccion(float x, float y, Tablero t);
	static Ficha* seleccion(float x, float y, ListaFichas lf);
};

