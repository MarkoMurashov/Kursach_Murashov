#include "pch.h"
#include "Figure.h"

Figure::Figure()
{
}

Figure::Figure(String^ name)
{
	Name = name;
}

Figure::Figure(String^ name, Color color)
	:Figure(name)
{
	InitialColor = color;
	CurrentColor = color;
}

Figure::Figure(String^ name, Point point, Color color)
	:Figure(name,color)
{
	InitialPoint = point;
	CurrentPoint = point;
}

void Figure::Draw(System::Drawing::Graphics^ g)
{
	throw gcnew System::NotImplementedException();
}

void Figure::ChangeColor(Color color)
{
	CurrentColor = color;
}

void Figure::Move(float x, float y, float maxX, float maxY)
{
	if (CanMove(CurrentPoint, x, y, maxX, maxY))
	{
		CurrentPoint.X += x;
		CurrentPoint.Y += y;
	}
}

void Figure::Reset()
{
	CurrentPoint = InitialPoint;
}

bool Figure::CanMove(Point p, float x, float y, float maxX, float maxY)
{
	return (p.X + x < maxX && p.X + x> -5) 
		&& (p.Y + y < maxY && p.Y + y > -5);;

}

bool Figure::CanMove(Figure^ f, float x, float y, float maxX, float maxY)
{
	return f->CanMove(f->CurrentPoint, x, y, maxX, maxY);
}

void Figure::ChangeAutoCoef()
{
	AutoCoef *= -1;
}
