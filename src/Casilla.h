#pragma once
#include "Vector2D.h"
#include "Color.h"
class Casilla
{
	friend class Tablero;
private:
	Vector2D pos;
	float lado;
	Color color;
public:
	Casilla(float l=2.0f);
	virtual ~Casilla();
	void dibuja();
	void blanca();
	void negra();
	void setPos(float x, float y);
	void setPos(Vector2D p);
	float getLado();
	Vector2D getPos();
};

