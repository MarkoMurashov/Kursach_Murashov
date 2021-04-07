#include "Figure.h"
#include "FigureMemento.h"

#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
ref class Scene
{
private:
	List<Figure^>^ figures = gcnew List<Figure^>();
	Bitmap^ bitmap;
	System::Drawing::Graphics^ graphics;
	Scene() {}
	Scene(const Scene%);
	static Scene _scene;

public:
	static Scene^ CreateScene(PictureBox^ pb);
	static void Clear();
	static void Clear(PictureBox^ pb);
	static void AddFigure(Figure^ f);
	static void DeleteFigure(String^ name);
	static Figure^ FindFigure(String^ name);
	static void Draw(PictureBox^ pb);
	static void Draw(PictureBox^ pb, String^ name);
	static void Draw(PictureBox^ pb, String^ name, float x, float y);
	static void ChangeFiguresColor(String^ name, Color color);
	static void HideFigure(String^ name);
	static void Move(String^ name, float x, float y);
	static void Reset(String^ name);
	static bool IsBorder(String^ name);
	static void ChangeAutoCoef(String^ name);
	static float GetAutoCoef(String^ name);
	static bool Influence(String^ name);
	static int GetFigureIndex(String^ name);

	FigureMemento^ CreateMemento();
	void Restore(FigureMemento^ memento);
	List<String^>^ GetFigureNames();
};

