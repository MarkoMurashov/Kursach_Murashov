#include "Figure.h"

[Serializable]
#pragma once
ref class Polygon: public Figure
{
private:
	List<Point>^ points = gcnew List<Point>;
	List<Point>^ initialPoints = gcnew List<Point>;;
	List<Point>^ deformPoints = gcnew List<Point>;;
public:
	Polygon(String^ name, Color color, List<Point>^ points);
	void Draw(System::Drawing::Graphics^ g) override;
	Figure^ Clone() override;
	void Move(float x, float y, float maxX, float maxY) override;
	void Reset() override;
	bool CanMove(Point p, float x, float y, float maxX, float maxY) override;
	bool CanMove(Figure^ f, float x, float y, float maxX, float maxY) override;

	float MinX() override;
	float MaxX() override;
	float MinY() override;
	float MaxY() override;
	void Deformation() override;
};

