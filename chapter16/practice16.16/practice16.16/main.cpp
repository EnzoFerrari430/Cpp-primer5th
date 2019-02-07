#include <Windows.h>
#include "Vec.h"
using namespace std;
int main()
{
	Vec<int> vi;
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);

	for (auto it = vi.begin(); it != vi.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	Vec<string> vs;
	vs.push_back("hello");
	vs.push_back("world");
	vs.push_back("born to run");
	for (auto it = vs.begin(); it != vs.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}