#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void DoWork(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "______ adding process is started ______" << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << a << " + " << b << " = " << a+b << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "______ process is ended ______" << endl;
}


int main()
{
	thread th1(DoWork, 5 , 254);

	for (size_t i = 0; true; i++)
	{
		cout << "Thread id: " << this_thread::get_id() << "\tmain"<<"\t# " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	

	th1.join();
	
	return 0;
}