#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Ball
{

public:
	Ball();
	bool HasCollided();
	void Update(const float dt);
	void Move(const Vec2 speed);
	void Draw(Graphics& const gfx);
	void Constrain();
public:
	Vec2 position;
	Vec2 velocity;
	const Vec2 size;
};

