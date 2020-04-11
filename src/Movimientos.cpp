#include "Movimientos.h"
#include "Ficha.h"
#include "glut.h"

Movimientos::Movimientos()
{

}

Movimientos::~Movimientos()
{
}

void Movimientos::PosInicial(ListaFichas &lf, Tablero &t)
{
	int j = 0, k = 0;
	for (int i = 0; i < 12; i++)
	{
			lf.blancas[i].setPos(t.lista[j][k].getPos());
			lf.negras[i].setPos(t.lista[7-j][7-k].getPos());
			j += 2;
			if (i == 3)
				j = 1, k = 1;
			if (i == 7)
				j = 0, k = 2;
	}
}

void Movimientos::Posibilidades(Ficha& f, ListaFichas& lf, Tablero& t)
{
//Prueba para atom

}
