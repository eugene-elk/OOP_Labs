#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "StatisticMultiset.h"

Cache::Cache()
{
	change();
}

void Cache::change()
{
	changeAfterGetAvg = true;
	changeAfterGetCountUnder = true;
	changeAfterGetCountAbove = true;
}