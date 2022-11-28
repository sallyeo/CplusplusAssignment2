#include "a2.h"

// Add the xAxis and yAxis into a vector of xyPoint
void Cross::setXYPoints(xyPoint p)
{
	crossPts.push_back(p);
}

void Cross::sortXYPoints()
{
	sort(crossPts.begin(), crossPts.end(), sortXY);
}

// Min Max value to determine the range when checking whether if the coordinate is in/on the shape
void Cross::setXYMinMax()
{
	// Initialize the values of min max of x & y values
	minXAxis = crossPts[0].xAxis;
	maxXAxis = crossPts[0].xAxis;
	minYAxis = crossPts[0].yAxis;
	maxYAxis = crossPts[0].yAxis;

	// and then loop thru all 12 points and compare to get the min max of x & y values
	for (int i = 1; i < crossPts.size(); i++)
	{
		if (minXAxis > crossPts[i].xAxis)
		{
			minXAxis = crossPts[i].xAxis;
		}
		else if (maxXAxis < crossPts[i].xAxis)
		{
			maxXAxis = crossPts[i].xAxis;
		}

		if (minYAxis > crossPts[i].yAxis)
		{
			minYAxis = crossPts[i].yAxis;
		}
		else if (maxYAxis < crossPts[i].yAxis)
		{
			maxYAxis = crossPts[i].yAxis;
		}
	}
}

// Check if any point is in the shape
bool Cross::isPointInShape(int x, int y)
{
	if (x > crossPts[0].xAxis && x < crossPts[3].xAxis && y > crossPts[0].yAxis && y < crossPts[1].yAxis)
	{
		return true;
	}
	else if (x > crossPts[2].xAxis && x < crossPts[6].xAxis && y > crossPts[2].yAxis && y < crossPts[3].yAxis)
	{
		return true;
	}
	else if (x > crossPts[3].xAxis && x < crossPts[7].xAxis && y > crossPts[3].yAxis && y < crossPts[4].yAxis)
	{
		return true;
	}
	else if (x > crossPts[4].xAxis && x < crossPts[8].xAxis && y > crossPts[4].yAxis && y < crossPts[5].yAxis)
	{
		return true;
	}
	else if (x > crossPts[7].xAxis && x < crossPts[10].xAxis && y > crossPts[7].yAxis && y < crossPts[8].yAxis)
	{
		return true;
	}
	else if ((x == crossPts[2].xAxis || x == crossPts[6].xAxis) && y > crossPts[3].yAxis && y < crossPts[4].yAxis)
	{
		return true;
	}
	else if ((y == crossPts[3].yAxis || y == crossPts[4].yAxis) && x > crossPts[3].xAxis && x < crossPts[7].xAxis)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Check if any point is on the shape (not including the vertices)
bool Cross::isPointOnShape(int x, int y)
{
	// outer left and right vertical 
	if ((x == crossPts[0].xAxis || x == crossPts[10].xAxis) && y > crossPts[0].yAxis && y < crossPts[1].yAxis)
	{
		return true;
	}
	// left horizontal 
	else if ((y == crossPts[0].yAxis || y == crossPts[1].yAxis) && x > crossPts[0].xAxis && x < crossPts[3].xAxis)
	{
		return true;
	}
	// middle upper and bottom left right vertical
	else if ((x == crossPts[2].xAxis || x == crossPts[6].xAxis) && ((y > crossPts[4].yAxis && y < crossPts[5].yAxis) || (y > crossPts[2].yAxis && y < crossPts[3].yAxis)))
	{
		return true;
	}
	// right horizontal
	else if ((y == crossPts[7].yAxis || y == crossPts[8].yAxis) && x > crossPts[7].xAxis && x < crossPts[10].xAxis)
	{
		return true;
	}
	// middle horizontal
	else if ((y == crossPts[2].yAxis || y == crossPts[5].yAxis) && x > crossPts[2].xAxis && x < crossPts[6].xAxis)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Override super class function computeArea()
double Cross::computeArea()
{
	int outerSquareArea = ((maxYAxis-minYAxis)*(maxXAxis-minXAxis));
	int smallOuterSquares = ((crossPts[4].xAxis - crossPts[1].xAxis) * (crossPts[5].yAxis - crossPts[4].yAxis)) + ((crossPts[11].xAxis - crossPts[8].xAxis) * (crossPts[9].yAxis - crossPts[8].yAxis)) + ((crossPts[3].xAxis - crossPts[0].xAxis) * (crossPts[3].yAxis - crossPts[2].yAxis)) + ((crossPts[10].xAxis - crossPts[7].xAxis) * (crossPts[7].yAxis - crossPts[6].yAxis));

	area = outerSquareArea - smallOuterSquares;

	return area;
}

// Used for sorting according to area
double Cross::getArea()
{
	return area;
}

// Override super class toString() to print cross info
string Cross::toString()
{
	string outerPoints;
	string innerPoints;
	string vertices;
	int countOuterPts = 0;
	int countInnerPts = 0;

	// Loop thru all 4 points
	for (int i = 0; i < crossPts.size(); i++)
	{
		// to_string() converts numerical value to string
		vertices += "Point [" + to_string(i) + "]: (" + to_string(crossPts[i].xAxis) + ", " + to_string(crossPts[i].yAxis) + ")\n";
	}

	// To get all the points that's on shape
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
	
	// To get all the points that's in shape
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