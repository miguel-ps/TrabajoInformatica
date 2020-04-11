#include "Tablero.h"

Tablero::Tablero()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			lista[i][j] = Casilla();
			if ((i%2==0&&j%2==0)||(i%2!=0&&j%2!=0))
				lista[i][j].negra();
			else
				lista[i][j].blanca();
			lista[i][j].setPos(lista[i][j].pos.x + i * lista[i][j].lado, lista[i][j].pos.y + j * lista[i][j].lado);
		}
	}
}

Tablero::~Tablero()
{
}

void Tablero::dibuja()
{
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			lista[i][j].dibuja();
}

Casilla Tablero::limites()
{
	Casilla c=Casilla(8*lista[0][0].getLado());
	c.setPos(lista[0][0].getPos());
	return c;
}
