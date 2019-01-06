#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>
#include "factor.h"

using namespace std;

int THREAD_COUNT;

uint64_t new_value;

mutex out;
mutex logging;
mutex update;
mutex new_val;

condition_variable cv_thread;
condition_variable cv_update;
condition_variable cv_free_thread;

atomic_bool for_update;
atomic_bool for_new_val;
atomic_bool finish;

void sendToThread(uint64_t x)
{
	logging.lock();
	cout << "Send To Thread" << endl;
	logging.unlock();

	unique_lock<mutex> pause_1(update);
	while (!for_update)
		cv_update.wait(pause_1);

	new_value = x;
	for_update = false;

	cv_thread.notify_one();
}

bool isAvaliableAnyThread(vector<atomic_bool>& working)
{
	bool ans = true;
	for (int i = 0; i < THREAD_COUNT; i++)
	{
		ans = ans && working[i];
	}
	return !ans;
}

int main()
{

	cout << "Input count of threads: " << endl;
	cin >> THREAD_COUNT;

	vector<atomic_bool> working(THREAD_COUNT);
	vector<thread> tp(THREAD_COUNT);

	finish = false;
	for_update = true;
	string in_file, out_file;

	in_file = "input.txt";
	out_file = "output.txt";

	ifstream fin(in_file);
	ofstream fout(out_file);

	for (int i = 0; i < THREAD_COUNT; i++)
	{
		working[i] = false;
	}

	vector<factor> fact(THREAD_COUNT);

	for (int i = 0; i < THREAD_COUNT; i++)
	{
		tp[i] = thread([&, i]()
		{
			int num = i;
			mutex mutex_thread;
			uint64_t input;
			while (!finish)
			{
				unique_lock<mutex> pause_2(mutex_thread);
				cv_thread.wait(pause_2);

				if (finish)
					break;

				working[num] = true;
				input = new_value;
				for_update = true;
				cv_update.notify_one();

				logging.lock();
				cout << "Start:  " << num << endl;
				logging.unlock();

				fact[num].createFactor(input);

				out.lock();
				fout << fact[num].getString() << endl;
				out.unlock();

				logging.lock();
				cout << "Finish: " << num << endl;
				logging.unlock();

				working[num] = false;
				cv_free_thread.notify_one();
			}
		});
	}

	uint64_t in;
	while (!fin.eof())
	{
		fin >> in;

		unique_lock<mutex> pause_3(new_val);
		while (!isAvaliableAnyThread(working))
			cv_free_thread.wait(pause_3);

		sendToThread(in);
	}

	cv_thread.notify_all();
	finish = true;

	for (int i = 0; i < THREAD_COUNT; i++)
	{
		if (tp[i].joinable())
			tp[i].join();
	}

	fin.close();
	fout.close();

	return 0;
}