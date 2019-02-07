#include "Blob.h"
#include "BlobPtr.h"
#include <Windows.h>
using namespace std;
int main()
{
	//使用类模板时，我们必须提供额外信息。
	//这些额外信息是显示模板实参列表，它们被绑定到模板参数。
	//编译器使用这些模板实参来实例化出特定的类
	Blob<int> ia;  //空Blob<int>
	Blob<int> ia2 = { 0,1,2,3,4 };  //有5个元素的Blob<int>
									//当编译器从我们的Blob模板实例化出一个类时，它会重写Blob模板，将模板参数T的每个实例替换为给定的模板实参，在本例中是int


									//对我们指定的每一种元素类型，编译器都生成一个不同的类
	Blob<string> names;     //保存string的Blob
	Blob<double> prices;    //不同的元素类型

							//默认情况下，一个类模板的成员函数只有当程序用到它时才进行实例化
							//实例化Blob<int>和接受initializer_list<int>的构造函数
	Blob<int> squares = { 0,1,2,3,4,5,6,7,8,9 };
	//实例化Blob<int>::size()const
	for (size_t i = 0; i != squares.size(); ++i)
	{
		squares[i] = i*i;  //实例化Blob<int>::operator[](size_t)
	}

	Blob<int> v1 = { 1,2,3 };
	Blob<int> v2 = { 1,2,3 };
	cout << (v1 == v2) << endl;
	cout << (v1 < v2) << endl;

	BlobPtr<int> it = v1.begin(),ib;
	for (; it != v1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	it = v1.begin();
	for (; it < v1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	it = v1.begin();
	ib = ++it;
	it = v1.begin();
	Blob<char> vc = { 'h','e' };
	BlobPtr<char> ic = vc.begin();
	//cout << (it < ic) << endl;  it和ic的实例化对象类型不一致，不能比较
	cout << (it < ib) << endl;

	vector<int> v24 = { 1,2,3,4,5,6 };
	Blob<int> b24(v24.begin(), v24.end());
	it = b24.begin();
	for (; it < b24.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0; 
}