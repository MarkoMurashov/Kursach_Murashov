#include "Figure.h"

[Serializable]
#pragma once
ref class Composite :  Figure
{

private:
	List<Figure^>^ figures = gcnew List<Figure^>;
public:
	Composite(String^ name, List<Figure^>^ figures);
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

