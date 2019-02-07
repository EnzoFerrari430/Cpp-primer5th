#include "Sales_data.h"
#include <Windows.h>
#include "specialtemplate.h"
#include "InlineNamespace.h"
#include "unnamedspace.h"

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	using namespace PJD;
	using namespace std;
	A a;
	B b;

	inspace::Query_base q1;

	inspace::FourthEd::Item_base i1;
	inspace::FourthEd::Query_base q2;

	int n1 = 1;
	int n2 = 2;
	swap(&n1, &n2);
	cout << n1 << " " << n2 << endl;

	//space1::swap(&n1, &n2);  未命名的命名空间不能跨文件
	cout << n1 << " " << n2 << endl;

	//swapprint(1, 2);

	system("pause");
	return 0;
}