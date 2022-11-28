#include "a2.h"

// Adds the xAxis and yAxis into a vector of xyPoint struct 
void Rectangle::setXYPoints(xyPoint p)
{
	rectanglePts.push_back(p);
}

// Min Max value to determine the range when checking whether if the coordinate is in/on the shape
void Rectangle::setXYMinMax()
{
	// Initialize the values of min max of x & y values
	minXAxis = rectanglePts[0].xAxis;
	maxXAxis = rectanglePts[0].xAxis;
	minYAxis = rectanglePts[0].yAxis;
	maxYAxis = rectanglePts[0].yAxis;

	// and then loop thru all 4 points and set the min max of x & y values
	for (int i = 1; i < rectanglePts.size(); i++)
	{
		if (minXAxis > rectanglePts[i].xAxis)
		{
			minXAxis = rectanglePts[i].xAxis;
		}
		else if (maxXAxis < rectanglePts[i].xAxis)
		{
			maxXAxis = rectanglePts[i].xAxis;
		}

		if (minYAxis > rectanglePts[i].yAxis)
		{
			minYAxis = rectanglePts[i].yAxis;
		}
		else if (maxYAxis < rectanglePts[i].yAxis)
		{
			maxYAxis = rectanglePts[i].yAxis;
		}
	}
}

// Check if any point is in the shape
bool Rectangle::isPointInShape(int x, int y)
{
	// Coordinate in shape
	if (x > minXAxis && x < maxXAxis && y > minYAxis && y < maxYAxis)
	{
		return true;
	}
	// Coordiate not in shape
	else
	{
		return false;
	}
}

// Check if any point is on the shape (not including the vertices)
bool Rectangle::isPointOnShape(int x, int y)
{
	// Check vertical sides of rectangle
	if ((x == minXAxis || x == maxXAxis) && y > minYAxis && y < maxYAxis)
	{
		return true;
	}
	// Check horizontal sides of rectangle
	else if ((y == minYAxis || y == maxYAxis) && x > minXAxis && x < maxXAxis)
	{
		return true;
	}
	// Coordinate not on shape
	else
	{
		return false;
	}
}

// Override super class function computeArea()
double Rectangle::computeArea()
{
	area = ((maxXAxis - minXAxis) * (maxYAxis - minYAxis));
	return area;
}

// Used for sorting according to area
double Rectangle::getArea()
{
	return area;
}

// Override super class method toString() to print the rectangle info
string Rectangle::toString()
{
	string outerPoints;
	string innerPoints;
	string vertices;
	int countOuterPts = 0;
	int countInnerPts = 0;

	// Loop thru all 4 points
	for (int i = 0; i < rectanglePts.size(); i++)
	{
		// to_string() converts numerical value to string
		vertices += "Point [" + to_string(i) + "]: (" + to_string(rectanglePts[i].xAxis) + ", " + to_string(rectanglePts[i].yAxis) + ")\n";
	}

	// To get all the points that's on the shape
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
	return (ShapeTwoD::toString() + "Area: " + to_string((int)area) + " units square" + "\nVertices:\n" + vertices + "\nPoints on perimeter: " + outerPoints + "\n" + "Points within shape: " + innerPoints + "\n");
}