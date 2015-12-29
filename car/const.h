#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

const int WINDOW_X = 1300;
const int WINDOW_Y = 400;
const int BODY_X = 0;
const int REAR_WHEEL_X = BODY_X + 40;
const int FRONT_WHEEL_X = BODY_X + 120;
const float FRONT_WHEEL_RADIUS = 23 / 2;
const float REAR_WHEEL_RADIUS = 23 / 2;
const float CIRCLE_LENGTH = 58 * 2 * M_PI;