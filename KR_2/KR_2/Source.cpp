//Evgeny Lositsky 3205

#include <iostream>
#include "sight.h"

using namespace std;

int main()
{
	sight fortress("Peter and Paul Fortress",
		"The Peter and Paul Fortress is the original citadel of St. Petersburg, Russia",
		10, 10);

	cout << fortress.getName() << endl;
	cout << fortress.getDescription() << endl;
	cout << fortress.getDistance(13, 14) << endl;

	return 0;
}