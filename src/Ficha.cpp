#include "Ficha.h"
#include "ETSIDI.h"
#include "glut.h"

Ficha::Ficha(float l)
{
	lado = l;
	color = true;
	setPos(0, 0);
}

Ficha::~Ficha()
{
}

void Ficha::dibuja()
{
	glEnable(GL_TEXTURE_2D);
	if(color)
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/ficha_b.png").id);
	else if(color==false)
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/ficha_n.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(pos.x, pos.y+lado, 0.1);
	glTexCoord2d(1, 1); glVertex3f(pos.x+lado, pos.y+lado, 0.1);
	glTexCoord2d(1, 0); glVertex3f(pos.x+lado, pos.y, 0.1);
	glTexCoord2d(0, 0); glVertex3f(pos.x, pos.y, 0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}

void Ficha::setPos(float x, float y)
{
	pos.set(x, y); //se mide desde abajo a la izquierda
}

void Ficha::setPos(Vector2D p)
{
	pos.set(p.x, p.y);
}

void Ficha::col(bool c)
{
	color = c;
}

float Ficha::getLado()
{
	return lado;
}

Vector2D Ficha::getPos()
{
	return pos;
}

void Ficha::mueve(float x, float y, float t)
{
	if (pos.x <= x && pos.y <= y)
		pos = pos + Vector2D(3,3) * t;
}

