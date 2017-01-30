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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
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

//Sprite Movement within bounds
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y = y - 1;
		if (y - sHc <= 1)
		{
			y = sHc;
		}
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y = y + 1;
		if (y + sHc >= gfx.ScreenHeight)
		{
			y = gfx.ScreenHeight - (sHc + 1);
		}
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x = x - 1;
		if (x - sWc <= 1)
		{
			x = sWc;
		}

	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x = x + 1;
		if (x + sWc >= gfx.ScreenWidth)
		{
			x = gfx.ScreenWidth - (sWc + 1);
		}
	}

	colliding = Overlap(x, y, mX, mY);

//End Sprite Movement within bounds

}

	

void Game::ComposeFrame()
{
	DrawReticle(x, y, 255, 255, 255);
	DrawReticle(mX, mY, 255, 255, 255);

	if (colliding)
	{
		DrawReticle(x, y, 255, 0, 0);
	}
	else
		DrawReticle(x, y, 255, 255, 255);
	

}

void Game::DrawReticle(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(-5 + x, y, r, g, b);
	gfx.PutPixel(-4 + x, y, r, g, b);
	gfx.PutPixel(-3 + x, y, r, g, b);
	gfx.PutPixel(3 + x, y, r, g, b);
	gfx.PutPixel(4 + x, y, r, g, b);
	gfx.PutPixel(5 + x, y, r, g, b);
	gfx.PutPixel(x, -5 + y, r, g, b);
	gfx.PutPixel(x, -4 + y, r, g, b);
	gfx.PutPixel(x, -3 + y, r, g, b);
	gfx.PutPixel(x, 5 + y, r, g, b);
	gfx.PutPixel(x, 4 + y, r, g, b);
	gfx.PutPixel(x, 3 + y, r, g, b);
}

bool Game::Overlap(int obj0x, int obj0y, int obj1x, int obj1y)
{

	const int left_obj0 = obj0x - sWc;
	const int right_obj0 = obj0x + sWc;
	const int top_obj0 = obj0y - sHc;
	const int bottom_obj0 = obj0y + sHc;

	const int left_obj1 = obj1x - sWc;
	const int right_obj1 = obj1x + sWc;
	const int top_obj1 = obj1y - sHc;
	const int bottom_obj1 = obj1y + sHc;

	return 
		left_obj1 <= right_obj0 &&
		right_obj1 >= left_obj0 &&
		top_obj1 <= bottom_obj0 &&
		bottom_obj1 >= top_obj0;


}
