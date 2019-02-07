#pragma once
#include <iostream>
/*
未命名的空间是指关键字namespace后紧跟花括号起来的一系列声明

未命名的命名空间中定义的变量拥有生命周期:它们在第一次使用前创建，并且直到程序结束才销毁

一个未命名的命名空间可以在某个给定的文件内连续，但是不能跨越多个文件
	估计的原因:未命名的命名空间不能按照名字将多个文件中的未命名的命名空间区分出来

如果两个文件都含有未命名的命名空间，则这两个空间互相无关。
在这两个未命名的命名空间可以定义相同的名字，并且这些定义表示的不同的实体
*/

//int i;  //i的全局声明
namespace space1
{
	namespace
	{
		//int i;
		void swap(int *a,int *b);

		void swapprint(int n1, int n2);
	}
}

//i = 10;