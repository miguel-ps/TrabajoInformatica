#include "Color.h"
#include "glut.h"


Color::Color(Byte _r, Byte _v, Byte _a)
{
	r=_r;
	v=_v;
	a=_a;
}
void Color::pon()
{
	glColor3ub(r,v,a);
}
Color::~Color()
{
}
