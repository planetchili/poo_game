#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Vec2.h"
#include "Surface.h"

class Dude
{
public:
	void ClampToScreen();
	void Draw( Graphics& gfx ) const;
	void Update( const Keyboard& kbd,float dt );
	void Update( const Mouse& mouse,float dt );
	Vec2 GetPos() const;
	float GetWidth() const;
	float GetHeight() const;
private:
	Surface sprite = Surface( "poo_images\\awsom.bmp" );
	Vec2 pos = Vec2( 400.0f,300.0f );
	static constexpr float speed = 1.0f * 60.0f;
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
};