#include <iostream>
#include <Windows.h>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include "debugdelete.h"
#include "Blob.h"
using namespace std;
int main()
{
	double *p = new double;
	DebugDelete d;
	d(p);  //调用Debug::operator()(double *),释放p
	int *ip = new int;
	//在一个临时DebugDelete对象上调用operator()(int*)
	DebugDelete()(ip);

	//我们也可以用DebugDelete用作unique_ptr的删除器。
	//为了重载unique_ptr的删除器，我们要在尖括号内给出删除器的类型
	//并提供一个这种类型的对象给unique_ptr的构造函数

	//销毁up指向的对象
	//实例化DebugDelete::operator()<int>(int*)
	//类型为DebugDelete的可调用对象来释放它的指针
	unique_ptr<int, DebugDelete> up(new int, DebugDelete());//在up的构造函数中提供了该类型的一个未命名对象

	//销毁usp指向的对象
	//实例化DebugDelete::operator()<string>(string*)
	//类型为DebugDelete的可调用对象来释放它的指针
	unique_ptr<string, DebugDelete>usp(new string, DebugDelete());

	//实例化一个类模板的成员模板。我们必须提供类和函数模板的实参。
	//编译器根据该给定对象的类型来推断类模板参数的实参
	//编译器通常根据传递给成员模板的函数实参来推断它的模板实参
	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<long> vi = { 0,1,2,3,4,5,6,7,8,9 };
	list<const char*> w = { "now","is","the","time" };
	//实例化Blob<int>类以及接受两个int*参数的构造函数
	Blob<int> a1(begin(ia), end(ia));
	cout << typeid(a1).name() << endl;
	//实例化Blob<int>类接受2个vector<long>::iterator的构造函数
	Blob<int> a2(vi.begin(), vi.end());
	cout << typeid(a2).name() << endl;
	//实例化Blob<string>类以及接受两个list<const char*>::iterator参数的构造函数
	Blob<string> a3(w.begin(), w.end());
	cout << typeid(a3).name() << endl;


	system("pause");
	return 0;
}