//Evgeny Lositsky 3205

#include <math.h>
#include "sight.h"

sight::sight()
{
	name = "";
	description = "";
	posX = 0;
	posY = 0;
}

sight::sight(const std::string& new_name, const std::string& des, int X, int Y)
{
	name = new_name;
	description = des;
	posX = X;
	posY = Y;
}

std::string sight::getName()
{
	return name;
}

std::string sight::getDescription()
{
	return description;
}

double sight::getDistance(int myPosX, int myPosY)
{
	return sqrt(((posX - myPosX)*(posX - myPosX)) + ((posY - myPosY)*(posY - myPosY)));
}

