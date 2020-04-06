#include "pch.h"
#include "Polygon.h"

Polygon::Polygon(String^ name, Color color, cliext::list<Point> points)
	:Figure(name,color)
{
	this->points = points;
	this->initialPoints = points;
	for each (Point p in points)
	{
		Point newP(p.X * 0.5f, p.Y * 0.5f);
		deformPoints.push_front(newP);
	}
}

void Polygon::Draw(System::Drawing::Graphics^ g)
{
	Brush^ brush = gcnew SolidBrush(CurrentColor);

	g->FillPolygon(brush, points.to_array());
	g->DrawPolygon(gcnew Pen(System::Drawing::Color::Black), points.to_array());
	
}

Figure^ Polygon::Clone()
{
	return gcnew Polygon(Name, CurrentColor, points);
}

void Polygon::Move(float x, float y, float maxX, float maxY)
{
	cliext::list<Point> newPoint;
	bool canMove = true;
	for each (Point p in points)
	{
		if (!CanMove(p,x, y, maxX, maxY))
		{
			canMove = false;
			break;
		}
		Point newP(p.X + x, p.Y + y);
		newPoint.push_front(newP);
	}

	if (canMove) 
	{
		points = newPoint;
	}	
}

void Polygon::Reset()
{
	Figure::Reset(); 
	points = initialPoints;
}

bool Polygon::CanMove(Point p, float x, float y, float maxX, float maxY)
{
	return Figure::CanMove(p, x, y, maxX, maxY);
}

bool Polygon::CanMove(Figure^ f, float x, float y, float maxX, float maxY)
{
	for each (Point p in points)
	{
		if (!CanMove(p, x, y, maxX, maxY))
		{
			return false;
			break;
		}
	}

	return true;
}

float Polygon::MinX()
{
	float min = 0;
	for each (Point p in points)
	{
		if (min > p.X)
		{
			min = p.X;
		}
	}

	return min;
}

float Polygon::MaxX()
{
	float max = 0;
	for each (Point p in points)
	{
		if (max < p.X)
		{
			max = p.X;
		}
	}

	return max;
}

float Polygon::MinY()
{
	float min = 0;
	for each (Point p in points)
	{
		if (min > p.Y)
		{
			min = p.Y;
		}
	}

	return min;
}

float Polygon::MaxY()
{
	float max = 0;
	for each (Point p in points)
	{
		if (max > p.Y)
		{
			max = p.Y;
		}
	}

	return max;
}

void Polygon::Deformation()
{
	cliext::list<Point> tmp = deformPoints;
	deformPoints = points;
	points = deformPoints;	
}
