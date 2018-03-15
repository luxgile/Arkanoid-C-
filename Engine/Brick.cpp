#include "Brick.h"



Brick::Brick()
	:
	position(400,400),
	size(100,30),
	color(Colors::Red)
{
}

Brick::Brick(Vec2 _pos, Color _color)
	:	
position(_pos),
size(100, 15),
color(_color)
{
}

const Rect Brick::GetRect()
{
	return Rect(position, size);
}

void Brick::Destroy()
{
	destroyed = true;
}

void Brick::Draw(Graphics& gfx)
{
	if (!destroyed) 
	{
		gfx.DrawRect(GetRect(), color);
	}
}
