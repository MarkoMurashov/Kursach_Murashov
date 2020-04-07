#include "pch.h"
#include "Polygon.h"

Polygon::Polygon(String^ name, Color color, List<Point>^ points)
	:Figure(name,color)
{
	this->points = points;
	this->initialPoints = points;
	for each (Point p in points)
	{
		Point newP(p.X * 0.5f, p.Y * 0.5f);
		deformPoints->Add(newP);
	}
}

void Polygon::Draw(System::Drawing::Graphics^ g)
{
	Brush^ brush = gcnew SolidBrush(CurrentColor);

	g->FillPolygon(brush, points->ToArray());
	g->DrawPolygon(gcnew Pen(System::Drawing::Color::Black), points->ToArray());
	
}

Figure^ Polygon::Clone()
{
	return gcnew Polygon(Name, CurrentColor, points);
}

void Polygon::Move(float x, float y, float maxX, float maxY)
{
	List<Point>^ newPoint = gcnew List<Point>;
	bool canMove = true;
	for each (Point p in points)
	{
		if (!CanMove(p,x, y, maxX, maxY))
		{
			canMove = false;
			break;
		}
		Point newP(p.X + x, p.Y + y);
		newPoint->Add(newP);
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
	float min = points[0].X;
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
	float max = points[0].X;
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
	float min = points[0].Y;
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
	float max = points[0].Y;
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
	List<Point>^ tmp = deformPoints;
	deformPoints = points;
	points = deformPoints;	
}
