#pragma once

#include "Graphics.h"
#include "Dude.h"

class Poo
{
public:
	void Init( float in_x,float in_y,float in_vx,float in_vy );
	void Update( float dt );
	bool TestCollision( const Dude& dude ) const;
	void Draw( Graphics& gfx ) const;
private:
	float x;
	float y;
	float vx;
	float vy;
	static constexpr float width = 24;
	static constexpr float height = 24;
	bool initialized = false;
};