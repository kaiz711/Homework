#include "Shape.h"
#include <vector>
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "leftArrow.h"
#include "rightArrow.h"
#include "CrossLine.h"
#include "Lion.h"
#include "downArrow.h"
#include "upArrow.h"
#include "BoldLine.h"


Shape* Shape::getShape(const std::string& name)
{
	if (name == "Circle")
		return new Circle;
	else if (name == "Square")
		return new Square;
	else if (name == "Triangle")
		return new Triangle;
	else if (name == "rightArrow")
		return new rightArrow;
	else if (name == "leftArrow")
		return new leftArrow;
	else if (name == "CrossLine")
		return new CrossLine;
	else if (name == "Lion")
		return new Lion;
	else if (name == "downArrow")
		return new downArrow;
	else if (name == "upArrow")
		return new upArrow;
	else if (name == "BoldLine")
		return new BoldLine;
	return nullptr;
}

Shape::Shape()
{
	this->red = 1.0f;
	this->blue = 0.0f;
	this->green = 0.0f;
}

Shape::Shape(int x0, int y0, float red, float blue, float green, int size)
{
	this->x = x0;
	this->y = y0;
	this->red = red;
	this->blue = blue;
	this->green = green;
	this->size = size;
}

void Shape::setting(const int& xpos, const int& ypos, const int& size, const float& red, const float& green, const float& blue)
{
	this->x = xpos;
	this->y = ypos;
	this->size = size;
	this->red = red;
	this->blue = blue;
	this->green = green;
}

void Shape::draw()
{

}

bool Shape::checkCursor(const double x, const double y, const double x_c, const double y_c, const double r)
{
	const double f = (x - x_c) * (x - x_c) + (y - y_c) * (y - y_c) - r * r;
	if (f > 0.0)
		return false;
	else
		return true;
}

void Shape::drawCircle(const double& xpos, const double& ypos)
{
	Shape *my_shape = new Circle();

	my_shape->size = this->size + 20;
	my_shape->x = this->x;
	my_shape->y = this->y;

	if (checkCursor(xpos, 480 - ypos, my_shape->x, my_shape->y, my_shape->size))
	{
		my_shape->green = 0.0f;
		my_shape->red = 0.0f;
		my_shape->blue = 1.0f;
	}

	else
	{
		my_shape->green = 0.0f;
		my_shape->red = 1.0f;
		my_shape->blue = 0.0f;
	}

	my_shape->draw();
}