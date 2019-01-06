#include <iostream>
#include <fstream>
#include "factor.h"

using namespace std;

int main() 
{
	factor A;
	string in_file, out_file;

	cout << "Input file: " << std::endl;
	cin >> in_file;
	cout << "Output file: " << std::endl;
	cin >> out_file;
	
	ifstream fin(in_file);
	ofstream fout(out_file);

	uint64_t current;
	while (!fin.eof()) 
	{
		fin >> current;
		A.createFactor(current);
		fout << A.getString() << std::endl;
	}
}