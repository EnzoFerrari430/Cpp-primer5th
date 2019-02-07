#include <iostream>
#include <Windows.h>

/*
上一节了解到，对于接受类类型实参的函数来说，其名字查找将在实参类所属的命名空间中进行
这条规则对于我们如何确定候选函数集同样也有影响
我们将在每个实参类(以及实参类的基类)所属的命名空间中搜寻候选函数
*/

namespace NS
{
	class Quote
	{

	};
	void display(const Quote& item)
	{
		std::cout << "function display" << std::endl;
	}

}

class Bulk_item : public NS::Quote
{

};


namespace P1
{
	void print(double d)
	{
		std::cout << "print function in namespace P1 and parameter is double" << std::endl;
	}
}

namespace P2
{
	void print(int a)
	{
		std::cout << "print function in namespace P2 and parameter is int" << std::endl;
	}
}

void print()
{
	std::cout << "print function in global" << std::endl;
}
using namespace P1;
using namespace P2;

int main()
{
	Bulk_item book1;
	display(book1);

	//对于using指示来说，引入一个与已有函数形参列表完全相同的函数并不会产生错误。
	//此时，只要我们指明调用的是命名空间中的函数版本还是当前作用域中的版本即可
	print();
	print(3.14);
	print(3);

	system("pause");
	return 0;
}