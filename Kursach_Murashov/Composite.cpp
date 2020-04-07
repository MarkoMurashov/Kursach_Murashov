#include "pch.h"
#include "Composite.h"
#include "Figure.h"

Composite::Composite(String^ name, List<Figure^>^ figures)
	:Figure(name)
{
	for each (Figure ^ f in figures)
	{
		this->figures->Add(f->Clone());
	}
}

void Composite::Draw(System::Drawing::Graphics^ g)
{
	for each (Figure^ f in figures)
	{
		f->Draw(g);
	}
}

Figure^ Composite::Clone()
{ 
	return gcnew Composite(Name, this->figures);
}

void Composite::ChangeColor(Color color)
{
	for each (Figure ^ f in figures)
	{
		f->ChangeColor(color);
	}
}

void Composite::Move(float x, float y, float maxX, float maxY)
{
	for each (Figure ^ f in figures)
	{
		f->Move(x,y,maxX,maxY);
	}
}

void Composite::Reset()
{
	for each (Figure ^ f in figures)
	{
		f->Reset();
	}
}

bool Composite::CanMove(Figure^ f, float x, float y, float maxX, float maxY)
{
	for each (Figure ^ f in figures)
	{
		if (f->CanMove(f, x, y, maxX, maxY))
		{
			return false;
		}
	}

	return true;
}

void Composite::ChangeAutoCoef()
{
	for each (Figure ^ f in figures)
	{
		f->ChangeAutoCoef();
	}
}

float Composite::MinX()
{
	float min = figures[0]->MinX();;
	for each (Figure ^ f in figures)
	{
		float fMin = f->MinX();
		if (min > fMin) 
		{
			min = fMin;
		}
	}

	return min;
}

float Composite::MaxX()
{
	float max = figures[0]->MaxX();
	for each (Figure ^ f in figures)
	{
		float fMax = f->MaxX();
		if (fMax > max)
		{
			max = fMax;
		}
	}

	return max;
}

float Composite::MinY()
{
	float min = figures[0]->MinY();
	for each (Figure ^ f in figures)
	{
		float fMin = f->MinY();
		if (min > fMin)
		{
			min = fMin;
		}
	}

	return min;
}

float Composite::MaxY()
{
	float max = figures[0]->MaxY();;
	for each (Figure ^ f in figures)
	{
		float fMax = f->MaxY();
		if (max < fMax)
		{
			max = fMax;
		}
	}

	return max;
}

void Composite::Deformation()
{
	for each (Figure ^ f in figures)
	{
		f->Deformation();
	}
}
