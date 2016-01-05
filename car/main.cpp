#include <SFML/Graphics.hpp>
#include<iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "const.h"
#include "car.h"

using namespace sf;

void DrawElements(RenderWindow &window, Car * car)
{
	window.clear(Color::White);
	DrawCar(window, car);
	window.display();
}

void WorkMainCycle(RenderWindow &window, float acceleration, Car * car)
{
	PositionCarParts(car);
	Clock clock;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time * acceleration;

		UpdateSpeed(event, time, car);
		DrawElements(window, car);

	}
}

int main()
{
	Car car;
	RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), "Car");

	Texture body;
	Texture frontWheel;
	Texture rearWheel;
	body.loadFromFile("images/car.png");
	frontWheel.loadFromFile("images/wheel1.png");
	rearWheel.loadFromFile("images/wheel2.png");

	car.carBody.setTexture(body);

	car.frontWheel.setTexture(&frontWheel);
	car.frontWheel.setOrigin(FRONT_WHEEL_RADIUS, FRONT_WHEEL_RADIUS);

	car.rearWheel.setTexture(&rearWheel);
	car.rearWheel.setOrigin(REAR_WHEEL_RADIUS, REAR_WHEEL_RADIUS);

	RectangleShape background;

	WorkMainCycle(window, car.acceleration, &car);

	return 0;
}