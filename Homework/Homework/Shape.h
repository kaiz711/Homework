#pragma once
#include <string>

class Shape
{
public:
	int x, y, size;
	float red, blue, green;

	Shape();
	Shape(int x0, int y0, float red, float blue, float green, int size);
	Shape* getShape(const std::string& name);
	void setting(const int& xpos, const int& ypos, const int& size, const float& red, const float& green, const float& blue);
	virtual void draw();
	bool checkCursor(const double x, const double y, const double x_c, const double y_c, const double r);
	void Shape::drawCircle(const double& xpos, const double& ypos);
};