#include "upArrow.h"
#include "Draw.h"

void upArrow::draw()
{
	drawLine(this->x, this->y - size / 2, this->x, this->y + size / 2, red, blue, green);
	drawLine(this->x - 20, this->y, this->x, this->y + size / 2, red, blue, green);
	drawLine(this->x, this->y + size / 2, this->x + 20, this->y, red, blue, green);
}