#include <iostream>
#include <cliext/list>
#include "pch.h"
#include "Square.h"
#include "Figure.h"

Square::Square(String^ name, Point point, Color color, float width, float height)
	: Figure(name, point, color)
{
	this->width = width;
	this->height = height;
	initialWidth = width;
	initialHeight = height;
	deformWidth = width * 0.5f;
	deformHeight = height * 0.5f;
}

void Square::Draw(System::Drawing::Graphics^ g)
{
	Brush^ brush = gcnew SolidBrush(CurrentColor);
	
	g->FillRectangle(brush, (float)CurrentPoint.X, (float)CurrentPoint.Y, width, height);
	g->DrawRectangle(gcnew Pen(System::Drawing::Color::Black), (float)CurrentPoint.X, (float)CurrentPoint.Y, width, height);
}

Figure^ Square::Clone()
{
	return gcnew Square(Name, CurrentPoint, CurrentColor, width, height);
}

void Square::Reset()
{
	Figure::Reset();
	width = initialWidth;
	height = initialHeight;
}

float Square::MinX()
{
	return CurrentPoint.X;
}

float Square::MaxX()
{
	return CurrentPoint.X + width;
}

float Square::MinY()
{
	return CurrentPoint.Y;
}

float Square::MaxY()
{
	return CurrentPoint.Y + height;
}

void Square::Deformation()
{
	float tmp = width;
	width = deformWidth;
	deformWidth = tmp;

	tmp = height;
	height = deformHeight;
	deformHeight = tmp;
}
