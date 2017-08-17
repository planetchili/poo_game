#include "Poo.h"
#include "Graphics.h"
#include <assert.h>

Poo::Poo( const Vec2& pos_in,const Vec2& vel_in,const Surface& sprite )
	:
	sprite( sprite )
{
	pos = pos_in;
	vel = vel_in;
}

void Poo::Update( float dt )
{
	pos += vel * dt;

	const float right = pos.x + width;
	if( pos.x < 0 )
	{
		pos.x = 0;
		vel.x = -vel.x;
	}
	else if( right >= float( Graphics::ScreenWidth ) )
	{
		pos.x = float( Graphics::ScreenWidth - 1 ) - width;
		vel.x = -vel.x;
	}

	const float bottom = pos.y + height;
	if( pos.y < 0 )
	{
		pos.y = 0;
		vel.y = -vel.y;
	}
	else if( bottom >= float( Graphics::ScreenHeight ) )
	{
		pos.y = float( Graphics::ScreenHeight - 1 ) - height;
		vel.y = -vel.y;
	}
}

bool Poo::TestCollision( const Dude& dude ) const
{
	const float duderight = dude.GetPos().x + dude.GetWidth();
	const float dudebottom = dude.GetPos().y + dude.GetHeight();
	const float pooright = pos.x + width;
	const float poobottom = pos.y + height;

	return
		duderight >= pos.x &&
		dude.GetPos().x <= pooright &&
		dudebottom >= pos.y &&
		dude.GetPos().y <= poobottom;
}

void Poo::Draw( Graphics& gfx ) const
{
	gfx.DrawSprite( int( pos.x ),int( pos.y ),sprite,Colors::White );
}