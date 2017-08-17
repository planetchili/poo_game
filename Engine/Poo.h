#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2.h"

class Poo
{
public:
	Poo( const Vec2& pos_in,const Vec2& vel_in,const Surface& sprite );
	void Update( float dt );
	bool TestCollision( const Dude& dude ) const;
	void Draw( Graphics& gfx ) const;
private:
	const Surface& sprite;
	Vec2 pos;
	Vec2 vel;
	static constexpr float width = 24;
	static constexpr float height = 24;
};