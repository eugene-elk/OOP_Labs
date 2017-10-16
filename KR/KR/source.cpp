//Evgeny Lositsky 3205

#include <iostream>
#include <vector>
#include "my_vector.h"

using namespace std;

int main()
{
	vector<int> v1 = { 10, 20, 30, 40, 50, 60 };

	out<int> (v1);
	swap<int> (v1);
	out<int> (v1);

	return 0;
}