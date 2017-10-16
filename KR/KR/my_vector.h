//Evgeny Lositsky 3205

#pragma once

#include <vector>

template<typename T>
void swap(std::vector<T>& v_in)
{
	int len = v_in.size();
	if ((len % 2) == 0)
	{
		for (int i = 0; i < len / 2; i++)
		{
			T t = v_in[i];
			v_in[i] = v_in[i + (len / 2)];
			v_in[i + (len / 2)] = t;
		}
	}
	else
	{
		for (int i = 0; i < len / 2; i++)
		{
			T t = v_in[i];
			v_in[i] = v_in[i + (len / 2) + 1];
			v_in[i + (len / 2) + 1] = t;
		}
	}
}

template<typename T>
void out(std::vector<T>& v_in)
{
	for (unsigned int i = 0; i < v_in.size(); i++)
		cout << v_in[i] << " ";
	cout << endl;
}