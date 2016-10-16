#include "Square.h"
#include "Draw.h"

void Square::draw()
{
	int size = this->size - 20;
	int i0 = this->x - size;
	int i1 = this->x + size;
	int j0 = this->y - size;
	int j1 = this->y + size;

	drawLine(i0, j0, i0, j1, red, green, blue);
	drawLine(i0, j0, i1, j0, red, green, blue);
	drawLine(i0 + 2 * size, j0, i0 + 2 * size, j1, red, green, blue);
	drawLine(i0, j0 + 2 * size, i1, j0 + 2 * size, red, green, blue);
}