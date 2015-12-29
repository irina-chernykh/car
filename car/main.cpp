#include <SFML/Graphics.hpp>
#include<iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "const.h"
#include "car.h"

using namespace sf;

void DrawObjects(RenderWindow &window, Car &car, RectangleShape background)
{
	window.clear();
	window.draw(background);
	window.draw(car.carBody);
	window.draw(car.frontWheel);
	window.draw(car.rearWheel);
	window.display();
}

void PositionCarParts()
{
	car.frontWheel.setRadius(FRONT_WHEEL_RADIUS);
	car.frontWheel.setOrigin(FRONT_WHEEL_RADIUS, FRONT_WHEEL_RADIUS);

	car.rearWheel.setRadius(REAR_WHEEL_RADIUS);
	car.rearWheel.setOrigin(REAR_WHEEL_RADIUS, REAR_WHEEL_RADIUS);

}

void DrawCar(RenderWindow &window) 
{
	window.clear(Color::White);
	window.draw(car.carBody);
	window.draw(car.frontWheel);
	window.draw(car.rearWheel);
	window.display();
}

void MoveCar(RenderWindow &window, float acceleration)
{
	PositionCarParts();
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

		car.CounterSpeed(event, time);
		DrawCar(window);

	}
}

int main()
{
	RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), "Car");

	Texture body, frontWheel, rearWheel;
	body.loadFromFile("images/car.psd");
	frontWheel.loadFromFile("images/wheel1.psd");
	rearWheel.loadFromFile("images/wheel2.psd");

	car.carBody.setTexture(body);

	car.frontWheel.setTexture(&frontWheel);
	car.frontWheel.setOrigin(FRONT_WHEEL_RADIUS, FRONT_WHEEL_RADIUS);

	car.rearWheel.setTexture(&rearWheel);
	car.rearWheel.setOrigin(REAR_WHEEL_RADIUS, REAR_WHEEL_RADIUS);

	RectangleShape background;

	MoveCar(window, car.acceleration);

	return 0;
}