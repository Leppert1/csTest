// Test2.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//


#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class GameWindow : public Gosu::Window {
public:
	Gosu::Image bild;

	GameWindow()
		: Window(1000, 1000)
		, bild("Rakete.png")
	{
		set_caption("Gosu Tutorial Game");
	}
	int x = 0;
	int y = 0;
	int z = 0;
	double rot = 0.0;

	void update() override
	{
		/*z = input().mouse_x();
		y = input().mouse_y();
		x = (x + 1) % 300;
		*/
		x = input().mouse_x();
		y = input().mouse_y();
		if (input().down(Gosu::MS_LEFT))
		{
			rot += 10;
		}
		else if (input().down(Gosu::MS_RIGHT))
		{
			rot -= 10;
		}
	}

	void draw() override
	{
		/*	graphics().draw_line
			(
				x, 20, Gosu::Color::RED,
				200, 100, Gosu::Color::GREEN,
				0.0 // Ebene der Linie
			);
			graphics().draw_triangle
			(
				z, y, Gosu::Color::RED,
				200, 100, Gosu::Color::GREEN,
				200, 400, Gosu::Color::BLUE,
				0.0
			);
		*/
		bild.draw_rot
		(x, y, 0.0,
			rot, // Rotationswinkel in Grad
			0.5, 0.5 // Position der "Mitte"
		);
	}
};

int main()
{
	GameWindow window;
	window.show();
}