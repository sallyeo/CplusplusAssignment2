#include "a2.h"

string ShapeTwoD::getName()
{
	return name;
}

// Boolean operator used in sorting based on Warp Space or Normal Space
bool ShapeTwoD::getContainsWarpSpace()
{
	return containsWarpSpace;
}

void ShapeTwoD::setName(string name)
{
	this->name = name;
}

void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
	this->containsWarpSpace = containsWarpSpace;
}

// toString() to print report
string ShapeTwoD::toString()
{
	if (containsWarpSpace == true)
	{
		return ("Name: " + getName() + "\nSpecial Type: " + "WS\n");
	}
	else
	{
		return ("Name: " + getName() + "\nSpecial Type: " + "NS\n");
	}
}