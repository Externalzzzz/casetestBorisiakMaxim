#include "Shape.hpp"
#include <iostream>
#include <Windows.h>

DrawShape::DrawShape() //Standart construct
{
	shape_count = 0;
	shape_length = 0;
	shape_height = 0;
	shape_type = "";
}
DrawShape::DrawShape(std::string shape, int count, int height, int length, int radius) //Construct with parameters 
{
	shape_type = shape;
	shape_count = count;
	shape_length = length;
	shape_height = height;
	shape_radius = radius;
}
DrawShape::~DrawShape() //Destructor
{

}

 std::string DrawShape::get_shape() const // Geters
{	 
	return shape_type;
}


int DrawShape::get_count() const
{
	return shape_count;
}
int DrawShape::get_length() const
{
	return shape_length;
}

int DrawShape::get_radius() const
{
	return shape_radius;
}

void DrawShape::set_shape(std::string varshape) //setters
{
	shape_type = varshape;
}

void DrawShape::set_radius(int varradius)
{
	shape_radius = varradius;
}

void DrawShape::set_count(int varcount)
{
	shape_count = varcount;
}
void DrawShape::set_height(int varheight)
{
	shape_height = varheight;
}
void DrawShape::set_length(int varlength)
{
	shape_length = varlength;
}
int DrawShape::get_height() const
{
	return shape_height;
}
void DrawShape::Draw() //Function for drawing with winAPI
{
	system("cls");
	Info();
	HWND hwnd = GetConsoleWindow();
	HDC dc = GetDC(hwnd);
	RECT window = {}; 
	HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
	HPEN hPen = (HPEN)GetStockObject(WHITE_PEN);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(dc, hBrush);
	HPEN hOldPen = (HPEN)SelectObject(dc, hPen);
	int AxisXOffset = 0, line = 0, counter = 0;
	if (shape_type == "circle")
	{ 
		int yAxisChange = 0,  oneLinePaint = 0;
		for (int paint_count = 0; paint_count < shape_count; paint_count++)
		{
			Ellipse(dc, counter * 60 * shape_radius + 50, 180 + AxisXOffset, counter * 60 * shape_radius + shape_radius * 50 + 50, 180 + shape_radius * 50 + AxisXOffset);
			line++;
			int limitAxisX = counter * 60 * shape_radius + shape_radius * 50 + 50;
			if (limitAxisX + counter * 60 * shape_radius + shape_radius * 50 + 50 > 2500)
			{
				counter = 0;
				AxisXOffset = shape_radius * line * shape_radius * 3;
			}
			else
				counter++;
		}

	}
	else  if (shape_type == "triangle")
	{
		
		for (int paint_count = 0; paint_count < shape_count; paint_count++)
		{
			POINT poly[3];
			BYTE polytype[3];
			poly[0].x = counter * 60 * shape_length + 50;
			poly[0].y = 180 + AxisXOffset;
			poly[1].x = counter * 60 * shape_length + 50;
			poly[1].y = 180 + shape_height * 50 + AxisXOffset;
			poly[2].x = counter * 60 * shape_length + shape_length * 50 + 50;
			poly[2].y = 180 + shape_height * 50 + AxisXOffset;
			polytype[0] = PT_LINETO;
			polytype[1] = PT_LINETO;
			polytype[2] = PT_LINETO;
			Polygon(dc, poly, 3);
			line++;
			int limitAxisX = counter * 60 * shape_length + shape_length * 50 + 50;
			if (limitAxisX + counter * 60 * shape_length + shape_length * 50 + 50 > 2500)
			{
				counter = 0;
				AxisXOffset = shape_height * 20 * line;
			}
			else
				counter++;
		}
	}
	else if (shape_type == "rectangle")
	{
		for (int paint_count = 0; paint_count < shape_count; paint_count++)
		{

			Rectangle(dc, counter * 60 * shape_length + 50, 180 + AxisXOffset, counter * 60 * shape_length + shape_length * 50 + 50, 180 + shape_height * 50 + AxisXOffset);
			line++;
			int limitAxisX = counter * 60 * shape_length + shape_length * 50 + 50;
			if (limitAxisX + counter * 60 * shape_length + shape_length * 50 + 50 > 2500)
			{
				//line++;
				counter = 0;
				AxisXOffset = shape_height * 20 * line;
			}
			else
				counter++;
		}
	}
	else if (shape_type == "square")
	{
		for (int paint_count = 0; paint_count < shape_count; paint_count++)
		{
			Rectangle(dc, counter * 60 * shape_height + 50, 180 + AxisXOffset, counter * 60 * shape_height + shape_height * 50 + 50, 180 + shape_height * 50 + AxisXOffset);
			line++;
			int limitAxisX = counter * 60 * shape_height + shape_height * 50 + 50;
			if (limitAxisX + counter * 60 * shape_height + shape_height * 50 + 50 > 2500)
			{
				//line++;
				counter = 0;
				AxisXOffset = shape_height * 30 * line;
			}
			else
				counter++;
		}
	}

	SelectObject(dc, hOldBrush);
	SelectObject(dc, hOldPen);
	ReleaseDC(NULL, dc);

	
}
void DrawShape::DrawStars() //Function for drawing with *
{
	system("cls");
	Info();
	if (shape_type == "circle")
	{
		for (int paint_count = 0; paint_count < shape_count; paint_count++)
		{
			for (int y = shape_radius; y >= -shape_radius; --y) {
				for (int x = -shape_radius; x <= shape_radius; ++x) {
					if ((int)sqrt(pow(x, 2) + pow(y, 2)) == shape_radius) std::cout << "*";
					else std::cout << " ";
				}
				std::cout << std::endl;
			}
		}
	}
	else  if (shape_type == "triangle")
	{
		for (int paint_count = 0; paint_count < shape_count; paint_count++)
		{
			std::cout << std::endl;
			for (int i = shape_length; i > 0; i--)
			{
				std::cout << "\t";
				for (int j = 0; j < i; j++)
					std::cout << '*';
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

	}
	else if (shape_type == "rectangle")
	{
		for (int paint_count = 0; paint_count < shape_count; paint_count++)
		{
			std::cout << std::endl;
			for (int i = shape_height; i > 0; i--)
			{
				std::cout << "\t";
				for (int j = 0; j < shape_length; j++)
					std::cout << '*';
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}


	}
	else if (shape_type == "square")
	{
		for (int paint_count = 0; paint_count < shape_count; paint_count++)
		{
			std::cout << std::endl;
			for (int i = shape_height; i > 0; i--)
			{
				std::cout << "\t";
				for (int j = 0; j < shape_height; j++)
					std::cout << '*';
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}


}
void DrawShape::Info() //About the shape
{
	std::cout <<"Shape type: " << shape_type << std::endl << "Number of shapes: " << shape_count << std::endl << "Shape height: " << shape_height << std::endl << "Shape length: " << shape_length << std::endl << "Shape radius (only for circle): " << shape_radius << std::endl;
}
