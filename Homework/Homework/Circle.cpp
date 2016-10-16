#include "Circle.h"
#include "Draw.h"

void Circle::draw()
{
	int size = this->size - 20;
	int x = this->x;
	int y = this->y;

	for (int i = x - size; i < x + size; i++)
	{
		for (int j = y - size; j < y + size; j++)
		{
			int n = (i - x) * (i - x) + (j - y) * (j - y) - (size - 1) * (size - 1) + 2 * size - 1;
			int n2 = (i - x) * (i - x) + (j - y) * (j - y) - (size - 2) * (size - 2) + 4 * size - 4;
			if (n < 0 && n2 > 0)
			{
				drawPixel(i, j, red, green, blue);
			}
		}
	}
}