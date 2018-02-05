#include "Rect.h"

Rect::Rect(Vec2 _pos, Vec2 _size)
	:
	position(_pos),
	size(_size)
{
}

Vec2 Rect::MaxPoint() const
{
	return position + size * 0.5f;
}

Vec2 Rect::MinPoint() const
{
	return position - size * 0.5f;
}

bool Rect::OnBounds(Vec2 & _pos) const
{
	bool onBounds = false;
	if (_pos.x > MinPoint().x && _pos.x < MaxPoint().x && _pos.y > MinPoint().y && _pos.y < MaxPoint().y) { onBounds = true; }
	return onBounds;
}

float Rect::MinorSize() const
{
	if (size.x < size.y) {
		return size.x;
	}
	else {
		return size.y;
	}
}
