#include "Interaccion.h"


bool Interaccion::seleccion(float x, float y, Tablero t)
{
	Casilla c = t.limites();
	float l = c.getLado();
	Vector2D p = c.getPos();
	if (x > p.x && y > p.y && x < p.x + l && y < p.y + l) //si se selecciona dentro del tablero
		return true;
	return false;
}

Ficha* Interaccion::seleccion(float x, float y, ListaFichas lf)
{
	for (int i = 0; i < 12; i++)
	{
		float l = lf.blancas[i].getLado();
		Vector2D p = lf.blancas[i].getPos();
		if (x > p.x && y > p.y && x < p.x + l && y < p.y + l)
			return &lf.blancas[i];
		l = lf.negras[i].getLado();
		p = lf.negras[i].getPos();
		if (x > p.x && y > p.y && x < p.x + l && y < p.y + l)
			return &lf.negras[i];
	}
	return 0;
}
