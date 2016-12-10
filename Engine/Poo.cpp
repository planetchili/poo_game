#include "Poo.h"
#include "Graphics.h"
#include <assert.h>

void Poo::Init( float in_x,float in_y,float in_vx,float in_vy )
{
	assert( initialized == false );
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	initialized = true;
}

void Poo::Update( float dt )
{
	assert( initialized == true );
	x += vx * dt;
	y += vy * dt;

	const float right = x + width;
	if( x < 0 )
	{
		x = 0;
		vx = -vx;
	}
	else if( right >= float( Graphics::ScreenWidth ) )
	{
		x = float( Graphics::ScreenWidth - 1 ) - width;
		vx = -vx;
	}

	const float bottom = y + height;
	if( y < 0 )
	{
		y = 0;
		vy = -vy;
	}
	else if( bottom >= float( Graphics::ScreenHeight ) )
	{
		y = float( Graphics::ScreenHeight - 1 ) - height;
		vy = -vy;
	}
}

bool Poo::TestCollision( const Dude& dude ) const
{
	assert( initialized == true );
	const float duderight = dude.GetX() + dude.GetWidth();
	const float dudebottom = dude.GetY() + dude.GetHeight();
	const float pooright = x + width;
	const float poobottom = y + height;

	return
		duderight >= x &&
		dude.GetX() <= pooright &&
		dudebottom >= y &&
		dude.GetY() <= poobottom;
}

void Poo::Draw( Graphics& gfx ) const
{
	assert( initialized == true );

	const int x_int = int( x );
	const int y_int = int( y );

	gfx.PutPixel( 14 + x_int,0 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,1 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,1 + y_int,138,77,0 );
	gfx.PutPixel( 20 + x_int,1 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,2 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,2 + y_int,138,77,0 );
	gfx.PutPixel( 20 + x_int,2 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,3 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,4 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,4 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,4 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,5 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,5 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,5 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,6 + y_int,138,77,0 );
	gfx.PutPixel( 20 + x_int,6 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,7 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,7 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,7 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,7 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,8 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,8 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,8 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,9 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,9 + y_int,102,57,0 );
	gfx.PutPixel( 13 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,9 + y_int,51,28,0 );
	gfx.PutPixel( 21 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,10 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,10 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,10 + y_int,102,57,0 );
	gfx.PutPixel( 13 + x_int,10 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,10 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,10 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,10 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,11 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,11 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 16 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,12 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,12 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,12 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,12 + y_int,111,62,0 );
	gfx.PutPixel( 13 + x_int,12 + y_int,102,57,0 );
	gfx.PutPixel( 14 + x_int,12 + y_int,102,57,0 );
	gfx.PutPixel( 15 + x_int,12 + y_int,102,57,0 );
	gfx.PutPixel( 16 + x_int,12 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,13 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,13 + y_int,109,61,0 );
	gfx.PutPixel( 11 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,13 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 8 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,15 + y_int,116,65,0 );
	gfx.PutPixel( 8 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 16 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 17 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 18 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 2 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 3 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,16 + y_int,116,65,0 );
	gfx.PutPixel( 8 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,16 + y_int,109,61,0 );
	gfx.PutPixel( 14 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,16 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 2 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 3 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 4 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 5 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,17 + y_int,43,24,0 );
	gfx.PutPixel( 8 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,17 + y_int,40,22,0 );
	gfx.PutPixel( 14 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,17 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,17 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,17 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,17 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 2 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 3 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 4 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 5 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 8 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,18 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 21 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 22 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 2 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 3 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 4 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 5 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 8 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,19 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 22 + x_int,19 + y_int,65,36,0 );
	gfx.PutPixel( 23 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 2 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 3 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 8 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,20 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 22 + x_int,20 + y_int,65,36,0 );
	gfx.PutPixel( 23 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 2 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 3 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 4 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 5 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 8 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 16 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 17 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 18 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 21 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 22 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,22 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 2 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 3 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 4 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 5 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 6 + x_int,22 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 2 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 3 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,23 + y_int,51,28,0 );
}