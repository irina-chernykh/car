#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"

using namespace sf;

struct Car {
	Sprite carBody;
	CircleShape frontWheel;
	CircleShape rearWheel;

	float acceleration = 0.0009;
	float rotation = 0;
	float speed = 0;
	bool speedReduction;

	Vector2f carCoord = { 0, 200 };

	void CounterSpeed(Event event, float time)
	{
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
		{
			speed += acceleration * time;
			speedReduction = true;
		}
		else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
		{
			speed -= acceleration * time;
			speedReduction = false;
		}
		else {

			if ((speed > 0) && (speedReduction))
			{
				speed -= (acceleration * time) / 2;
			}
			if ((speed < 0) && (!speedReduction))
				speed += (acceleration * time) / 2;
		}
		CounterRotation(event, time);
	}

	void CounterRotation(Event event, float time)
	{
		carCoord.x += speed;
		rotation = carCoord.x * 360 / CIRCLE_LENGTH;
		MoveParts();
	}

	void MoveParts()
	{
		car.carBody.setPosition(BODY_X + carCoord.x, WINDOW_Y - 50);

		car.frontWheel.setPosition(FRONT_WHEEL_X + carCoord.x, WINDOW_Y - FRONT_WHEEL_RADIUS);
		car.frontWheel.setRotation(rotation);

		car.rearWheel.setPosition(REAR_WHEEL_X + carCoord.x, WINDOW_Y - REAR_WHEEL_RADIUS);
		car.rearWheel.setRotation(rotation);
	}
}car;