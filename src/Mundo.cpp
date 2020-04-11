#include "Mundo.h"
#include "glut.h"
#include <math.h>

Mundo::Mundo()
{
	x_ojo = 0.0f;
	y_ojo = 0.0f;
	z_ojo = 25.0f;
	Movimientos::PosInicial(lf, t);
}
Mundo::~Mundo()
{

}
void Mundo::inicializa()
{
	Movimientos::PosInicial(lf, t);
}
void Mundo::rotarOjo()
{
	float dist=(float)sqrt((x_ojo*x_ojo)+(z_ojo*z_ojo));
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
	t.dibuja();
	lf.dibuja();
}
void Mundo::mueve()
{

}
void Mundo::tecla(unsigned char key)
{

}
void Mundo::teclaEspecial(unsigned char key)
{

}

void Mundo::raton(float x, float y)
{
	if (Interaccion::seleccion(x, y, t))
	{
		
		Ficha *f = Interaccion::seleccion(x, y, lf);
		if (f)
		{
			Vector2D p = f->getPos();
			glTranslatef(p.x, p.y, 0);
			glColor3ub(0, 255, 0);
			glutSolidTorus(1, 5, 20, 20);
		}
	}
}
