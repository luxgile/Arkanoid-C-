/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Colors.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	player (Vec2(gfx.ScreenWidth/2, gfx.ScreenHeight * 0.9f)),
	ball()
{
	for (int i = 0; i < brickNumber; i++)
	{
		int row = i / brickColumns;
		int column = i % brickColumns;

		float x = Mathf::Lerp(Graphics::ScreenOffset + 100, Graphics::ScreenWidth - Graphics::ScreenOffset - 100, (float)column / (float)(brickColumns-1));
		float y = Mathf::Lerp(Graphics::ScreenHeight/2, Graphics::ScreenOffset, (float)row/(float)brickColumns);
		Vec2 brickPos = Vec2(x, y);

		bricks[i] = Brick(brickPos, Colors::Red);
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = timer.Mark();
	player.Update(dt, wnd.kbd);
	ball.Update(dt, bricks, player);
}

void Game::ComposeFrame()
{
	gfx.DrawOffset(10, Colors::Gray);

	player.Draw(gfx);
	ball.Draw(gfx);

	for (int  i = 0; i < brickNumber; i++)
	{
		bricks[i].Draw(gfx);
	}
}
