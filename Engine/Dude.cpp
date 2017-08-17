#include "Dude.h"
#include "Graphics.h"

void Dude::ClampToScreen()
{
	const float right = pos.x + width;
	if( pos.x < 0 )
	{
		pos.x = 0;
	}
	else if( right >= float( Graphics::ScreenWidth ) )
	{
		pos.x = float( Graphics::ScreenWidth - 1 ) - width;
	}

	const float bottom = pos.y + height;
	if( pos.y < 0 )
	{
		pos.y = 0;
	}
	else if( bottom >= float( Graphics::ScreenHeight ) )
	{
		pos.y = float( Graphics::ScreenHeight - 1 ) - height;
	}
}

void Dude::Draw( Graphics& gfx ) const
{
	gfx.DrawSprite( int( pos.x ),int( pos.y ),sprite );
}

void Dude::Update( const Keyboard& kbd,float dt )
{
	Vec2 vel( 0.0f,0.0f );
	if( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		vel.x += 1.0f;
	}
	if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		vel.x -= 1.0f;
	}
	if( kbd.KeyIsPressed( VK_DOWN ) )
	{
		vel.y += 1.0f;
	}
	if( kbd.KeyIsPressed( VK_UP ) )
	{
		vel.y -= 1.0f;
	}
	pos += vel.GetNormalized() * speed * dt;
}

void Dude::Update( const Mouse& mouse,float dt )
{
	if( mouse.LeftIsPressed() )
	{
		const Vec2 center = pos + Vec2( float( width ) / 2.0f,float( height ) / 2.0f );
		const Vec2 toPointer = Vec2( float( mouse.GetPosX() ),float( mouse.GetPosY() ) ) - center;
		// dead zone radius = sqrt( 2 )
		if( toPointer.GetLengthSq() > 2.0f )
		{
			pos += toPointer.GetNormalized() * speed * dt;
		}
	}	
}

Vec2 Dude::GetPos() const
{
	return pos;
}

float Dude::GetWidth() const
{
	return width;
}

float Dude::GetHeight() const
{
	return height;
}
