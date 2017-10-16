#pragma once

#include "exceptions.h"
#include "Cache.h"
#include <vector>
#include <set>
#include <list>

template <class T>
class StatisticMultiset {
private:

	multiset <T> dataset;
	Cache save;

public:

	StatisticMultiset();
	~StatisticMultiset() = default;

	void AddNum(T num);
	
	void AddNum(const std::multiset<T>& numbers);

	void AddNum(const std::vector<T>& numbers);

	void AddNum(const std::list<T>& numbers);

	void AddNum(const string& filename)
		throw (exc_io);

	void AddNum(const StatisticMultiset& a_stat_set);

	T GetMax() const
		throw(exc_empty_multiset);

	T GetMin() const
		throw(exc_empty_multiset);

	float GetAvg() const
		throw(exc_empty_multiset);

	int GetCountUnder(float threshold) const
		throw(exc_empty_multiset);

	int GetCountAbove(float threshold) const
		throw(exc_empty_multiset);
};

template <class T>
StatisticMultiset<T>::StatisticMultiset()
{
	dataset.clear();
	save.change();
}

template <class T>
void StatisticMultiset<T>::AddNum(T num)
{
	dataset.insert(num);
	save.change();
}

template <class T>
T StatisticMultiset<T>::GetMin() const
{
	if (dataset.size() == 0)
		throw exc_empty_multiset();
	else
		return *(dataset.rbegin());
}

template <class T>
T StatisticMultiset<T>::GetMax() const
{
	if (dataset.size() == 0)
		throw exc_empty_multiset();
	else
		return *(dataset.begin());
}

template <class T>
float StatisticMultiset<T>::GetAvg() const
{
	if (dataset.size() == 0)
		throw exc_empty_multiset();
	else
	{
		if (save.changeAfterGetAvg)
		{
			T summ = 0;
			for (auto element : dataset)
				summ += element;
			save.changeAfterGetAvg = false;
			save.lastGetAvg = summ / dataset.size();
		}
		return save.lastGetAvg;
	}
}

template <class T>
int StatisticMultiset<T>::GetCountUnder(float threshold) const
{
	if (dataset.size() == 0)
		throw exc_empty_multiset();
	else
	{
		if (save.changeAfterGetCountUnder)
		{
			save.lastGetCountUnder = 0;
			for (auto element : dataset)
				if (element < threshold)
					save.lastGetCountUnder += 1;
			save.changeAfterGetCountUnder = false;
		}
		return save.lastGetCountUnder;
	}
}

template <class T>
int StatisticMultiset<T>::GetCountAbove(float threshold) const
{
	if (dataset.size() == 0)
		throw exc_empty_multiset();
	else
	{
		if (save.changeAfterGetCountUnder)
		{
			save.lastGetCountAbove = 0;
			for (auto element : dataset)
				if (element > threshold)
					save.lastGetCountAbove += 1;
			save.changeAfterGetCountAbove = false;
		}
		return save.lastGetCountAbove;
	}
}

template <class T>
void StatisticMultiset<T>::AddNum(const std::vector<T>& numbers)
{
	for (unsigned int i = 0; i < numbers.size(); i++)
		AddNum(numbers[i]);
}

template <class T>
void StatisticMultiset<T>::AddNum(const std::list<T>& numbers)
{
	list <int> copy = numbers;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		AddNum(copy.back());
		copy.pop_back();
	}
}

template <class T>
void StatisticMultiset<T>::AddNum(const std::multiset<T>& numbers)
{
	for (const auto &number : numbers)
		AddNum(number);
}

template <class T>
void StatisticMultiset<T>::AddNum(const string& filename)
{
	ifstream fin;
	T in;
	fin.open(filename);
	if (!fin.is_open())
		throw exc_io();
	while (!fin.eof())
	{
		fin >> in;
		AddNum(in);
	}
}

template <class T>
void StatisticMultiset<T>::AddNum(const StatisticMultiset& a_stat_set)
{
	AddNum(a_stat_set.dataset);
}