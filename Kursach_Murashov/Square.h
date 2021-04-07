#include "Figure.h"

[Serializable]
#pragma once
ref class Square: public Figure
{

private:
	float width;
	float height;
	float initialWidth;
	float initialHeight;
	float deformWidth;
	float deformHeight;
public:
	Square(String^ name, Point point, Color color, float width, float height);
	void Draw(System::Drawing::Graphics^ g) override;
	Figure^ Clone() override;
	void Reset() override;

	float MinX() override;
	float MaxX() override;
	float MinY() override;
	float MaxY() override;
	void Deformation() override;
	void Draw(System::Drawing::Graphics^ g, float x, float y) override;
};

