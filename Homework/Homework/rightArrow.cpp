#include "rightArrow.h"
#include "Draw.h"

void rightArrow::draw()
{
	drawLine(this->x - size / 2, this->y, this->x + size / 2, this->y, red, blue, green);
	drawLine(this->x, this->y - size / 2, this->x + size / 2, this->y, red, blue, green);
	drawLine(this->x, this->y + size / 2, this->x + size / 2, this->y, red, blue, green);
}