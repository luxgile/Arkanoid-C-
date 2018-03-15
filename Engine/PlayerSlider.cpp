#include "PlayerSlider.h"

PlayerSlider::PlayerSlider(Vec2 _position)
	:
	position(_position),
	size(Vec2(100,15))
{
}

void PlayerSlider::Move(const float _speed)
{
	position.x += _speed;
}

void PlayerSlider::Constrain()
{
	if (position.x > 700) { position.x = 700; }
	if (position.x < 100) { position.x = 100; }
}

const Rect PlayerSlider::GetRect()
{
	return Rect(position, size);
}

float PlayerSlider::SetSpeed(Keyboard& const kbd)
{
	float speed = 0;
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		speed = -200;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		speed = 200;
	}

	if(kbd.KeyIsPressed(VK_SHIFT))
	{
		speed *= 2;
	}

	return speed;
}

void PlayerSlider::Update(float const dt, Keyboard& const kbd)
{
	float speed = SetSpeed(kbd) * dt;
	Move(speed);
	Constrain();
}

void PlayerSlider::Draw(Graphics& const gfx)
{
	const Rect rectGfx = Rect(position, size);
	gfx.DrawRect(rectGfx, Colors::White);
}
