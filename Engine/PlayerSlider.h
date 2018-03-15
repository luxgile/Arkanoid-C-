#pragma once

#include "Vec2.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "Rect.h"

class PlayerSlider
{
public:
	PlayerSlider() = default;
	PlayerSlider(Vec2 _position);
	void Update(float const dt, Keyboard& const kbd);
	void Draw(Graphics& const gfx);
	void Move(const float _speed);
	void Constrain();
	const Rect GetRect();
	float SetSpeed(Keyboard& const kbd);
public:
	Vec2 position;
	const Vec2 size;
private:
	
};