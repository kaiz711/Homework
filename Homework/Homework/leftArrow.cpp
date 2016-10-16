#include "leftArrow.h"
#include "Draw.h"

void leftArrow::draw()
{
	drawLine(this->x - size / 2, this->y, this->x + size / 2, this->y, red, blue, green);
	drawLine(this->x - size / 2, this->y, this->x, this->y - size / 2, red, blue, green);
	drawLine(this->x - size / 2, this->y, this->x, this->y + size / 2, red, blue, green);
}