#pragma once
#include "ListaFichas.h"
#include "Tablero.h"
class Movimientos
{ 
public:
	Movimientos();
	virtual~Movimientos();
	static void PosInicial(ListaFichas &lf, Tablero &t);
	static void Posibilidades(Ficha& f, ListaFichas& lf, Tablero& t);
};

