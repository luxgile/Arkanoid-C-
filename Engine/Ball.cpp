#include "Ball.h"



Ball::Ball()
	:
	size(Vec2(30,30)),
	velocity(Vec2(100,100)),
	position(Vec2(400,400))
{
}

bool Ball::HasCollided()
{
	return false;
}

void Ball::Update(const float dt)
{
	Move(velocity * dt);

	if (HasCollided()) {
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
