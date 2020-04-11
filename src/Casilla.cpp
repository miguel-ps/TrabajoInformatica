#include "Casilla.h"
#include "glut.h"
Casilla::Casilla(float l)
{
	lado = l;
	setPos(-8,-8);
}

Casilla::~Casilla()
{
}

void Casilla::dibuja()
{
	glDisable(GL_LIGHTING);
	color.pon();
	glBegin(GL_POLYGON);
	glVertex3d(pos.x, pos.y, 0);
	glVertex3d(pos.x+lado, pos.y, 0);
	glVertex3d(pos.x+lado, pos.y+lado, 0);
	glVertex3d(pos.x, pos.y+lado, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}
void Casilla::blanca()
{
	color.r=color.v=color.a=255;
}
void Casilla::negra()
{
	color.r=color.v=color.a=0;
}
void Casilla::setPos(float x, float y)
{
	pos.set(x, y);
}

void Casilla::setPos(Vector2D p)
{
	pos.set(p.x, p.y);
}

float Casilla::getLado()
{
	return lado;
}

Vector2D Casilla::getPos()
{
	return pos;
}
