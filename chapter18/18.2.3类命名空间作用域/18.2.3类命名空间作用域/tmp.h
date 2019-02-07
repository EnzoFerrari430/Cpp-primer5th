#pragma once
/*
即由内向外依次查找每个外层作用域
外层作用域也可能是一个或者多个嵌套的命名空间，直到最外层的全局命名空间查找过程终止
只有位于开放的块中且在使用点之前声明的名字才被考虑
*/

namespace A
{
	int i;
	namespace B
	{
		int i;
		int j;
		int f1()
		{
			int j;  //这个局部变量隐藏了A::B::j
			return i;  //返回的是B::i
		}
	}  //命名空间B结束，此后B中定义的名字不再可见
	//int f2()
	//{
	//	return j;  //引发错误:  j未定义
	//}
	int j = i;
}


//对于位于命名空间中的类来说，常规的查找规则仍然适用
namespace AC
{
	int i;
	int k;
	class C1
	{
	public:
		C1():i(0),j(0){}
		int f1() { return k; }  //返回AC::k
		//int f2() { return h; }  //错误未定义h
		int f3();
	private:
		int i;  //在C1中隐藏了AC::i
		int j;
	};
	int h = i;  //用AC::i初始化h
}

int AC::C1::f3() { return h; }  //正确  返回AC::h