#include "color.h"
#define THRESHHOLD 0.01

color::color()	{
	setColor(0.0, 0.0, 0.0);
}

color::color(float red, float green, float blue)	{
	setColor(red, green, blue);
}

color::color(const float _color[3])	{
	setColor(_color);
}

color::color(const color& _color)	{
	setColor(_color[0], _color[1], _color[2]);
}

void color::operator=(const float _color[3])	{
	setColor(_color);
}

void color::operator=(const color _color)	{
	setColor(_color);
}

color color::operator+(const float _color[3]) const	{
	return color(Color[0] + _color[0], Color[1] + _color[1], Color[2] + _color[2]); 
}

color color::operator+(const color _color) const	{
	return color(Color[0] + _color[0], Color[1] + _color[1], Color[2] + _color[2]);
}

float color::operator[](const int index) const	{
	return Color[index];
}

void color::setColor(const float red, const float green, const float blue)	{
	Color[0] = red;
	Color[1] = green;
	Color[2] = blue;
}

void color::setColor(const float _color[3])	{
	Color[0] = _color[0];
	Color[1] = _color[1];
	Color[2] = _color[2];
}

void color::setColor(const color _color)	{
	Color[0] = _color[0];
	Color[1] = _color[1];
	Color[2] = _color[2];
}

void color::randomColor()	{
	setColor((float)(rand() % 101) / 101.0, (float)(rand() % 101) / 101.0, (float)(rand() % 101) / 101.0);
}

void color::killRed()	{
	Color[0] = 0.0;
}

void color::killGreen()	{
	Color[1] = 0.0;
}

void color::killBlue()	{
	Color[2] = 0.0;
}

void color::addToColor(const float red, const float green, const float blue)	{
	setColor(Color[0] + red, Color[1] + green, Color[2] + blue);
}

void color::addToColor(const float _color[3])	{
	setColor(Color[0] + _color[0], Color[1] + _color[1], Color[2] + _color[2]);
}

void color::addToColor(const color _color)	{
	setColor(Color[0] + _color[0], Color[1] + _color[1], Color[2] + _color[2]);
}

void color::addToColor(const float val, const int index)	{
	Color[index] += val;
}

std::string color::colorValues() const	{
	return std::to_string(Color[0]) + "," + std::to_string(Color[1]) + "," + std::to_string(Color[2]);
}

void color::insertColorValues(float (* _color)[3]) const	{
	*_color[0] = Color[0];
	*_color[1] = Color[1];
	*_color[2] = Color[2];
}

bool color::isBlack() const	{
	return (isGrey() && Color[0] < THRESHHOLD);
}

bool color::isWhite() const	{
	return (isGrey() && Color[0] > 1 - THRESHHOLD);
}

bool color::isGrey() const	{
	return ((abs(Color[0] - Color[1]) < THRESHHOLD) && (abs(Color[1] - Color[2]) < THRESHHOLD));
}