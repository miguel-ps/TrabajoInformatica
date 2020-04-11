
#pragma once

typedef unsigned char Byte;
class Color  
{
public:
	Color(Byte _r=255, Byte _v=255, Byte _a=255);
	void set(Byte _r=255, Byte _v=255, Byte _a=255){r=_r;v=_v;a=_a;}
	void pon();
	virtual ~Color();
	Byte r,v,a;
};

