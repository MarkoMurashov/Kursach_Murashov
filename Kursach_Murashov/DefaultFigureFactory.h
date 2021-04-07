#pragma once
#include <map>
#include <string>
#include "Figure.h"

ref class DefaultFigureFactory
{
private:
    Dictionary<String^, Figure^>^ figures = gcnew Dictionary<String^, Figure^>;

public:
    String^ CIRCLE_NAME = "DEFAULT CIRCLE";
    String^ SQUARE_NAME = "DEFAULT SQUARE";
    String^ TRIANGLE_NAME = "DEFAULT TRIANGLE";
    String^ COMPOSITE_NAME = "DEFAULT COMPOSITE";

    DefaultFigureFactory();
    Figure^ GetDefaultFigure(String^ key);

};


