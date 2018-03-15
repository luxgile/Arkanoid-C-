#include "Ball.h"


Ball::Ball()
	:
	size(Vec2(30,30)),
	velocity(Vec2(250,250)),
	position(Vec2(400,400))
{
}

bool Ball::HasCollided(Brick bricks[], PlayerSlider& player)
{
	const int arrSize = 20;

	for (int i = 0; i < arrSize; i++)
	{
		if (bricks[i].GetRect().OnBounds(position)) 
		{
			bricks[i].Destroy();
			velocity.y *= -1;
		}
	}

	if(player.GetRect().OnBounds(position))
	{
		velocity.y *= -1;
	}

	return false;
}

void Ball::Update(const float dt, Brick bricks[], PlayerSlider& player)
{
	Move(velocity * dt);

	if (HasCollided(bricks, player)) 
	{
		velocity = velocity * -1;
	}

	Constrain();
}

void Ball::Move(const Vec2 speed)
{
	position += speed;
}

void Ball::Draw(Graphics & const gfx)
{
	Rect rect = Rect(position, size);
	gfx.DrawCircle(rect, Colors::Blue);
}

void Ball::Constrain()
{
	if (position.x < Graphics::ScreenOffset + (size.x / 2) || position.x > Graphics::ScreenWidth - Graphics::ScreenOffset - (size.x / 2)) {
		velocity.x *= -1;
	}

	if (position.y < Graphics::ScreenOffset + (size.y / 2) || position.y > Graphics::ScreenHeight - Graphics::ScreenOffset - (size.y / 2)) {
		velocity.y *= -1;
	}
}

const Rect Ball::GetRect() 
{
	return Rect(position, size);
}
