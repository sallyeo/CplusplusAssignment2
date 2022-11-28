#include "a2.h"

// Adds the xAxis and yAxis into a vector of xyPoint
void Square::setXYPoints(xyPoint p)
{
	squarePts.push_back(p);
}

// Min Max value to determine the range when checking whether the coordinate is in/on the shape
void Square::setXYMinMax()
{
	// Initialize the values of min max of x & y values
	minXAxis = squarePts[0].xAxis;
	maxXAxis = squarePts[0].xAxis;
	minYAxis = squarePts[0].yAxis;
	maxYAxis = squarePts[0].yAxis;

	// and then loop thru all 4 points and compare to get the min max of x & y values
	for (int i = 1; i < squarePts.size(); i++)
	{
		if (minXAxis > squarePts[i].xAxis)
		{
			minXAxis = squarePts[i].xAxis;
		}
		else if (maxXAxis < squarePts[i].xAxis)
		{
			maxXAxis = squarePts[i].xAxis;
		}

		if (minYAxis > squarePts[i].yAxis)
		{
			minYAxis = squarePts[i].yAxis;
		}
		else if (maxYAxis < squarePts[i].yAxis)
		{
			maxYAxis = squarePts[i].yAxis;
		}
	}
}

// Check if any point is in the shape
bool Square::isPointInShape(int x, int y)
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
bool Square::isPointOnShape(int x, int y)
{
	// Check vertical sides of the square
	if ((x == minXAxis || x == maxXAxis) && y > minYAxis && y < maxYAxis)
	{
		return true;
	}
	// Check horizontal sides of the square
	else if ((y == minYAxis || y == maxYAxis) && x > minXAxis && x < maxXAxis)
	{
		return true;
	}
	// Not on shape
	else
	{
		return false;
	}
}

// Override super class function computeArea()
double Square::computeArea()
{
	area = ((maxXAxis - minXAxis) * (maxYAxis - minYAxis));
	return area;
}

// Used for sorting according to area
double Square::getArea()
{
	return area;
}

// Override super class method toString() to print the square info
string Square::toString()
{
	string vertices;
	string outerPoints;
	string innerPoints;
	int countOuterPts = 0;
	int countInnerPts = 0;

	// Loop thru all 4 points
	for (int i = 0; i < squarePts.size(); i++)
	{
		// to_string() converts numerical value to string
		vertices += "Point [" + to_string(i) + "]: (" + to_string(squarePts[i].xAxis) + ", " + to_string(squarePts[i].yAxis) + ")\n";
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