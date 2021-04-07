#include "pch.h"
#include "DefaultFigureFactory.h"
#include "Circle.h"
#include "Square.h"
#include "Polygon.h"
#include "Composite.h"

DefaultFigureFactory::DefaultFigureFactory()
{
	Point point(150.0, 20.0);
	float width = 50.0;
	float height = 50.0;

	Figure^ circle = gcnew Circle(CIRCLE_NAME, point, Color::Green, width, height);
	figures->Add(CIRCLE_NAME, circle);

	Point sqPoint(20.0, 20.0);
	width = 50.0;
	height = 50.0;

	Figure^ square = gcnew Square(SQUARE_NAME, sqPoint, Color::Red, width, height);
	figures->Add(SQUARE_NAME, square);

	Point point1(100, 100);
	Point point2(200, 130);
	Point point3(150, 200);

	List<Point>^ points = gcnew List<Point>;
	points->Add(point1);
	points->Add(point2);
	points->Add(point3);

	Figure^ polygon = gcnew Polygon(TRIANGLE_NAME, Color::Blue, points);
	figures->Add(TRIANGLE_NAME, polygon);

	List<Figure^>^ listFigures = gcnew List<Figure^>();

	Point point4(200, 200);
	Point point5(300, 230);
	Point point6(250, 300);

	List<Point>^ pointsForComposite = gcnew List<Point>;
	pointsForComposite->Add(point4);
	pointsForComposite->Add(point5);
	pointsForComposite->Add(point6);

	Figure^ polygonForComposite = gcnew Polygon(TRIANGLE_NAME + "2", Color::Olive, pointsForComposite);
	listFigures->Add(polygonForComposite);

	Point pointForComposite(250.0, 100.0);
	width = 50.0;
	height = 50.0;

	Figure^ circleForComposite = gcnew Circle(CIRCLE_NAME + "2", pointForComposite, Color::Olive, width, height);
	listFigures->Add(circleForComposite);

	Composite^ comp = gcnew Composite(COMPOSITE_NAME, listFigures);
	figures->Add(COMPOSITE_NAME, comp);
}

Figure^ DefaultFigureFactory::GetDefaultFigure(String^ key)
{
	if (figures->ContainsKey(key))
		return  figures[key];
	else
		return nullptr;
}
