#pragma once

class Rectangle2D
{
public:
	Rectangle2D();
	Rectangle2D(double, double, double, double);

	double getx() const;
	double gety() const;
	void setx(double);
	void sety(double);

	double getWidth() const;
	double getHeight() const;
	void setWidth(double);
	void setHeight(double);

	double getArea() const;
	double getPerimeter() const;
	bool contains(double x, double y) const;
	bool contains(const Rectangle2D &r) const;
	bool overlaps(const Rectangle2D &r) const;

private:
	double x;
	double y;
	double width;
	double height;
};