#include "Figure.h"
#include "Scene.h"

#pragma once
ref class FigureSaver
{
private:
	FigureMemento^ fg;
	Scene^ scene;
	String^ path;
public:
	FigureSaver(Scene^ sc, String^ path);
	void Create();
	void Undo();
};

