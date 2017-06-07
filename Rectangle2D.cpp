#include <iostream>
#include <cmath>
#include "Rectangle2D.h"
using namespace std;

//set up the default rectangle properties
Rectangle2D::Rectangle2D()
{
	x = 0;
	y = 0;
	width = 1;
	height = 1;
}

//set up a new object
Rectangle2D::Rectangle2D(double x, double y, double width, double height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

//returns the value of x
double Rectangle2D::getx() const
{
	return x;
}

//returns the value of y
double Rectangle2D::gety() const
{
	return y;
}

//sets the value of x
void Rectangle2D::setx(double x)
{
	this->x = x;
}

//sets the value of y
void Rectangle2D::sety(double y)
{
	this -> y = y;
}

//returns the value of the width
double Rectangle2D::getWidth() const
{
	return width;
}

//returns the value of the height
double Rectangle2D::getHeight() const
{
	return height;
}

//set the width
void Rectangle2D::setWidth(double width)
{
	this ->width = width;
}

//set the height
void Rectangle2D::setHeight(double height)
{
	this->height = height;
}

//calculate the area of the rectangle
double Rectangle2D::getArea() const
{
	return width * height;
}

//calculate the perimeter of the rectangle
double Rectangle2D::getPerimeter() const
{
	return 2*(width*height);
}

//see if the rectangle contains a specified coordinate point
bool Rectangle2D::contains(double x, double y) const
{
	//if the coordinate's x and y values are less than the x and y values of the side lengths, then the point is within the rectangle
	if (abs(x) <= (this->x + width) / 2 && abs(y) <= (this->y+height)/2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//see if another rectangle is contained within the rectangle
bool Rectangle2D::contains(const Rectangle2D &r) const
{
	//if the points on the sides of the given rectangle is less than the point on the side of the other rectangle
	//the rectangle is within the other rectangle
	if ((r.getx()+r.getWidth())/2 <= (x+width)/2 && (r.getx()-r.getWidth())/2 >= (x-width)/2)
	{
		if ((r.gety() + r.getHeight()) / 2 <= (y + height) / 2 && (r.gety() - r.getHeight()) / 2 >= (y - height) / 2)
		{
			return true;
		}
	}
	else
	{
		return false;
	}

}

//see if another rectangle overlaps the rectangle
bool Rectangle2D::overlaps(const Rectangle2D &r) const
{
	//if points on both sides of the rectangle are greater than the ones on the other rectangle
	//the rectangles overlap
	if ((r.getx() + r.getWidth()) / 2 > (x + width) / 2 && (r.getx() - r.getWidth()) / 2 < (x - width) / 2)
	{
		if ((r.gety() + r.getHeight()) / 2 > (y + height) / 2 && (r.gety() - r.getHeight()) / 2 < (x - width) / 2)
		{
			return true;
		}
		else
		{
			return true;
		}
	}
	//however, if only one point on the side is greater than the one on the other rectangle
	//the rectangles also overlap
	else if ((r.gety() + r.getHeight()) / 2 > (y + height) / 2 && (r.gety() - r.getHeight()) / 2 < (x - width) / 2)
	{
		return true;
	}
	//if none of the points on the sides overlap, the rectangles do not overlap
	else
	{
		return false;
	}
}