#include "a2.h"

// Global vector of ShapeTwoD super class
vector <ShapeTwoD*> shapes_vector;

// Function to clear screen
void resetScreen()
{
	system("clear");
} // End of resetScreen() ...

// To display the main menu
int mainMenu()
{
	int choice;

	cout << "Student ID 	: " << "4603229" << endl;
	cout << "Student Name 	: " << "SALLY" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Welcome to A2 Space Shape program!" << endl;
	cout << endl;
	cout << "1) 	Input sensor data" << endl;
	cout << "2) 	Compute area (for all records)" << endl;
	cout << "3) 	Print shapes report" << endl;
	cout << "4) 	Sort shape data" << endl;
	cout << "5) 	Quit" << endl;
	cout << endl;
	cout << "Please enter your choice: ";

	cin >> choice;

    // Validate user input is in range
	while (cin.fail() || choice < 1 || choice > 5) 
	{
		cout << "Please enter a valid choice: ";
		cin.clear();
		cin.ignore(520, '\n');
		cin >> choice;
	}

	return choice;
} // End of mainMenu() ...

// To display 
void returnMainMenu()
{
	char enter = 'a';
	cout << endl;

	while (enter != '\n') 
    {
        cout << "Press <enter> to go back to main menu";
        cin.get(enter);
        cin.ignore();
        cin.clear();
    }
    
    cout << endl;
	processChoice(mainMenu());
} // End of returnMainMenu()

// Option 1, input the type of shape and their coordinates
void inputData()
{
	string shape;
	string spaceType;
	bool isAWarpSpace;

	cout << endl << "[Input sensor data]" << endl;

	cout << "Please enter name of shape (circle/rectangle/square/cross): ";
	cin >> shape;

	// Convert input to lowercase
	transform(shape.begin(), shape.end(), shape.begin(), ::tolower);

	// validate input
	while (shape != "circle" && shape != "square" && shape != "rectangle" && shape != "cross")
	{
		cout << "Please enter a valid name of shape(circle/rectangle/square/cross): ";
		cin.clear();
		cin.ignore(520, '\n');
		cin >> shape;

		// Convert input to lowercase
		transform(shape.begin(), shape.end(), shape.begin(), ::tolower);
	}
	
	cout << "Please enter special type (ws/ns): ";
	cin >> spaceType;

	// Convert input to lowercase
	transform(spaceType.begin(), spaceType.end(), spaceType.begin(), ::tolower);

	while (spaceType != "ws" && spaceType != "ns")
	{
		cout << "Please enter a valid special type(ws/ns): ";
		cin.clear();
		cin.ignore(520, '\n');
		cin >> spaceType;

		// Convert input to lowercase
		transform(spaceType.begin(), spaceType.end(), spaceType.begin(), ::tolower);
	}

	// Space type
	if(spaceType == "ws")
	{
		isAWarpSpace = true;
	}
	else
	{
		isAWarpSpace = false;
	}

	// Circle Shape
	if(shape == "circle")
	{
		xyPoint p;
		int rad;

		// Add circle into shapes_vector
		shapes_vector.push_back(new Circle("Circle", isAWarpSpace));

		// Get user input for coordinates and radius of circle
		do
		{
			cout << "Please enter x-axis of pt.1: ";
			cin >> p.xAxis;
			cin.clear();
       		cin.ignore(520,'\n');
		} while (p.xAxis < 0);

		do
		{
			cout << "Please enter y-axis of pt.1: ";
			cin >> p.yAxis;
			cin.clear();
			cin.ignore(520,'\n');
		} while (p.yAxis < 0);

		shapes_vector[shapes_vector.size()-1]->setXYPoints(p);

		do
		{
			cout << "Please enter radius (units): ";
			cin >> rad;
			cin.clear();
			cin.ignore(520,'\n');
		} while (rad < 0);

		cout << endl;

		shapes_vector[shapes_vector.size()-1]->setRadius(rad);
		shapes_vector[shapes_vector.size()-1]->setXYMinMax();

		cout << "Record successfully stored. Going back to main menu …\n" << endl;
	}

	if(shape == "rectangle")
	{
		xyPoint p;
		int rad;

		// Add rectangle into the shapes_vector
		shapes_vector.push_back(new Rectangle("Rectangle", isAWarpSpace));

		// Loop 4 times because rectangle has 4 corner points
		for (int i = 1; i <= 4; i++)
		{
			do
			{
				cout << "Please enter x-ordinate of pt." << i << ": ";
				cin >> p.xAxis;
				cin.clear();
		   		cin.ignore(520,'\n');
			} while (p.xAxis < 0);

			do
			{
				cout << "Please enter y-ordinate of pt." << i << ": ";
				cin >> p.yAxis;
				cin.clear();
				cin.ignore(520,'\n');
			} while (p.yAxis < 0);

			cout << endl;

			shapes_vector[shapes_vector.size()-1]->setXYPoints(p);
		}

		shapes_vector[shapes_vector.size()-1]->setXYMinMax();

		cout << "Record successfully stored. Going back to main menu …\n" << endl;
	}

	if(shape == "square")
	{
		xyPoint p;
		int rad;

		// Add square into the shapes_vector
		shapes_vector.push_back(new Square("Square", isAWarpSpace));

		// Loop 4 times because square has 4 corner points
		for (int i = 1; i <= 4; i++)
		{
			do
			{
				cout << "Please enter x-ordinate of pt." << i << ": ";
				cin >> p.xAxis;
				cin.clear();
		   		cin.ignore(100,'\n');
			} while (p.xAxis < 0);

			do
			{
				cout << "Please enter y-ordinate of pt." << i << ": ";
				cin >> p.yAxis;
				cin.clear();
				cin.ignore(100,'\n');
			} while (p.yAxis < 0);

			cout << endl;

			shapes_vector[shapes_vector.size()-1]->setXYPoints(p);
		}

		shapes_vector[shapes_vector.size()-1]->setXYMinMax();

		cout << "Record successfully stored. Going back to main menu …\n" << endl;
	}

	if(shape == "cross")
	{
		xyPoint p;
		int rad;

		// Add cross into shapes_vector
		shapes_vector.push_back(new Cross("Cross", isAWarpSpace));

		// Loop 12 times for cross shape
		for (int i = 1; i <= 12; i++)
		{
			do
			{
				cout << "Please enter x-ordinate of pt." << i << ": ";
				cin >> p.xAxis;
				cin.clear();
		   		cin.ignore(520,'\n');
			} while (p.xAxis < 0);

			do
			{
				cout << "Please enter y-ordinate of pt." << i << ": ";
				cin >> p.yAxis;
				cin.clear();
				cin.ignore(520,'\n');
			} while (p.yAxis < 0);

			cout << endl;

			shapes_vector[shapes_vector.size()-1]->setXYPoints(p);
		}

		shapes_vector[shapes_vector.size()-1]->sortXYPoints();
		shapes_vector[shapes_vector.size()-1]->setXYMinMax();

		cout << "Record successfully stored. Going back to main menu …\n" << endl;
	}

	returnMainMenu();
} // End of inputData() ...

// To sort vector of struct xyPoint of Cross shape
bool sortXY (xyPoint point1, xyPoint point2)
{
    if(point1.xAxis < point2.xAxis)
    {
        return (true);
    }
    else if(point1.xAxis == point2.xAxis && point1.yAxis < point2.yAxis)
    {
        return (true);
    }
    return (false);
} // End of sortXY() ...

// Option 2, computes the area of all shapes by looping the shapes_vector and calling overridden super class method computeArea()
void computeArea()
{
	for(int i = 0; i < shapes_vector.size(); i++)
	{
		shapes_vector[i]->computeArea();
	}

	cout << "Computation completed! ( " << shapes_vector.size() << " records were updated )\n" << endl;

	returnMainMenu();
} // End of computeArea() ...

// Option 3, prints the report of all shapes by looping the shapes_vector and calling overridden super class method toString()
void printShapesSummary()
{
	cout << endl;

	for(int i = 0; i < shapes_vector.size(); i++)
	{
		cout << "Shape [" << i << "]\n" << shapes_vector[i]->toString() << endl;
	}

	returnMainMenu();
} // End of printShapesSummary() ...

// Boolean operator to sort shapes in descending order of area
bool compareDescending(ShapeTwoD* shape1, ShapeTwoD* shape2)
{
	return shape1->getArea() > shape2->getArea();
} // End of compareDescending() ...

// Boolean operator to sort shapes (WS then NS), and in descending order of area
bool compareTypeThenArea(ShapeTwoD* shape1, ShapeTwoD* shape2)
{
	if(shape1->getContainsWarpSpace() == true && shape2->getContainsWarpSpace() == false)
	{
		return true;
	}
	else if (shape1->getContainsWarpSpace() == false && shape2->getContainsWarpSpace() == true)
	{
		return false;
	}
	else if ((shape1->getContainsWarpSpace() == shape2->getContainsWarpSpace()) && (shape1->getArea() > shape2->getArea()))
	{
		return true;
	}
	return false;
} // End of compareTypeThenArea() ...

// Option 4, sorts the shapes according to user selection
void sortData()
{
	char sortOption;

	cout << endl;
	cout << "a) 	Sort by area (ascending)" << endl;
	cout << "b) 	Sort by area (descending)" << endl;
	cout << "c) 	Sort by special type and area" << endl << endl;

	do
	{
		cout << "Please select sort option ('q' to go main menu): ";
		cin >> sortOption;
		cin.ignore(520,'\n');
	} while (sortOption != 'q' && sortOption != 'a' && sortOption != 'b' && sortOption != 'c');

	cout << endl;

	switch (sortOption)
	{
		case 'q':
			resetScreen();
			processChoice(mainMenu());
			break;
		case 'a':
			// By default is sort in ascending order
			sort(shapes_vector.begin(), shapes_vector.end());
			cout << "Sort by area (smallest to largest)..." << endl << endl;
			for(int shapeNum = 0; shapeNum < shapes_vector.size(); shapeNum++)
			{
				cout << "Shape [" << shapeNum << "]\n" << shapes_vector[shapeNum]->toString() << endl;
			}
			returnMainMenu();
			break;
		case 'b':
			sort(shapes_vector.begin(), shapes_vector.end(), compareDescending);
			cout << "Sort by area (largest to smallest)..." << endl << endl;
			for(int shapeNum = 0; shapeNum < shapes_vector.size(); shapeNum++)
			{
				cout << "Shape [" << shapes_vector.size() - 1 - shapeNum << "]\n" << shapes_vector[shapeNum]->toString() << endl;
			}
			returnMainMenu();
			break;
		case 'c':
			sort(shapes_vector.begin(), shapes_vector.end(), compareTypeThenArea);
			cout << "Sort by type and area..." << endl << endl;
			for(int shapeNum = 0; shapeNum < shapes_vector.size(); shapeNum++)
			{
				cout << "Shape [" << shapes_vector.size() - 1 - shapeNum << "]\n" << shapes_vector[shapeNum]->toString() << endl;
			}
			returnMainMenu();
			break;
	}

} // End of sortData() ...

// processChoice() takes in mainMenu() as parameter to call the rest of the function based on user input
void processChoice(int choice)
{
	switch(choice)
	{
		case 1:
			inputData();
			break;
		case 2:
			computeArea();
			break;
		case 3:
			printShapesSummary();
			break;
		case 4:
			sortData();
			break;
		case 5:
			// Additional code to delete all the shapes saved in the vector of ShapeTwoD
			for (ShapeTwoD* s : shapes_vector)
			{
				delete s;
			}
			cout << "Exiting Program successfully!" << endl;
			exit(0);
			break;
	}
}