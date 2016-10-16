#include "BoldLine.h"
#include "Draw.h"

void BoldLine::draw()
{
	drawLine(this->x - size / 2, this->y - size / 2, this->x + size / 2, this->y + size / 2, red, blue, green);
	drawLine(this->x - size / 2, this->y - size / 2 + 1, this->x + size / 2 - 1, this->y + size / 2, red, blue, green);
	drawLine(this->x - size / 2 + 1, this->y - size / 2, this->x + size / 2, this->y + size / 2 - 1, red, blue, green);
}