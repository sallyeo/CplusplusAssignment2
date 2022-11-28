#include "a2.h"

// Set radius of the Circle based on user input
void Circle::setRadius(int rad)
{
	radius = rad;
}

// set the center point of the circle
void Circle::setXYPoints(xyPoint p)
{
	center = p;
}

// Min Max value to determine the range when checking whether if there's any xyPoint in/on the shape
void Circle::setXYMinMax()
{
	minXAxis = center.xAxis - radius;
	maxXAxis = center.xAxis + radius;
	minYAxis = center.yAxis - radius;
	maxYAxis = center.yAxis + radius;
}

// To check if any points is in the shape
bool Circle::isPointInShape(int x, int y)
{
	// square the difference to eliminate the negative values
	// in shape if the radius is greater than the distance from center of circle to the coordinate of the point
	if ((x != center.xAxis && y != center.yAxis) && ((x - center.xAxis) * (x - center.xAxis) + (y - center.yAxis) * (y - center.yAxis) < radius * radius))
	{
        return true;
    }
    else
    {
        return false;
    }
}

// Check if any point is on the shape (not including the vertices)
bool Circle::isPointOnShape(int x, int y)
{
	// on shape if the radius is equal to distance from center of circle to the coordinate of the point
	if ((x - center.xAxis) * (x - center.xAxis) + (y - center.yAxis) * (y - center.yAxis) == radius * radius)
	{
        return true;
    }
    else
    {
        return false;
    }
}

// Override super class function computeArea()
double Circle::computeArea()
{
	area = PI * radius * radius;
	return area;
}

// Used for sorting according to area
double Circle::getArea()
{
	return area;
}


// Override super class method toString() to print the circle info
string Circle::toString()
{
	string outerPoints;
	string innerPoints;
	int countOuterPts = 0;
	int countInnerPts = 0;

	// To get all points that's on the shape
	for (int i = minXAxis; i <= maxXAxis; i++)
	{
		for (int k = minYAxis; k <= maxYAxis; k++)
		{
			if(isPointOnShape(i,k) == true && i >= 0 && k >= 0)
			{
				// to_string() converts numerical value to string
				outerPoints += ("(" + to_string(i) + "," + to_string(k) + ") ");
				countOuterPts++;
			}
		}
	}

	// To get all the points that's in the shape
	for (int i = minXAxis; i <= maxXAxis; i++)
	{
		for (int k = minYAxis; k <= maxYAxis; k++)
		{
			if(isPointInShape(i,k) == true && i >= 0 && k >= 0)
			{
				// to_string() converts numerical value to string
				innerPoints += ("(" + to_string(i) + "," + to_string(k) + ") ");
				countInnerPts++;
			}
		}
	}

	if (countOuterPts == 0)
	{
		outerPoints = "NIL!";
	}

	if (countInnerPts == 0)
	{
		innerPoints = "NIL!";
	}

	// to_string() converts numerical value to string
	// ShapeTwoD::toString() prints the Name and Special Type
	return (ShapeTwoD::toString() + "Area: " + to_string((int)area) + " units square" + "\nCenter: (" + to_string(center.xAxis) + ", " + to_string(center.yAxis) + ")\n" + "\nPoints on perimeter: " + outerPoints + "\n" + "Points within shape: " + innerPoints + "\n");
}