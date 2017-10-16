#include <iostream>
#include "ini_parser.h"

using namespace std;

int main()
{
	IniParser file1;
	try
	{
		file1.Initialize("test.txt");
		
		int val1 = file1.GetValue<int>("NCMD", "EnableChannelControl");
		cout << val1 << endl;

		string val2 = file1.GetValue<string>("COMMON", "DiskCachePath");
		cout << val2 << endl;

		double val3 = file1.GetValue<double>("ADC_DEV", "BufferLenSeconds");
		cout << val3 << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
	return 0;
}