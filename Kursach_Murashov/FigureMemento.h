#include "Figure.h"

using namespace System;

#pragma once

[Serializable]
ref class FigureMemento
{
	List<Figure^>^ figures = gcnew List<Figure^>();

public:
	FigureMemento(List<Figure^>^ figures);
	List<Figure^>^ GetFigures();

};

