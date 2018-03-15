#pragma once

#include "Vec2.h"
#include "Rect.h"
#include "PlayerSlider.h"
#include "Graphics.h"
#include "Brick.h"

class Ball
{

public:
	Ball();
	bool HasCollided(Brick bricks[], PlayerSlider& player);
	void Update(const float dt, Brick bricks[], PlayerSlider& player);
	void Move(const Vec2 speed);
	void Draw(Graphics& const gfx);
	void Constrain();
	const Rect GetRect();
public:
	Vec2 position;
	Vec2 velocity;
	const Vec2 size;
};

