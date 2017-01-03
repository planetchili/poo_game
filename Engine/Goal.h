#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2.h"

class Goal
{
public:
	Goal( const Vec2& pos_in )
		:
		pos( pos_in )
	{}
	void Draw( Graphics& gfx ) const
	{
		gfx.DrawRectDim( int( pos.x ),int( pos.y ),int( dimension ),int( dimension ),c );
	}
	bool TestCollision( const Dude& dude ) const
	{
		const float duderight = dude.GetPos().x + dude.GetWidth();
		const float dudebottom = dude.GetPos().y + dude.GetHeight();
		const float pooright = pos.x + dimension;
		const float poobottom = pos.y + dimension;

		return
			duderight >= pos.x &&
			dude.GetPos().x <= pooright &&
			dudebottom >= pos.y &&
			dude.GetPos().y <= poobottom;
	}
	void Respawn( const Vec2& pos_in )
	{
		pos = pos_in;
	}
	void UpdateColor()
	{
		if( colorIncreasing )
		{
			if( c.GetR() >= 253 )
			{
				colorIncreasing = false;
			}
			else
			{
				c = Color( c.GetR() + 2,c.GetG() + 4,c.GetB() + 4 );
			}
		}
		else
		{
			if( c.GetR() <= 127 )
			{
				colorIncreasing = true;
			}
			else
			{
				c = Color( c.GetR() - 2,c.GetG() - 4,c.GetB() - 4 );
			}
		}
	}
private:
	static constexpr float dimension = 20;
	Color c = { 127,0,0 };
	bool colorIncreasing = true;
	Vec2 pos;
};