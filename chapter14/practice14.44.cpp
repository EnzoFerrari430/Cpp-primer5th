#include <iostream>
#include <functional>
#include <map>
#include <string>

using namespace std;
using namespace std::placeholders;
int add(int i, int j) { return i + j; }
class Myminus
{
public:
	int operator()(int i, int j)
	{
		return i - j;
	}
};
int(*multiple)(int, int) = [](int i, int j) {return i * j; };
int main()
{
	map<string, function<int(int,int)>> binops;
	binops.insert({ "+",add });
	binops.insert({ "-",Myminus() });
	binops.insert({ "*",multiple });
	binops.insert({ "/",[](int i,int j) {return i / j; } });
	int a, b;
	char c;
	cin >> a >> c >> b;
	switch (c)
	{
	case '+':
		cout << binops["+"](a, b) << endl;
		break;
	case '-':
		cout << binops["-"](a, b) << endl;
		break;
	case '*':
		cout << binops["*"](a, b) << endl;
		break;
	case '/':
		cout << binops["/"](a, b) << endl;
		break;
	default:
		break;
	}
	return 0;
}
