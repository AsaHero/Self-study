#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void DoWork(int& a)
{
	this_thread::sleep_for(chrono::milliseconds(3000));
	a *= 2;
}


int main()
{
	int a = 5;
	thread th1(DoWork, std::ref(a));


	for (size_t i = 0; i < 7; i++)
	{
		cout << "Thread id: " << this_thread::get_id() << "\t# " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th1.join();
	cout << a << endl;
	return 0;
}