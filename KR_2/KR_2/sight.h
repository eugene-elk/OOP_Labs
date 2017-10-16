//Evgeny Lositsky 3205

#pragma once

#include <string>

class sight
{
private:
	std::string name;
	std::string description;

	int posX, posY;
public:
	sight();
	sight(const std::string& name, const std::string& des, int X, int Y);

	std::string getName();
	std::string getDescription();

	double getDistance(int myPosX, int myPosY);
};