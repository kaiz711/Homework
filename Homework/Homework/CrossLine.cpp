#include "CrossLine.h"
#include "Draw.h"

void CrossLine::draw()
{
	drawLine(this->x - size / 2, this->y - size / 2, this->x + size / 2, this->y + size / 2, red, blue, green);
	drawLine(this->x - size / 2, this->y + size / 2, this->x + size / 2, this->y - size / 2, red, blue, green);
}