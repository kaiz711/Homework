#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Shape.h"
#include "Circle.h"
#include "draw.h"
#include "Triangle.h"
#include "Square.h"
#include <vector>

const int width = 640;
const int height = 480;

double xpos, ypos;

float* pixels = new float[width*height * 3];
GLFWwindow* window;

using namespace std;
vector<Shape*> my_shape;

template<class T>
class Geometric : public Shape
{
public:
	void draw()
	{
		T drawShape;
		drawShape.draw();
	}
};

void drawPixel(const int& i, const int& j, const float& red, const float&green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i0 == i1)
	{
		for (int j = j0; j < j1; j++)
			drawPixel(i0, j, red, green, blue);
		return;
	}

	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawOnPixelBuffer(double xpos, double ypos)
{
	std::fill_n(pixels, width*height * 3, 1.0f);

	Shape shape_list;

	my_shape.push_back(shape_list.getShape("Square"));
	my_shape.push_back(shape_list.getShape("Circle"));
	my_shape.push_back(shape_list.getShape("Triangle"));
	my_shape.push_back(shape_list.getShape("rightArrow"));
	my_shape.push_back(shape_list.getShape("leftArrow"));
	my_shape.push_back(shape_list.getShape("CrossLine"));
	my_shape.push_back(shape_list.getShape("Lion"));
	my_shape.push_back(shape_list.getShape("downArrow"));
	my_shape.push_back(shape_list.getShape("upArrow"));
	my_shape.push_back(shape_list.getShape("BoldLine"));
	//my_shape.push_back(new Geometric<Box>);
	//my_shape.push_back(new Geometric<Triangle>);
	//my_shape.push_back(new Geometric<Box>);
	//my_shape.push_back(new Geometric<Box>);
	//my_shape.push_back(new Geometric<Box>);

	int ini_x = 100;
	int ini_y = 80;
	int size = 50;
	float red = 1.0f;
	float green = 0.0f;
	float blue = 0.0f;

	for (int i = 0; i < 2; i++)
	{
		for (auto itr : my_shape)
		{
			itr->setting(ini_x, ini_y, size, red, green, blue);
			ini_x += 110;
			if (ini_x > 540)
			{
				ini_x = 100;
				ini_y += 100;
			}

			itr->draw();
			itr->drawCircle(xpos, ypos);
		}
	}

	my_shape.clear();
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background
	bool inside = false;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* get Cursor pos */
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		//printf("%04.1lf\t%04.1lf\n", xpos, ypos);

		/* ALL Drawing Function is here */
		drawOnPixelBuffer(xpos, ypos);

		/* Drawing Buffer on window */
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}