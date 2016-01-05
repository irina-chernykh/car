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

};

void UpdateSpeed(Event event, float time, Car * car);
void UpdateRotation(Event event, float time, Car * car);
void MoveParts(Car * car);
void PositionCarParts(Car * car);
void DrawCar(RenderWindow &window, Car * car);