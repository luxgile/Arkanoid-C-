#pragma once

#include "Vec2.h"

class Rect
{
public:
	Rect() = default;
	Rect(Vec2 _pos, Vec2 _size);
	Vec2 MaxPoint() const;
	Vec2 MinPoint() const;
	bool OnBounds(Vec2& _pos) const;
	float MinorSize() const;
public:
	Vec2 position;
	Vec2 size;
};