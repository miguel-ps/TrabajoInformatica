#pragma once
#include "Ficha.h"
class ListaFichas
{
	friend class Movimientos;
	friend class Ficha;
	friend class Interaccion;
private:
	Ficha blancas[12];
	Ficha negras[12];
public:
	ListaFichas();
	virtual~ListaFichas();
	void dibuja();
};

