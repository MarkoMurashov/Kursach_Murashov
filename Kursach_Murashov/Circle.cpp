#include "pch.h"
#include "Circle.h"

Circle::Circle(String^ name, Point point, Color color, float width, float height)
	:Figure(name, point, color)
{
	currentWidth = width;
	currentHeight = height;
	initialWidth = width;
	initailHeight = height;
	deformWidth = width * 0.5f;
	deformHeight = height * 0.5f;
}

void Circle::Draw(System::Drawing::Graphics^ g)
{
	Brush^ brush = gcnew SolidBrush(CurrentColor);

	g->FillEllipse(brush, (float)CurrentPoint.X, (float)CurrentPoint.Y, currentWidth, currentHeight);
	g->DrawEllipse(gcnew Pen(System::Drawing::Color::Black), (float)CurrentPoint.X, (float)CurrentPoint.Y, currentWidth, currentHeight);
}

Figure^ Circle::Clone()
{
	return gcnew Circle(Name, CurrentPoint, CurrentColor, currentWidth, currentHeight);
}

void Circle::Reset()
{
	Figure::Reset();
	currentWidth = initialWidth;
	currentHeight = initailHeight;
}

float Circle::MinX()
{
	return CurrentPoint.X;
}

float Circle::MaxX()
{
	return CurrentPoint.X + currentWidth;
}

float Circle::MinY()
{
	return CurrentPoint.Y;
}

float Circle::MaxY()
{
	return CurrentPoint.Y + currentHeight;
}

void Circle::Deformation()
{
	float tmp = currentWidth;
	currentWidth = deformWidth;
	deformWidth = tmp;

	tmp = currentHeight;
	currentHeight = deformHeight;
	deformHeight = tmp;
}
