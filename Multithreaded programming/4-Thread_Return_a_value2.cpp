#include <iostream>
#include <thread>
#include <functional>
#include <chrono>
using namespace std;

int getSum(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(5000));
	return a + b;
}


int main()
{
	int result = 0;

	/*
		////// method 1 ///////

		std::function<void()> f;
		f = [&result]()
		{
			result = getSum(5,6);
		}
		thread t(f);
	*/

	/*
		////// method 2 ///////

		auto f = [&result]()
		{
			result = getSum(5,6);
		}
		thread t(f);
	*/

		////// method 2 /////// recomended
		thread t([&result](){result = getSum(5,6);});

	

	for (int i = 0; i < 10; ++i)
	{
		cout << "thread id: " << this_thread::get_id() << "\tmain working" << "\t#" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}


	t.join();
	cout << result << endl;
	return 0;
}