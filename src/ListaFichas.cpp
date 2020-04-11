#include "ListaFichas.h"

ListaFichas::ListaFichas()
{
	for (int i = 0; i < 12; i++)
	{
		blancas[i].col(true);
		negras[i].col(false);
	}
}

ListaFichas::~ListaFichas()
{
}

void ListaFichas::dibuja()
{
	for (int i = 0; i < 12; i++)
		blancas[i].dibuja();
	for (int i = 0; i < 12; i++)
		negras[i].dibuja();
}
