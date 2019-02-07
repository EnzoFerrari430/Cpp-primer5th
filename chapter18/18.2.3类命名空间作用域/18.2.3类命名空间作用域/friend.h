#pragma once
#include <iostream>
/*
当类声明一个友元时，该友元的声明并没有使得友元本身可见。

然而，一个另外的未声明的类或函数如果第一次出现在友元声明中，则我们认为它是最接近的外层命名空间的成员

*/

namespace FRIEND
{
	class C
	{
		friend void f2();			//除非另有声明，否则不会被找到
		friend void f(const C&);	//根据实参相关的查找规则可以被找到
	};
}