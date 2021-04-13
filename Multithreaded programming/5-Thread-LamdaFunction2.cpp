#include <iostream>
using namespace std;

int main()
{
	int a = 5,b = 25;

/*	auto f = [&]()
	{
		a = a + b;
		b = a - b;
		a = a - b;

	};
	f();
*/
/*	auto f = [=]()mutable
	{
		a = a + b;
		b = a - b;
		a = a - b;

	};
	f();
*/
	auto f = [&a,b]()mutable
	{
		a = a + b;
		b = a - b;
		a = a - b;
	};
	f();
	auto fu = [a,b]()
	{
		cout << a << endl << b << endl;
	};
	fu();
	return 0;
}