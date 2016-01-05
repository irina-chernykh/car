#include <SFML/Graphics.hpp>
#include "const.h"
#include "car.h"

using namespace sf;

void UpdateSpeed(Event event, float time, Car * car)
{
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
	{
		car->speed += car->acceleration * time;
		car->speedReduction = true;
	}
	else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
	{
		car->speed -= car->acceleration * time;
		car->speedReduction = false;
	}
	else {

		if ((car->speed > 0) && (car->speedReduction))
		{
			car->speed -= (car->acceleration * time) / 2;
		}
		if ((car->speed < 0) && (!car->speedReduction))
			car->speed += (car->acceleration * time) / 2;
	}
	UpdateRotation(event, time, car);
}

void UpdateRotation(Event event, float time, Car * car)
{
	car->carCoord.x += car->speed;
	car->rotation = car->carCoord.x * 360 / CIRCLE_LENGTH;
	MoveParts(car);
}

void MoveParts(Car * car)
{
	car->carBody.setPosition(BODY_X + car->carCoord.x, WINDOW_Y - 50);

	car->frontWheel.setPosition(FRONT_WHEEL_X + car->carCoord.x, WINDOW_Y - FRONT_WHEEL_RADIUS);
	car->frontWheel.setRotation(car->rotation);

	car->rearWheel.setPosition(REAR_WHEEL_X + car->carCoord.x, WINDOW_Y - REAR_WHEEL_RADIUS);
	car->rearWheel.setRotation(car->rotation);
}