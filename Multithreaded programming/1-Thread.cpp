#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void DoWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "Thread id: " << this_thread::get_id() << "\t# " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}


int main()
{
	thread th1(DoWork);

	for (size_t i = 0; i < 10; i++)
	{
		cout << "Thread id: " << this_thread::get_id() << "\t# " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	

	th1.join();
	return 0;
}