#pragma once
#include "Vector2D.h"

class Ficha
{
private:
	Vector2D pos;
	float lado;
	bool color;
public:
	Ficha(float l=2.0f);
	virtual~Ficha();
	void dibuja();
	void setPos(float x, float y);
	void setPos(Vector2D p);
	void col(bool c);
	float getLado();
	Vector2D getPos();
	void mueve(float x, float y, float t);
};

