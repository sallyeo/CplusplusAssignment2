#ifndef A2_H
#define A2_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struct to store x and y values
struct xyPoint
{
	int xAxis;
	int yAxis;
};

// Super class
class ShapeTwoD
{
	protected:
		string name;
		bool containsWarpSpace;

	public:
		ShapeTwoD(string name, bool containsWarpSpace)
		{
			setName(name);
			setContainsWarpSpace(containsWarpSpace);
		}

		string getName();
		bool getContainsWarpSpace();
		void setName(string name);
		void setContainsWarpSpace(bool containsWarpSpace);

		// Virtual methods given by qns
		virtual string toString();
		virtual double computeArea(){return 0.0;}
		virtual bool isPointInShape(int x, int y){return false;}
		virtual bool isPointOnShape(int x, int y){return false;}

		// Additional methods
		virtual void setXYPoints(xyPoint){};

		// Min Max value to determine the range when checking whether if there's any Point in/on the Shape
		virtual void setXYMinMax(){};

		virtual void setRadius(int){};
		virtual void sortXYPoints(){};
		virtual double getArea(){return 0.0;}		
};

// Sub-class circle
class Circle : public ShapeTwoD
{
	public:
		const double PI = 3.141592;

		int minXAxis, maxXAxis;
		int minYAxis, maxYAxis;

		xyPoint center;
		double radius;
		double area = 0.0;
		
		// Derived constructor
		Circle(string name, bool containsWarpSpace) : ShapeTwoD(name, containsWarpSpace)
		{

		}

		// Inherits
		virtual string toString() override;
		virtual double computeArea() override;
		virtual bool isPointInShape(int x, int y) override;
		virtual bool isPointOnShape(int x, int y) override;

		virtual void setXYPoints(xyPoint) override;
		virtual void setXYMinMax() override;
		virtual void setRadius(int);

		virtual double getArea() override;
};

// Sub-class
class Square : public ShapeTwoD
{
	public:
		int minXAxis, maxXAxis;
		int minYAxis, maxYAxis;
		double area = 0.0;

		// Vector of xyPoint struct to store coordinates and use later on
		vector <xyPoint> squarePts;

		Square(string name, bool containsWarpSpace) : ShapeTwoD(name, containsWarpSpace)
		{

		}

		// Inherits
		virtual string toString() override;
		virtual double computeArea() override;
		virtual bool isPointInShape(int x, int y) override;
		virtual bool isPointOnShape(int x, int y) override;

		virtual void setXYPoints(xyPoint) override;
		virtual void setXYMinMax() override;

		virtual double getArea() override;
};

//Sub-class
class Rectangle : public ShapeTwoD
{
	public:
		int minXAxis, maxXAxis;
		int minYAxis, maxYAxis;
		double area = 0.0;
		vector <xyPoint> rectanglePts;

		Rectangle(string name, bool containsWarpSpace) : ShapeTwoD(name, containsWarpSpace)
		{

		}

		virtual string toString() override;
		virtual double computeArea() override;
		virtual bool isPointInShape(int x, int y) override;
		virtual bool isPointOnShape(int x, int y) override;

		virtual void setXYPoints(xyPoint) override;
		virtual void setXYMinMax() override;

		virtual double getArea() override;
};

// Sub-class
class Cross : public ShapeTwoD
{
	public:
		int minXAxis, maxXAxis;
		int minYAxis, maxYAxis;
		double area;
		vector <xyPoint> crossPts;

		Cross(string name, bool containsWarpSpace) : ShapeTwoD(name, containsWarpSpace)
		{

		}

		// Inherits
		virtual string toString() override;
		virtual double computeArea() override;
		virtual bool isPointInShape(int x, int y) override;
		virtual bool isPointOnShape(int x, int y) override;

		virtual void setXYPoints(xyPoint) override;
		virtual void setXYMinMax() override;
		virtual void sortXYPoints() override;

		virtual double getArea() override;		
};

// Function prototypes
int mainMenu();
void processChoice(int);
void inputData();
void computeArea();
void printShapesSummary();
bool compareDescending(ShapeTwoD* shape1, ShapeTwoD* shape2);
bool compareTypeThenArea(ShapeTwoD* shape1, ShapeTwoD* shape2);
void sortData();
void resetScreen();
void returnMainMenu();
bool sortXY(xyPoint point1, xyPoint point2);
// End of function prototypes

#endif