#include "iostream"
#include "StatisticMultiset.h"

using namespace std;

int main()
{
	StatisticMultiset <int> data1;
	StatisticMultiset <double> data2;

	try {
		data2.AddNum(1.1);
		data2.AddNum(2.2);
		data2.AddNum(4.4);

		cout << data2.GetMin() << endl;
		cout << data2.GetMax() << endl;
		cout << data2.GetAvg() << endl;
		cout << data2.GetCountAbove(1.5) << endl;
		cout << data2.GetCountUnder(1.5) << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	return 0;
}