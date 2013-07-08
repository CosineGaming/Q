#pragma once
#include <string>
#include "math.h"
#include "stdlib.h"

class color	{
public:
	color();
	color(const float red, const float green, const float blue);
	color(const float _color[3]);
	color(const color& _color);
	void operator=(const float _color[3]);
	void operator=(const color _color);
	color operator+(const float _color[3]) const;
	color operator+(const color _color) const;
	float operator[](const int index) const;
	void setColor(const float red, const float green, const float blue);
	void setColor(const float _color[3]);
	void setColor(const color _color);
	void randomColor();
	void killRed();
	void killGreen();
	void killBlue();
	void addToColor(const float red, const float green, const float blue);
	void addToColor(const float _color[3]);
	void addToColor(const color _color);
	void addToColor(const float val, const int index);
	std::string colorValues() const;
	void insertColorValues(float (* _color)[3]) const;
	bool isBlack() const;
	bool isWhite() const;
	bool isGrey() const;
private:
	float Color[3];
};