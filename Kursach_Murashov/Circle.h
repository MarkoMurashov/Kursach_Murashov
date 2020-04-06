#include "Figure.h"

[Serializable]
#pragma once
ref class Circle : public Figure
{

private:
	float currentWidth;
	float currentHeight;
	float initialWidth;
	float initailHeight;
	float deformWidth;
	float deformHeight;
public:
	Circle(String^ name, Point point, Color color, float width, float height);
	void Draw(System::Drawing::Graphics^ g) override;
	Figure^ Clone() override;
	void Reset() override;

	float MinX() override;
	float MaxX() override;
	float MinY() override;
	float MaxY() override;
	void Deformation() override;
};

