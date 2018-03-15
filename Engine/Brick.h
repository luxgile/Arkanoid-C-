#pragma once

#include "Rect.h"
#include "Vec2.h"
#include "Graphics.h"
#include "Colors.h"

class Brick
{
public:
	Brick();
	Brick(Vec2 _pos, Color _color);
	const Rect GetRect();
	void Destroy();
	void Draw(Graphics& gfx);
public: 
	Color color;
	Vec2 position;
	Vec2 size;
	bool destroyed = false;
};

