/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawReticle(int x, int y, int r, int g, int b);
	bool Overlap(int obj0x, int obj0y, int obj1x, int obj1y);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	
	/********************************/
	/*  User Variables              */
	int x = gfx.ScreenWidth / 2;
	int y = gfx.ScreenHeight / 2;
	int mX = 200;
	int mY = 200;
	int spriteWidth = 10;
	int spriteHeight = 10;
	int sWc = spriteWidth / 2;
	int sHc = spriteHeight / 2;
	int r = 255;
	int g = 255;
	int b = 255;
	bool colliding = false;
	/********************************/

};