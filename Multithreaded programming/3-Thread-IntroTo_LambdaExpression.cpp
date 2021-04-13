#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void Even(int a)
{
	if (a % 2 == 0)
	{
		cout << "EVEN: " << a << endl;
	}
}

void Odd(int a)
{
	if (a % 2 != 0)
	{
		cout << "ODD: " << a << endl;
	}
}

void implement(std::vector<int> v, std::vector<std::function<void(int)>> f)
{
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		for (std::vector<std::function<void(int)>>::iterator j = f.begin(); j != f.end(); ++j)
		{
			(*j)(*i);
		}
	}
}

int main()
{
	std::vector<int> v{ 2,6,5,9,47,5,8,65,22,29 };

	std::vector<std::function<void(int)>> f;

	std::function<void(int)> fun;
	std::function<void(int)> fun1;
	std::function<void(int)> fun2;
	fun = [](int i)
	{
		cout << i << endl;
	};
	fun1 = Even;
	fun2 = Odd;

	f.emplace_back(fun);
	f.emplace_back(fun1);
	f.emplace_back(fun2);

	implement(v, f);



	return 0;
}