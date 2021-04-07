#include <iostream>
#include <cliext/list>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace System;

[Serializable]
#pragma once
ref class Figure abstract
{
protected:
	Point InitialPoint;
	Point CurrentPoint;
	Color CurrentColor;
	Color InitialColor;

public:
	String^ Name;
	bool IsHidden = false;
	float AutoCoef = 5.0;
	Figure();
	Figure(String^ Name);
	Figure(String^ Name, Color color);
	Figure(String^ Name, Point point, Color color);
	//prototype
	virtual Figure^ Clone() = 0;
	virtual void Draw(System::Drawing::Graphics^ g);
	virtual void ChangeColor(Color color);
	virtual void Move(float x, float y, float maxX, float maxY);
	virtual void Reset();
	virtual bool CanMove(Point p, float x, float y, float maxX, float maxY);
	virtual bool CanMove(Figure^ f, float x, float y, float maxX, float maxY);
	virtual void ChangeAutoCoef();
	virtual void Draw(System::Drawing::Graphics^ g, float x, float y);

	virtual float MinX() = 0;
	virtual float MaxX() = 0;
	virtual float MinY() = 0;
	virtual float MaxY() = 0;
	virtual void Deformation() = 0;
};

