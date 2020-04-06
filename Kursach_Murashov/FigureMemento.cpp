#include "pch.h"
#include "FigureMemento.h"

FigureMemento::FigureMemento(List<Figure^>^ figures)
{
	this->figures = figures;
}

List<Figure^>^ FigureMemento::GetFigures()
{
	return figures;
}
