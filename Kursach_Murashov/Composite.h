#include "Figure.h"

[Serializable]
#pragma once
ref class Composite :  Figure
{

private:
	cliext::list<Figure^> figures;
public:
	Composite(String^ name, cliext::list<Figure^> figures);
	void Draw(System::Drawing::Graphics^ g) override;
	Figure^ Clone() override;
	void ChangeColor(Color color) override;
	void Move(float x, float y, float maxX, float maxY) override;
	void Reset() override;
	bool CanMove(Figure^ f, float x, float y, float maxX, float maxY) override;
	void ChangeAutoCoef() override;

	float MinX() override;
	float MaxX() override;
	float MinY() override;
	float MaxY() override;
	void Deformation() override;
};

